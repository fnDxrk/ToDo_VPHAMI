#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Скрываем меню с иконками
    showFullMenu();

    // Делаем по умолчанию страницу Today в меню
    ui->stackedWidget->setCurrentIndex(0);
    ui->full_menu_today_button->setChecked(true);

    // Скрываем кнопку календаря
    ui->calendar_button->setVisible(0);

    // Подключение сигналов и слотов для переключения меню
    connect(ui->icon_menu_toggle_button, &QPushButton::clicked, this, &MainWindow::showFullMenu);
    connect(ui->full_menu_toggle_button, &QPushButton::clicked, this, &MainWindow::showIconMenu);

    // Подключаем сигналы кнопок к слоту переключения страниц
    connect(ui->icon_menu_today_button, &QPushButton::clicked, this, &MainWindow::showTodayPage);
    connect(ui->full_menu_today_button, &QPushButton::clicked, this, &MainWindow::showTodayPage);

    connect(ui->icon_menu_plans_button, &QPushButton::clicked, this, &MainWindow::showPlansPage);
    connect(ui->full_menu_plans_button, &QPushButton::clicked, this, &MainWindow::showPlansPage);

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
    ui->calendar_button->setVisible(0);
    ui->title_text->setContentsMargins(0,0,0,0);
}

// Слот для переключения на страницу "Plans"
void MainWindow::showPlansPage() {
    ui->stackedWidget->setCurrentWidget(ui->plans_page);
    ui->calendar_button->setVisible(1);
    ui->title_text->setContentsMargins(52,0,0,0);
}

// Слот для переключения на страницу "Tasks"
void MainWindow::showTasksPage() {
    ui->stackedWidget->setCurrentWidget(ui->tasks_page);
    ui->calendar_button->setVisible(0);
    ui->title_text->setContentsMargins(0,0,0,0);
}
