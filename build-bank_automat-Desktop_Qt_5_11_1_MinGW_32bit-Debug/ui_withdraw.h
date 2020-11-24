/********************************************************************************
** Form generated from reading UI file 'withdraw.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WITHDRAW_H
#define UI_WITHDRAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_withdraw
{
public:
    QLabel *label;

    void setupUi(QWidget *withdraw)
    {
        if (withdraw->objectName().isEmpty())
            withdraw->setObjectName(QStringLiteral("withdraw"));
        withdraw->resize(770, 582);
        label = new QLabel(withdraw);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 100, 211, 121));

        retranslateUi(withdraw);

        QMetaObject::connectSlotsByName(withdraw);
    } // setupUi

    void retranslateUi(QWidget *withdraw)
    {
        withdraw->setWindowTitle(QApplication::translate("withdraw", "Form", nullptr));
        label->setText(QApplication::translate("withdraw", "withdraw", nullptr));
    } // retranslateUi

};

namespace Ui {
    class withdraw: public Ui_withdraw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WITHDRAW_H
