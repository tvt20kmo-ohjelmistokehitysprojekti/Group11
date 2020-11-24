/********************************************************************************
** Form generated from reading UI file 'action.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTION_H
#define UI_ACTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_action
{
public:
    QLabel *label;

    void setupUi(QWidget *action)
    {
        if (action->objectName().isEmpty())
            action->setObjectName(QStringLiteral("action"));
        action->resize(770, 582);
        label = new QLabel(action);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(290, 160, 181, 181));

        retranslateUi(action);

        QMetaObject::connectSlotsByName(action);
    } // setupUi

    void retranslateUi(QWidget *action)
    {
        action->setWindowTitle(QApplication::translate("action", "Form", nullptr));
        label->setText(QApplication::translate("action", "action", nullptr));
    } // retranslateUi

};

namespace Ui {
    class action: public Ui_action {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTION_H
