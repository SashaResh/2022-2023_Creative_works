#include "creatingwindow.h"
#include "ui_creatingwindow.h"
#include <QDateTime>
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

CreatingWindow::CreatingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatingWindow)
{
    ui->setupUi(this);
    //const QString dateTime = QDateTime::currentDateTime().toString("hh:mm dd.MM.yyyy");
    //ui->dataaa->setText(dateTime);
    ui->lineEdit_4->setValidator(new QIntValidator(this));
    ui->lineEdit_5->setValidator(new QIntValidator(this));

}
CreatingWindow::~CreatingWindow()
{
    delete ui;
}
void CreatingWindow::on_pushButton_clicked()
{
    if(ui->lineEdit_2->text()=="" || ui->lineEdit_4->text() == "" || ui->lineEdit_5->text() == "")
    {
        QMessageBox::warning(this, "Посадка растения", "Необходимо заполнить все поля");
    }
    else
    {
        QString str="";
        QFile file(QApplication::applicationDirPath()+"/data");
        if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
        {

            while(!file.atEnd())
            {
                str=str + file.readLine();
            }
            file.close();
        }
        if (file.open(QIODevice::WriteOnly))
        {
            str += ui->lineEdit_2->text() + "\n";
            str += ui->dateEdit->date().toString("dd.MM.yyyy") + "\n";
            str += ui->dateEdit_2->date().toString("dd.MM.yyyy") + "\n";
            str += ui->lineEdit_4->text() + "\n";
            str += ui->lineEdit_5->text() + "\n";

            file.write(str.toUtf8().data());
            file.close();
        }
        close();
     }
}
void CreatingWindow::on_pushButton_2_clicked()
{
    close();
}
