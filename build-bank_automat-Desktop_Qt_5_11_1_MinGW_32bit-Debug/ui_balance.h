/********************************************************************************
** Form generated from reading UI file 'balance.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALANCE_H
#define UI_BALANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_balance
{
public:
    QLabel *label;

    void setupUi(QWidget *balance)
    {
        if (balance->objectName().isEmpty())
            balance->setObjectName(QStringLiteral("balance"));
        balance->resize(770, 582);
        label = new QLabel(balance);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 100, 201, 181));

        retranslateUi(balance);

        QMetaObject::connectSlotsByName(balance);
    } // setupUi

    void retranslateUi(QWidget *balance)
    {
        balance->setWindowTitle(QApplication::translate("balance", "Form", nullptr));
        label->setText(QApplication::translate("balance", "Balance", nullptr));
    } // retranslateUi

};

namespace Ui {
    class balance: public Ui_balance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALANCE_H
