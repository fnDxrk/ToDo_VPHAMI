#ifndef TODAYPAGE_H
#define TODAYPAGE_H

#include <QWidget>

#include "EventWidget.h"

class TodayPage : public QWidget
{
    Q_OBJECT

public:
    explicit TodayPage(QWidget *parent = nullptr);
    ~TodayPage();

private:
    QSpacerItem *spacer;
};

#endif // TODAYPAGE_H
