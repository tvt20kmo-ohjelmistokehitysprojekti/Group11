/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QLabel *label;
    QPushButton *btnWithdraw;
    QPushButton *btnBalance;
    QPushButton *btnAction;
    QPushButton *btnClose;

    void setupUi(QWidget *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QStringLiteral("menu"));
        menu->resize(777, 582);
        QFont font;
        font.setPointSize(14);
        menu->setFont(font);
        label = new QLabel(menu);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 80, 141, 81));
        QFont font1;
        font1.setPointSize(18);
        font1.setStrikeOut(false);
        label->setFont(font1);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);
        btnWithdraw = new QPushButton(menu);
        btnWithdraw->setObjectName(QStringLiteral("btnWithdraw"));
        btnWithdraw->setGeometry(QRect(140, 230, 141, 61));
        btnBalance = new QPushButton(menu);
        btnBalance->setObjectName(QStringLiteral("btnBalance"));
        btnBalance->setGeometry(QRect(320, 230, 141, 61));
        btnAction = new QPushButton(menu);
        btnAction->setObjectName(QStringLiteral("btnAction"));
        btnAction->setGeometry(QRect(500, 230, 141, 61));
        btnClose = new QPushButton(menu);
        btnClose->setObjectName(QStringLiteral("btnClose"));
        btnClose->setGeometry(QRect(290, 430, 201, 41));
        btnClose->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"font: 14pt \"MS Shell Dlg 2\";"));

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
        menu->setWindowTitle(QApplication::translate("menu", "Form", nullptr));
        label->setText(QApplication::translate("menu", "Valikko", nullptr));
        btnWithdraw->setText(QApplication::translate("menu", "Nosto", nullptr));
        btnBalance->setText(QApplication::translate("menu", "Saldo", nullptr));
        btnAction->setText(QApplication::translate("menu", "Tapahtumat", nullptr));
        btnClose->setText(QApplication::translate("menu", "Keskeyt\303\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
