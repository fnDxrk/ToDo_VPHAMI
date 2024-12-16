#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CalendarManager.h"
#include <QMainWindow>

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
    CalendarManager *calendarManager;

private slots:
    void showFullMenu();            // Слот для отображения full_menu_widget
    void showIconMenu();            // Слот для отображения icom_menu_widget
    void showTodayPage();           // Слот для преключения на страницу today_page
    void showPlansPage();           // Слот для преключения на страницу calendar_page
    void showTasksPage();           // Слот для преключения на страницу tasks_page
    // void onEditFinished();          // Слот для завершения редактирования в поле ввода
    // void createNewEventWidget();    // Слот для создания нового виджета событий
};
#endif // MAINWINDOW_H
