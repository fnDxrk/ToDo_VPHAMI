#include "EventContextMenu.h"

EventContextMenu::EventContextMenu(QWidget *parent) : QMenu(parent)
{
    renameAction = new QAction("Переименовать", this);
    deleteAction = new QAction("Удалить", this);

    addAction(renameAction);
    addAction(deleteAction);

    connect(renameAction, &QAction::triggered, this, &EventContextMenu::renameRequested);
    connect(deleteAction, &QAction::triggered, this, &EventContextMenu::deleteRequested);
}

void EventContextMenu::showMenu(const QPoint &pos)
{
    exec(pos);
}
