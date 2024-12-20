#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "CalendarManager.h"
#include "TodayPage.h"


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
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWindow *ui;
    CalendarManager *calendarManager;
    TodayPage *todayPage;

    void setupUI();
    void connectSignalsAndSlots();

private slots:
    void showFullMenu();
    void showIconMenu();
    void showTodayPage();
};
#endif // MAINWINDOW_H
