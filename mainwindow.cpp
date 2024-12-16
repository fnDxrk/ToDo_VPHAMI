#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "eventwidget.h"

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

    // Создаём календарь
    calendarWidget = new QCalendarWidget(this);
    calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    calendarWidget->setVisible(0);
    calendarWidget->setGeometry(1010, 98, 280, 280);

    // Скрываем поле текста
    // ui->edit_text->setVisible(0);
    // ui->edit_event_widget->hide();

    //
    // connect(ui->plus_button, &QPushButton::clicked, this, &MainWindow::createNewEventWidget);

    // Подключаем сигнал завершения редактирования в поле ввода к слоту обработки завершения редактирования
    // connect(ui->edit_line, &QLineEdit::editingFinished, this, &MainWindow::onEditFinished);

    // Подключаем кнопку календаря к слоту отображения календаря
    connect(ui->calendar_button, &QPushButton::clicked, this, &MainWindow::showCalendar);

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

// Слот для отображения или скрытия календаря
void MainWindow::showCalendar() {
    if (calendarWidget->isVisible()) {
        calendarWidget->setVisible(0);
    } else {
        calendarWidget->setVisible(1);
    }
}

// Функция для обновления расположения календаря
void MainWindow::updateCalendarPosition() {
    int calendarWidth = calendarWidget->width();
    int windowWidth = this->width();
    int newXPosition = windowWidth - calendarWidth - calendarMargin;
    calendarWidget->move(newXPosition, calendarWidget->y());
}

// Функция для обработки изменения окна
void MainWindow::resizeEvent(QResizeEvent *event) {
    updateCalendarPosition();
    QWidget::resizeEvent(event);
}

// Слот для завершения редактирования в поле ввода
// void MainWindow::onEditFin   ished() {
//     ui->edit_line->setVisible(0);
//     ui->edit_text->setText(ui->edit_line->text());
//     ui->edit_text->setVisible(1);
// }

// void MainWindow::createNewEventWidget() {
//     // Создаем новый виджет
//     QWidget *newWidget = new QWidget();

//     // Создаем горизонтальный layout для размещения элементов в одной строке
//     QHBoxLayout *layout = new QHBoxLayout();

//     // Создаем поле для ввода текста (например, QLineEdit)
//     QLineEdit *lineEdit = new QLineEdit();
//     lineEdit->setPlaceholderText("Введите событие");

//     // Создаем кнопку
//     QPushButton *button = new QPushButton("Добавить событие");

//     // Добавляем поле и кнопку в layout
//     layout->addWidget(lineEdit);
//     layout->addWidget(button);

//     // Устанавливаем layout для нового виджета
//     newWidget->setLayout(layout);

//     // Добавляем новый виджет в today_page
//     ui->today_page->layout()->addWidget(newWidget);
// }

