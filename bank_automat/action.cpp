#include "action.h"
#include "menu.h"
#include "mysingleton.h"
#include "ui_action.h"
#include <QNetworkAccessManager>
#include <QtNetwork>
#include <QJsonDocument>
#include <qjsondocument.h>
#include <QJsonValue>

action::action(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::action)
{
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);
    ui->setupUi(this);
}

action::~action()
{
    delete ui;
}

void action::on_btnShowAction_clicked()
{
    MySingleton *my = MySingleton::getInstance();
    QString idCard = my->getCardID();

    QNetworkRequest request(QUrl("http://www.students.oamk.fi/~t9satu01/Group11/Api/RestApi-master/index.php/api/action/action/id/"+idCard));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QString username = "admin";
        QString password = "1234";
        QString concatenatedCredentials = username + ":" + password;
            QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
            QString headerData = "Basic " + data;
            request.setRawHeader("Authorization", headerData.toLocal8Bit());
        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.get(request);
        while(!reply->isFinished()) {
            qApp->processEvents();
        }
        QByteArray response_data = reply->readAll();

        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject jsobj = json_doc.object();
        QJsonArray jsarr = json_doc.array();

        QString action;
        foreach(const QJsonValue &value, jsarr) {
            QJsonObject jsob = value.toObject();
            action+="         "+jsob["action"].toString()+"                           "+jsob["action_time"].toString()+"                         "+jsob["amount"].toString()+" €\r";
            ui->textEditAction->setText(action);
        }
        reply->deleteLater();
}

void action::on_btnBack_clicked()
{
    this->close();
    menu *men = new menu();
    men->show();
}

void action::on_btnClose_clicked()
{
    this->close();
}
