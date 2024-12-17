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

    contextMenu = new EventContextMenu(this);

    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->setContentsMargins(20, 0, 20, 0);

    layout->addWidget(leftButton);
    layout->addSpacerItem(fixedSpacer);
    layout->addWidget(labelEdit);
    layout->addWidget(label);
    layout->addSpacerItem(expandingSpacer);
    layout->addWidget(rightButton);

    connect(contextMenu, &EventContextMenu::renameRequested, this, &EventWidget::onRenameAction);
    connect(contextMenu, &EventContextMenu::deleteRequested, this, &EventWidget::onDeleteAction);

    connect(rightButton, &QPushButton::clicked, this, &EventWidget::onRightButtonClicked);

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

bool EventWidget::isEditing() const
{
    return labelEdit->isVisible();
}

void EventWidget::onRightButtonClicked()
{
    if (isEditing()) {
        contextMenu->showMenu(QCursor::pos(), false);
    } else {
        contextMenu->showMenu(QCursor::pos(), true);
    }
}

void EventWidget::onRenameAction()
{
    label->hide();
    labelEdit->setText(label->text());
    labelEdit->show();
    labelEdit->setFocus();
}

void EventWidget::onDeleteAction()
{
    this->deleteLater();
}
