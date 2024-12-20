#ifndef EVENTLISTWIDGET_H
#define EVENTLISTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QSpacerItem>
#include <QVBoxLayout>
#include <QList>
#include "EventWidget.h"

class EventListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EventListWidget(QWidget *parent = nullptr);
    void addEventWidget(EventWidget *widget);

private:
    QPushButton *leftButton;
    QSpacerItem *fixedSpacer;
    QLabel *label;
    QSpacerItem *expandingSpacer;
    QPushButton *rightButton;

    QList<EventWidget*> eventWidgets;

    QVBoxLayout *mainLayout;

    bool isExpanded;

    void setupUI();
    void connectSignals();
    void toggleListVisibility();

private slots:
    void onLeftButtonClicked();
    void onRightButtonClicked();
};

#endif // EVENTLISTWIDGET_H
