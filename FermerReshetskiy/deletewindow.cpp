#include "deletewindow.h"
#include "ui_deletewindow.h"
#include "plants.h"
#include <QVector>
#include <QFile>
#include <QDebug>

QVector<plants> info;
deletewindow::deletewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletewindow)
{
    ui->setupUi(this);

    QString name, date_was_planted, date_ready, poliv, obrabotka;
    QFile file(QApplication::applicationDirPath()+"/data");
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
            name=file.readLine();
            date_was_planted = file.readLine();
            date_ready= file.readLine();
            poliv = file.readLine();
            obrabotka = file.readLine();
            plants buff(date_was_planted, name, poliv, obrabotka, date_ready);
            info.append(buff);
            ui->comboBox->addItem(buff.get_name());

        }
    }

}

deletewindow::~deletewindow()
{
    delete ui;
}

void deletewindow::on_pushButton_2_clicked()
{
    info.clear();
    close();    
}



void deletewindow::on_pushButton_clicked()
{
    int index = ui->comboBox->currentIndex();
    info.remove(index);
    QFile file(QApplication::applicationDirPath()+"/data");
    QString str = "";
    if (file.open(QIODevice::WriteOnly))
    {
        for(int i = 0; i < info.size(); i++)
        {
            str+=info[i].get_name() + info[i].get_date_when_planted() + info[i].get_grows() + info[i].get_water() + info[i].get_handle();
        }
        file.write(str.toUtf8().data());
        file.close();
    }
    info.clear();
    close();

}

