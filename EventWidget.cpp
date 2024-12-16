#include "EventWidget.h"

EventWidget::EventWidget(QWidget *parent) : QWidget(parent)
{
    leftButton = new QPushButton("◯", this);
    fixedSpacer = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);
    label = new QLabel("Добавить событие", this);
    lineEdit = new QLineEdit(this);
    expandingSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    rightButton = new QPushButton("⋮", this);

    lineEdit->setPlaceholderText("Введите текст...");
    lineEdit->hide();

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setContentsMargins(20, 0, 20, 0);

    layout->addWidget(leftButton);
    layout->addSpacerItem(fixedSpacer);
    layout->addWidget(label);
    layout->addWidget(lineEdit);
    layout->addSpacerItem(expandingSpacer);
    layout->addWidget(rightButton);

    this->setFixedHeight(60);
}

void EventWidget::onEditFinished() {}
