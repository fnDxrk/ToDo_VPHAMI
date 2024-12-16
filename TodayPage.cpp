#include "TodayPage.h"
#include <QScrollArea>

TodayPage::TodayPage(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    QWidget *scrollWidget = new QWidget(this);
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollWidget);

    for (int i = 0; i < 5; ++i) {
        EventWidget *item = new EventWidget(this);
        scrollLayout->addWidget(item);
    }

    spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
    scrollLayout->addSpacerItem(spacer);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(scrollWidget);
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);

    layout->addWidget(scrollArea);

    setLayout(layout);
}

TodayPage::~TodayPage() {}
