#include "TodayPage.h"
#include <QScrollArea>

TodayPage::TodayPage(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QWidget *scrollWidget = new QWidget(this);
    scrollLayout = new QVBoxLayout(scrollWidget);

    AddEventWidget *addEventItem = new AddEventWidget(this);
    scrollLayout->addWidget(addEventItem);

    connect(addEventItem, &AddEventWidget::leftButtonClicked, this, &TodayPage::addEventWidget);

    spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    scrollLayout->addSpacerItem(spacer);
    scrollLayout->setSpacing(20);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);

    layout->addWidget(scrollArea);

    setLayout(layout);
}

TodayPage::~TodayPage() {}

void TodayPage::addEventWidget()
{
    scrollLayout->removeItem(spacer);
    EventWidget *eventItem = new EventWidget(this);
    scrollLayout->insertWidget(0, eventItem);
    scrollLayout->addSpacerItem(spacer);
}
