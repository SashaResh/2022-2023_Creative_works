#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QDialog>

namespace Ui {
class infowindow;
}

class infowindow : public QDialog
{
    Q_OBJECT

public:
    explicit infowindow(QWidget *parent = nullptr);
    ~infowindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::infowindow *ui;
};

#endif // INFOWINDOW_H
