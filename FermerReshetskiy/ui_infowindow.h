/********************************************************************************
** Form generated from reading UI file 'infowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWINDOW_H
#define UI_INFOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_infowindow
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QDialog *infowindow)
    {
        if (infowindow->objectName().isEmpty())
            infowindow->setObjectName(QString::fromUtf8("infowindow"));
        infowindow->resize(400, 305);
        textBrowser = new QTextBrowser(infowindow);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 401, 261));
        pushButton = new QPushButton(infowindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(300, 270, 93, 28));

        retranslateUi(infowindow);

        QMetaObject::connectSlotsByName(infowindow);
    } // setupUi

    void retranslateUi(QDialog *infowindow)
    {
        infowindow->setWindowTitle(QApplication::translate("infowindow", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("infowindow", "\320\236\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class infowindow: public Ui_infowindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWINDOW_H
