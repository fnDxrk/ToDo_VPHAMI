#include "AddEventWidget.h"

AddEventWidget::AddEventWidget(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StyledBackground, true);
    this->setFixedHeight(60);

    leftButton = new QPushButton(this);
    leftButton->setIcon(QIcon(":/resource/icons/Plus.png"));
    leftButton->setIconSize(QSize(20,20));
    fixedSpacer = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);
    label = new QLabel("Добавить событие", this);
    expandingSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setContentsMargins(20, 0, 20, 0);

    layout->addWidget(leftButton);
    layout->addSpacerItem(fixedSpacer);
    layout->addWidget(label);
    layout->addSpacerItem(expandingSpacer);

    connect(leftButton, &QPushButton::clicked, this, &AddEventWidget::leftButtonClicked);
}
