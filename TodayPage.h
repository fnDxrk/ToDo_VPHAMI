#ifndef TODAYPAGE_H
#define TODAYPAGE_H

#include <QWidget>

#include "AddEventWidget.h"
#include "EventWidget.h"

class TodayPage : public QWidget
{
    Q_OBJECT

public:
    explicit TodayPage(QWidget *parent = nullptr);
    ~TodayPage();

private:
    QVBoxLayout *scrollLayout;
    QSpacerItem *spacer;

private slots:
    void addEventWidget();
};

#endif // TODAYPAGE_H
