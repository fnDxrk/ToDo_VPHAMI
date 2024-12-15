#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCalendarWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    // Переопределяем resizeEvent для обработки изменения размера окна
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWindow *ui;
    QCalendarWidget *calendarWidget;        // Виджет календаря

    static const int calendarMargin = 20;   // Статическая константа для отспупа календаря

    void updateCalendarPosition();          // Функция для обновления расположения календаря

private slots:
    void showFullMenu();    // Слот для отображения full_menu_widget
    void showIconMenu();    // Слот для отображения icom_menu_widget
    void showTodayPage();   // Слот для преключения на страницу today_page
    void showPlansPage();   // Слот для преключения на страницу calendar_page
    void showTasksPage();   // Слот для преключения на страницу tasks_page
    void showCalendar();    // Слот для отображения или скрытия календаря
    void onEditFinished();  // Слот для завершения редактирования в поле ввода
};
#endif // MAINWINDOW_H
