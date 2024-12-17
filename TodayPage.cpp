#include "TodayPage.h"
#include <QScrollArea>

TodayPage::TodayPage(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QWidget *scrollWidget = new QWidget(this);
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);

    AddEventWidget *item = new AddEventWidget(this);
    scrollLayout->addWidget(item);

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
