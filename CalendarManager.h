#ifndef CALENDARMANAGER_H
#define CALENDARMANAGER_H

#include <QWidget>
#include <QCalendarWidget>
#include <QResizeEvent>

class CalendarManager : public QObject
{
    Q_OBJECT

public:
    explicit CalendarManager(QWidget *parent);

    void toggleCalendarVisibility();
    void updateCalendarPosition();

private:
    QCalendarWidget *calendarWidget;
    QWidget *parentWidget;

    const int calendarMargin = 20;
    const int calendarWidth = 280;
    const int calendarHeight = 280;
    int calendarX = 1010;
    int calendarY = 98;
};

#endif // CALENDARMANAGER_H
