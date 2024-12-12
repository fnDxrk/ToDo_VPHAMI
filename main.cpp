#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Подключение файла стилей
    QFile styleFile(":/resource/style.css");
    styleFile.open(QFile::ReadOnly);
    a.setStyleSheet(styleFile.readAll());

    MainWindow w;
    w.show();
    return a.exec();
}
