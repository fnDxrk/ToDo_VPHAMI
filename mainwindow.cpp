#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Скрываем меню с иконками
    showFullMenu();

    // Подключение сигналов и слотов
    connect(ui->icon_menu_toggle_button, &QPushButton::clicked, this, &MainWindow::showFullMenu);
    connect(ui->full_menu_toggle_button, &QPushButton::clicked, this, &MainWindow::showIconMenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::showFullMenu() {
    ui->full_menu_widget->show();
    ui->icon_menu_widget->hide();
}

void MainWindow::showIconMenu() {
    ui->full_menu_widget->hide();
    ui->icon_menu_widget->show();
}
