#ifndef TODAYPAGE_H
#define TODAYPAGE_H

#include <QWidget>

#include "AddEventWidget.h"
#include "EventWidget.h"
#include "EventListWidget.h"

class TodayPage : public QWidget
{
    Q_OBJECT

public:
    explicit TodayPage(QWidget *parent = nullptr);
    ~TodayPage();

private:
    QVBoxLayout *scrollLayout;
    QSpacerItem *spacer;
    EventListWidget *eventListWidget;

private slots:
    void addEventWidget();
    void handleEventCompleted(EventWidget *widget);
};

#endif // TODAYPAGE_H
