/********************************************************************************
** Form generated from reading UI file 'deletewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETEWINDOW_H
#define UI_DELETEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_deletewindow
{
public:
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *deletewindow)
    {
        if (deletewindow->objectName().isEmpty())
            deletewindow->setObjectName(QString::fromUtf8("deletewindow"));
        deletewindow->resize(400, 300);
        deletewindow->setMinimumSize(QSize(400, 300));
        deletewindow->setMaximumSize(QSize(400, 300));
        comboBox = new QComboBox(deletewindow);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(60, 60, 281, 51));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        comboBox->setFont(font);
        pushButton = new QPushButton(deletewindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 250, 93, 28));
        pushButton_2 = new QPushButton(deletewindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 250, 93, 28));

        retranslateUi(deletewindow);

        QMetaObject::connectSlotsByName(deletewindow);
    } // setupUi

    void retranslateUi(QDialog *deletewindow)
    {
        deletewindow->setWindowTitle(QApplication::translate("deletewindow", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("deletewindow", "\320\236\320\272", nullptr));
        pushButton_2->setText(QApplication::translate("deletewindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deletewindow: public Ui_deletewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETEWINDOW_H
