#ifndef DELETEWINDOW_H
#define DELETEWINDOW_H

#include <QDialog>

namespace Ui {
class deletewindow;
}

class deletewindow : public QDialog
{
    Q_OBJECT

public:
    explicit deletewindow(QWidget *parent = nullptr);
    ~deletewindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::deletewindow *ui;
};

#endif // DELETEWINDOW_H
