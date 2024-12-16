#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupUI();

    calendarManager = new CalendarManager(this);

    connectSignalsAndSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI() {
    showFullMenu();
    ui->stackedWidget->setCurrentIndex(0);
    ui->full_menu_today_button->setChecked(true);
    ui->calendar_button->setVisible(false);
}

void MainWindow::connectSignalsAndSlots() {
    connect(ui->calendar_button, &QPushButton::clicked, calendarManager, &CalendarManager::toggleCalendarVisibility);
    connect(ui->icon_menu_toggle_button, &QPushButton::clicked, this, &MainWindow::showFullMenu);
    connect(ui->full_menu_toggle_button, &QPushButton::clicked, this, &MainWindow::showIconMenu);
    connect(ui->icon_menu_today_button, &QPushButton::clicked, this, &MainWindow::showTodayPage);
    connect(ui->full_menu_today_button, &QPushButton::clicked, this, &MainWindow::showTodayPage);
    connect(ui->icon_menu_plans_button, &QPushButton::clicked, this, &MainWindow::showPlansPage);
    connect(ui->full_menu_plans_button, &QPushButton::clicked, this, &MainWindow::showPlansPage);
    connect(ui->icon_menu_tasks_button, &QPushButton::clicked, this, &MainWindow::showTasksPage);
    connect(ui->full_menu_tasks_button, &QPushButton::clicked, this, &MainWindow::showTasksPage);
}


void MainWindow::resizeEvent(QResizeEvent *event) {
    calendarManager->updateCalendarPosition();
    QMainWindow::resizeEvent(event);
}

void MainWindow::showFullMenu() {
    ui->full_menu_widget->setVisible(true);
    ui->icon_menu_widget->setVisible(false);
}

void MainWindow::showIconMenu() {
    ui->full_menu_widget->setVisible(false);
    ui->icon_menu_widget->setVisible(true);
}

void MainWindow::showTodayPage() {
    ui->stackedWidget->setCurrentWidget(ui->today_page);
    ui->calendar_button->setVisible(false);
    ui->title_text->setContentsMargins(0, 0, 0, 0);
}

void MainWindow::showPlansPage() {
    ui->stackedWidget->setCurrentWidget(ui->plans_page);
    ui->calendar_button->setVisible(true);
    ui->title_text->setContentsMargins(52, 0, 0, 0);
}

void MainWindow::showTasksPage() {
    ui->stackedWidget->setCurrentWidget(ui->tasks_page);
    ui->calendar_button->setVisible(false);
    ui->title_text->setContentsMargins(0, 0, 0, 0);
}
