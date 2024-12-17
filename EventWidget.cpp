#include "EventWidget.h"

EventWidget::EventWidget(QWidget *parent) : QWidget(parent)
{
    setAttribute(Qt::WA_StyledBackground, true);
    this->setFixedHeight(60);

    leftButton = new QPushButton(this);
    leftButton->setIcon(QIcon(":/resource/icons/Circle.png"));
    leftButton->setIconSize(QSize(20,20));

    fixedSpacer = new QSpacerItem(10, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

    label = new QLabel(this);
    label->hide();

    labelEdit = new QLineEdit(this);
    labelEdit->setPlaceholderText("Введите текст...");

    expandingSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    rightButton = new QPushButton(this);
    rightButton->setIcon(QIcon(":/resource/icons/Options.png"));
    rightButton->setIconSize(QSize(20,20));
    rightButton->hide();

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setContentsMargins(20, 0, 20, 0);

    layout->addWidget(leftButton);
    layout->addSpacerItem(fixedSpacer);
    layout->addWidget(labelEdit);
    layout->addWidget(label);
    layout->addSpacerItem(expandingSpacer);
    layout->addWidget(rightButton);

    connect(labelEdit, &QLineEdit::editingFinished, this, &EventWidget::onEditingFinished);
}

void EventWidget::onEditingFinished()
{
    QString text = labelEdit->text();
    if (!text.isEmpty()) {
        label->setText(text);
        label->show();
        labelEdit->hide();
        rightButton->show();
    }
}
