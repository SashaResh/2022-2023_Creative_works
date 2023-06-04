/********************************************************************************
** Form generated from reading UI file 'creatingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATINGWINDOW_H
#define UI_CREATINGWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreatingWindow
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QDateEdit *dateEdit_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *lineEdit_5;

    void setupUi(QDialog *CreatingWindow)
    {
        if (CreatingWindow->objectName().isEmpty())
            CreatingWindow->setObjectName(QString::fromUtf8("CreatingWindow"));
        CreatingWindow->resize(480, 242);
        CreatingWindow->setMinimumSize(QSize(450, 242));
        CreatingWindow->setMaximumSize(QSize(500, 242));
        pushButton = new QPushButton(CreatingWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(380, 210, 93, 28));
        pushButton_2 = new QPushButton(CreatingWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 210, 93, 28));
        layoutWidget = new QWidget(CreatingWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 421, 171));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(layoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        dateEdit = new QDateEdit(layoutWidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setDateTime(QDateTime(QDate(2023, 1, 1), QTime(0, 0, 0)));
        dateEdit->setDisplayFormat(QString::fromUtf8("dd.MM.yyyy"));
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate(2023, 1, 1));

        horizontalLayout_2->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        dateEdit_2 = new QDateEdit(layoutWidget);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setDateTime(QDateTime(QDate(2023, 1, 1), QTime(0, 0, 0)));
        dateEdit_2->setCalendarPopup(true);

        horizontalLayout_3->addWidget(dateEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_4->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_5->addWidget(label_6);

        lineEdit_5 = new QLineEdit(layoutWidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_5->addWidget(lineEdit_5);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(CreatingWindow);

        QMetaObject::connectSlotsByName(CreatingWindow);
    } // setupUi

    void retranslateUi(QDialog *CreatingWindow)
    {
        CreatingWindow->setWindowTitle(QApplication::translate("CreatingWindow", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("CreatingWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        pushButton_2->setText(QApplication::translate("CreatingWindow", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_3->setText(QApplication::translate("CreatingWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265         ", nullptr));
        label->setText(QApplication::translate("CreatingWindow", "\320\224\320\260\321\202\320\260 \320\277\320\276\321\201\320\260\320\264\320\272\320\270", nullptr));
        label_4->setText(QApplication::translate("CreatingWindow", "\320\224\320\260\321\202\320\260 \321\201\320\261\320\276\321\200\320\260:", nullptr));
        label_5->setText(QApplication::translate("CreatingWindow", "\320\232\320\260\320\272 \321\207\320\260\321\201\321\202\320\276 \320\277\320\276\320\273\320\270\320\262\320\260\321\202\321\214?        (\320\262 \320\264\320\275\321\217\321\205)", nullptr));
        label_6->setText(QApplication::translate("CreatingWindow", "\320\232\320\260\320\272 \321\207\320\260\321\201\321\202\320\276 \320\276\320\261\321\200\320\260\320\261\320\260\321\202\321\213\320\262\320\260\321\202\321\214? (\320\262 \320\264\320\275\321\217\321\205)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreatingWindow: public Ui_CreatingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATINGWINDOW_H
