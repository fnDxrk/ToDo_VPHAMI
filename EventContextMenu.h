#ifndef EVENTCONTEXTMENU_H
#define EVENTCONTEXTMENU_H

#include <QWidget>
#include <QMenu>

class EventContextMenu : public QMenu
{
    Q_OBJECT
public:
    explicit EventContextMenu(QWidget *parent = nullptr);
    void showMenu(const QPoint &pos);

signals:
    void renameRequested();
    void deleteRequested();

private:
    QAction *renameAction;
    QAction *deleteAction;
};

#endif // EVENTCONTEXTMENU_H
