#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Скрываем меню с иконками
    showFullMenu();

    // Подключение сигналов и слотов для переключения меню
    connect(ui->icon_menu_toggle_button, &QPushButton::clicked, this, &MainWindow::showFullMenu);
    connect(ui->full_menu_toggle_button, &QPushButton::clicked, this, &MainWindow::showIconMenu);

    // Подключаем сигналы кнопок к слоту переключения страниц
    connect(ui->icon_menu_today_button, &QPushButton::clicked, this, &MainWindow::showTodayPage);
    connect(ui->full_menu_today_button, &QPushButton::clicked, this, &MainWindow::showTodayPage);

    connect(ui->icon_menu_calendar_button, &QPushButton::clicked, this, &MainWindow::showCalendarPage);
    connect(ui->full_menu_calendar_button, &QPushButton::clicked, this, &MainWindow::showCalendarPage);

    connect(ui->icon_menu_tasks_button, &QPushButton::clicked, this, &MainWindow::showTasksPage);
    connect(ui->full_menu_tasks_button, &QPushButton::clicked, this, &MainWindow::showTasksPage);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Слот для отображения полного меню
void MainWindow::showFullMenu() {
    ui->full_menu_widget->show();
    ui->icon_menu_widget->hide();
}

// Слот для отображения меню с иконками
void MainWindow::showIconMenu() {
    ui->full_menu_widget->hide();
    ui->icon_menu_widget->show();
}

// Слот для переключения на страницу "Today"
void MainWindow::showTodayPage() {
    ui->stackedWidget->setCurrentWidget(ui->today_page);
}

// Слот для переключения на страницу "Calendar"
void MainWindow::showCalendarPage() {
    ui->stackedWidget->setCurrentWidget(ui->calendar_page);
}

// Слот для переключения на страницу "Tasks"
void MainWindow::showTasksPage() {
    ui->stackedWidget->setCurrentWidget(ui->tasks_page);
}
