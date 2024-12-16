#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

bool connectToDatabase()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":database.db");

    if (!db.open()) {
        qDebug() << "Ошибка подключения к базе данных: " << db.lastError().text();
        return false;
    }

    qDebug() << "Подключение к базе данных успешно!";
    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Подключение файла стилей
    QFile styleFile(":/resource/style.css");
    styleFile.open(QFile::ReadOnly);
    a.setStyleSheet(styleFile.readAll());

    connectToDatabase();

    MainWindow w;
    w.show();
    return a.exec();
}
