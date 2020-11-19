#include "action.h"
#include "ui_action.h"

action::action(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::action)
{
    ui->setupUi(this);
}

action::~action()
{
    delete ui;
}
