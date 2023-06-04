#include "infowindow.h"
#include "ui_infowindow.h"
#include <QFile>
#include <QString>
#include <QDate>

infowindow::infowindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::infowindow)
{
    ui->setupUi(this);

    const QDate curdate = QDate::currentDate();
    QDate date_was_plant, date_ready, temp;
    QString str = "", name, buff1, buff2, dayy1, mounthh1, yearr1, dayy2, mounthh2, yearr2;
    int poliv, obrabotka;
    QFile file(QApplication::applicationDirPath()+"/data");
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        while(!file.atEnd())
        {
            name=file.readLine();
            buff1 = file.readLine();
            buff2 = file.readLine();
            poliv = file.readLine().toInt();
            obrabotka = file.readLine().toInt();
            dayy1 = buff1[0]; dayy1 += buff1[1]; mounthh1 = buff1[3]; mounthh1+= buff1[4]; yearr1=buff1[6];yearr1+=buff1[7]; yearr1+=buff1[8]; yearr1+=buff1[9];
            date_was_plant.setDate(yearr1.toInt(), mounthh1.toInt(), dayy1.toInt());
            dayy2 = buff2[0]; dayy2 += buff2[1]; mounthh2 = buff2[3]; mounthh2+= buff2[4]; yearr2=buff2[6];yearr2+=buff2[7]; yearr2+=buff2[8]; yearr2+=buff2[9];
            date_ready.setDate(yearr2.toInt(), mounthh2.toInt(), dayy2.toInt());

            str+="Название растения: " + name + "\nДата посадки: " + date_was_plant.toString("dd.MM.yyyy") + "\nДата сбора: " + date_ready.toString("dd.MM.yyyy");
            str+= "\nЧастота полива: Раз в " + QString::number(poliv) + " дней\n";
            QDate date_was_plant1(date_was_plant), date_was_plant2(date_was_plant);
            if(date_ready >= curdate)
            {
                while(date_was_plant1 <= curdate)
                {
                    date_was_plant1 = date_was_plant1.addDays(poliv);
                    if(date_was_plant1>curdate)
                    {
                        str += "(Следующий полив: " + date_was_plant1.toString("dd.MM.yyyy") + ")\n";
                    }
                }
            }
            str+= "Частота обработки: Раз в " + QString::number(obrabotka) + " дней\n";
            if(date_ready >= curdate)
            {
                while(date_was_plant2 <= curdate)
                {
                    date_was_plant2 = date_was_plant2.addDays(obrabotka);
                    if(date_was_plant2>curdate)
                    {
                        str += "(Следующая обработка: " + date_was_plant2.toString("dd.MM.yyyy") + ")\n\n\n";
                    }
                }
            }
            else
            {
                str+="\n\n";
            }

        }
        str.remove(-3, 3);
        ui->textBrowser->setText(str);
    }
}

infowindow::~infowindow()
{
    delete ui;
}

void infowindow::on_pushButton_clicked()
{
    close();
}

