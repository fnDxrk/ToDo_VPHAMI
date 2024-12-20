#include "EventListWidget.h"
#include <QDebug>

EventListWidget::EventListWidget(QWidget *parent) : QWidget(parent), isExpanded(false)
{
    setupUI();
    connectSignals();
}

void EventListWidget::setupUI()
{
    setAttribute(Qt::WA_StyledBackground, true);
    this->setFixedHeight(60);

    leftButton = new QPushButton(this);
    leftButton->setIcon(QIcon(":/resource/icons/Arrow_right.png"));
    leftButton->setIconSize(QSize(20, 20));

    fixedSpacer = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

    label = new QLabel("Список событий", this);

    expandingSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    rightButton = new QPushButton(this);
    rightButton->setIcon(QIcon(":/resource/icons/Options.png"));
    rightButton->setIconSize(QSize(20, 20));

    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(20, 0, 20, 0);

    QHBoxLayout *topLayout = new QHBoxLayout;
    topLayout->addWidget(leftButton);
    topLayout->addSpacerItem(fixedSpacer);
    topLayout->addWidget(label);
    topLayout->addSpacerItem(expandingSpacer);
    topLayout->addWidget(rightButton);

    mainLayout->addLayout(topLayout);

    for (EventWidget *widget : eventWidgets) {
        mainLayout->addWidget(widget);
        widget->hide();
    }
}

void EventListWidget::connectSignals()
{
    connect(leftButton, &QPushButton::clicked, this, &EventListWidget::onLeftButtonClicked);
    connect(rightButton, &QPushButton::clicked, this, &EventListWidget::onRightButtonClicked);
}

void EventListWidget::addEventWidget(EventWidget *widget)
{
    if (widget) {
        eventWidgets.append(widget);
        mainLayout->addWidget(widget);
        widget->hide();
    }
}

void EventListWidget::onLeftButtonClicked()
{
    toggleListVisibility();
}

void EventListWidget::onRightButtonClicked()
{
    qDebug() << "Right button clicked";
}

void EventListWidget::toggleListVisibility()
{
    isExpanded = !isExpanded;

    if (isExpanded) {
        leftButton->setIcon(QIcon(":/resource/icons/Arrow_right.png"));
        for (EventWidget *widget : eventWidgets) {
            widget->show();
        }
    } else {
        leftButton->setIcon(QIcon(":/resource/icons/Arrow_down.png"));
        for (EventWidget *widget : eventWidgets) {
            widget->hide();
        }
    }
}
