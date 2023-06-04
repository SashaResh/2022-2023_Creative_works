#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "creatingwindow.h"
#include "plants.h"
#include <QVector>
#include <QDate>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{

    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void Check_tasks(QDate newData);
private slots:
    void on_plantObject_clicked();
    void on_plantObject_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_dateEdit_dateChanged(const QDate &date);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
