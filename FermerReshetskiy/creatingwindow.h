#ifndef CREATINGWINDOW_H
#define CREATINGWINDOW_H
#include <QDialog>
#include "plants.h"

namespace Ui {
class CreatingWindow;
}
class CreatingWindow : public QDialog
{
    Q_OBJECT
public:
    explicit CreatingWindow(QWidget *parent = nullptr);
    ~CreatingWindow();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
private:
    Ui::CreatingWindow *ui;
};
#endif // CREATINGWINDOW_H
