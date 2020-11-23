#include "withdraw.h"
#include "ui_withdraw.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "mainwindow.h"
#include "menu.h"
#include "mysingleton.h"

withdraw::withdraw(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::withdraw)
{
    setWindowFlags(Qt::WindowTitleHint | Qt::WindowMinimizeButtonHint);
    ui->setupUi(this);
}

withdraw::~withdraw()
{
    delete ui;
}

void withdraw::on_btnWithdraw20_clicked()
{
    MySingleton *my = MySingleton::getInstance();
    QString idCard = my->getCardID();
    double amount = 20;

    QNetworkRequest request (QUrl("http://www.students.oamk.fi/~t9satu01/Group11/Api/RestApi-master/index.php/api/account/withdraw"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QString username = "admin";
        QString password = "1234";
        QString concatenatedCredentials = username + ":" + password;
            QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
            QString headerData = "Basic " + data;
            request.setRawHeader("Authorization", headerData.toLocal8Bit() );

        QJsonObject json;
        json.insert("idkortti",idCard);
        json.insert("amount", amount);
        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
        while(!reply->isFinished()) {
            qApp->processEvents();
        }
        QString response_data = reply->readAll();
        qDebug() << response_data;
        reply->deleteLater();

        if(response_data == '1') {
            ui->labelInfo->setText("Tililtä nostettu 20 €.");
        }
        else {
            ui->labelInfo->setText("Tilillä ei ole tarpeeksi katetta.");
        }
}

void withdraw::on_btnWithdraw40_clicked()
{
    MySingleton *my = MySingleton::getInstance();
    QString idCard = my->getCardID();
    double amount = 40;

    QNetworkRequest request (QUrl("http://www.students.oamk.fi/~t9satu01/Group11/Api/RestApi-master/index.php/api/account/withdraw"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QString username = "admin";
        QString password = "1234";
        QString concatenatedCredentials = username + ":" + password;
            QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
            QString headerData = "Basic " + data;
            request.setRawHeader("Authorization", headerData.toLocal8Bit() );

        QJsonObject json;
        json.insert("idkortti",idCard);
        json.insert("amount", amount);
        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
        while(!reply->isFinished()) {
            qApp->processEvents();
        }
        QString response_data = reply->readAll();
        qDebug() << response_data;
        reply->deleteLater();

        if(response_data == '1') {
            ui->labelInfo->setText("Tililtä nostettu 40 €.");
        }
        else {
            ui->labelInfo->setText("Tilillä ei ole tarpeeksi katetta.");
        }
}

void withdraw::on_btnWithdraw50_clicked()
{
    MySingleton *my = MySingleton::getInstance();
    QString idCard = my->getCardID();
    double amount = 50;

    QNetworkRequest request (QUrl("http://www.students.oamk.fi/~t9satu01/Group11/Api/RestApi-master/index.php/api/account/withdraw"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QString username = "admin";
        QString password = "1234";
        QString concatenatedCredentials = username + ":" + password;
            QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
            QString headerData = "Basic " + data;
            request.setRawHeader("Authorization", headerData.toLocal8Bit() );

        QJsonObject json;
        json.insert("idkortti",idCard);
        json.insert("amount", amount);
        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
        while(!reply->isFinished()) {
            qApp->processEvents();
        }
        QString response_data = reply->readAll();
        qDebug() << response_data;
        reply->deleteLater();

        if(response_data == '1') {
            ui->labelInfo->setText("Tililtä nostettu 50 €.");
        }
        else {
            ui->labelInfo->setText("Tilillä ei ole tarpeeksi katetta.");
        }
}

void withdraw::on_btnWithdraw100_clicked()
{
    MySingleton *my = MySingleton::getInstance();
    QString idCard = my->getCardID();
    double amount = 100;

    QNetworkRequest request (QUrl("http://www.students.oamk.fi/~t9satu01/Group11/Api/RestApi-master/index.php/api/account/withdraw"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QString username = "admin";
        QString password = "1234";
        QString concatenatedCredentials = username + ":" + password;
            QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
            QString headerData = "Basic " + data;
            request.setRawHeader("Authorization", headerData.toLocal8Bit() );

        QJsonObject json;
        json.insert("idkortti",idCard);
        json.insert("amount", amount);
        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
        while(!reply->isFinished()) {
            qApp->processEvents();
        }
        QString response_data = reply->readAll();
        qDebug() << response_data;
        reply->deleteLater();

        if(response_data == '1') {
            ui->labelInfo->setText("Tililtä nostettu 100 €.");
        }
        else {
            ui->labelInfo->setText("Tilillä ei ole tarpeeksi katetta.");
        }
}

void withdraw::on_btnWithdrawAmount_clicked()
{
    MySingleton *my = MySingleton::getInstance();
    QString idCard = my->getCardID();
    QString amount = ui->lineEditAmount->text();

    QNetworkRequest request (QUrl("http://www.students.oamk.fi/~t9satu01/Group11/Api/RestApi-master/index.php/api/account/withdraw"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QString username = "admin";
        QString password = "1234";
        QString concatenatedCredentials = username + ":" + password;
            QByteArray data = concatenatedCredentials.toLocal8Bit().toBase64();
            QString headerData = "Basic " + data;
            request.setRawHeader("Authorization", headerData.toLocal8Bit() );

        QJsonObject json;
        json.insert("idkortti",idCard);
        json.insert("amount", amount);
        QNetworkAccessManager nam;
        QNetworkReply *reply = nam.post(request, QJsonDocument(json).toJson());
        while(!reply->isFinished()) {
            qApp->processEvents();
        }
        QString response_data = reply->readAll();
        qDebug() << response_data;
        reply->deleteLater();

        if(response_data == '1') {
            ui->labelInfo->setText("Tililtä nostettu " +amount+ " €.");
            ui->lineEditAmount->clear();
        }
        else {
            ui->labelInfo->setText("Tilillä ei ole tarpeeksi katetta.");
            ui->lineEditAmount->clear();
        }
}

void withdraw::on_btnClose_clicked()
{
    this->close();
}


void withdraw::on_btnBack_clicked()
{
    this->close();
    menu *men = new menu();
    men->show();
}
