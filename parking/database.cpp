#include "database.h"
#include<QCoreApplication>
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>

database::database(){
    this -> db = QSqlDatabase::addDatabase("QKINGBASE");
    qDebug()<<"The driver should be put in this path:"<<QCoreApplication::libraryPaths();
    qDebug()<<"Available drivers:"<<QSqlDatabase::drivers();
    this -> db.setHostName("127.0.0.1");
    this -> db.setDatabaseName("glxt");
    this -> db.setUserName("system");
    this -> db.setPassword("kingbase");
    this -> db.setPort(54321); //设置数据库的端口号
    bool conn = this -> db.open();
    if (!conn) {
        QMessageBox msgBox;
        msgBox.setText("无法连接数据库,请检查数据库是否启动,数据库服务器地址是否正确!");
        msgBox.exec();
    }
}

database::~database(){
    this -> db.close();
}

