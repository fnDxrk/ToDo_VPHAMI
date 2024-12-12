#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private:
    Ui::MainWindow *ui;

private slots:
    void showFullMenu();        // Слот для отображения full_menu_widget
    void showIconMenu();        // Слот для отображения icom_menu_widget
    void showTodayPage();       // Слот для преключения на страницу today_page
    void showPlansPage();    // Слот для преключения на страницу calendar_page
    void showTasksPage();       // Слот для преключения на страницу tasks_page
};
#endif // MAINWINDOW_H
