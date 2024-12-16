#include "CalendarManager.h"

CalendarManager::CalendarManager(QWidget *parent)
    : QObject(parent), parentWidget(parent) {
    calendarWidget = new QCalendarWidget(parentWidget);
    calendarWidget->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    calendarWidget->setVisible(false);
    calendarWidget->setGeometry(calendarX, calendarY, calendarWidth, calendarHeight);
}

void CalendarManager::toggleCalendarVisibility() {
    calendarWidget->setVisible(!calendarWidget->isVisible());
}

void CalendarManager::updateCalendarPosition() {
    int calendarWidth = calendarWidget->width();
    int windowWidth = parentWidget->width();
    int newXPosition = windowWidth - calendarWidth - calendarMargin;
    calendarWidget->move(newXPosition, calendarWidget->y());
}
