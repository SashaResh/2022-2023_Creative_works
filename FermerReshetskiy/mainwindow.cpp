#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "deletewindow.h"
#include "infowindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>
#include <QVector>
#include <QString>
#include <QDateTime>

const QDate curdate = QDate::currentDate();
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(curdate);
    Check_tasks(curdate);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_plantObject_clicked()
{
    CreatingWindow window;
    window.setModal(true);
    window.exec();
    Check_tasks(ui->dateEdit->date());
}
void MainWindow::Check_tasks(QDate newData)
{
    QFile file(QApplication::applicationDirPath()+"/data");
    if ((file.exists())&&(file.open(QIODevice::ReadOnly)))
    {
        QString informationPoliv = "Необходимо полить:\n", informationObrabotka = "Необходимо обработать:\n", informationSbor = "Необходимо собрать:\n";
        QDate date_was_plant, date_ready;
        QString name, buff1, buff2, dayy1, mounthh1, yearr1, dayy2, mounthh2, yearr2;
        int poliv, obrabotka;

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

            const QDate dateTime = newData;
            QDate buff(date_was_plant);
            if(dateTime == date_ready)
            {
                informationSbor += "\t" + name;
            }
            else
            {
                buff = buff.addDays(poliv);
                while(buff<date_ready)
                {
                    if (poliv <= 0) {break;}
                    if(buff>dateTime)
                    {
                        break;
                    }
                    if(dateTime == buff)
                    {
                        informationPoliv += "\t" + name;
                        break;
                    }
                    buff = buff.addDays(poliv);
                }
                buff.setDate(yearr1.toInt(), mounthh1.toInt(), dayy1.toInt());
                buff = buff.addDays(obrabotka);
                while(buff<date_ready)
                {
                    if (obrabotka<=0) {break;}
                    if(buff>dateTime)
                    {
                        break;
                    }
                    if(dateTime == buff)
                    {
                        informationObrabotka += "\t" + name;
                        break;
                    }
                    buff = buff.addDays(obrabotka);
                }
            }
        }
        file.close();
        ui->label->setText(informationSbor + informationObrabotka + informationPoliv);
    }
}


void MainWindow::on_plantObject_2_clicked()
{
    deletewindow delw;
    delw.setModal(true);
    delw.exec();
    Check_tasks(ui->dateEdit->date());
}


void MainWindow::on_pushButton_3_clicked()
{
    Check_tasks(QDate::currentDate());
    ui->dateEdit->setDate(curdate);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->dateEdit->setDate(ui->dateEdit->date().addDays(-1));
    Check_tasks(ui->dateEdit->date());
}


void MainWindow::on_pushButton_5_clicked()
{
    ui->dateEdit->setDate(ui->dateEdit->date().addDays(1));
    Check_tasks(ui->dateEdit->date());
}


void MainWindow::on_dateEdit_dateChanged(const QDate &date)
{
    Check_tasks(date);
}


void MainWindow::on_pushButton_clicked()
{
    infowindow infw;
    infw.setModal(true);
    infw.exec();
}

