#ifndef EVENTWIDGET_H
#define EVENTWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QLabel>
#include <QLineEdit>
#include <QIcon>

#include "EventContextMenu.h"

class EventWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EventWidget(QWidget *parent = nullptr);
    bool isEditing() const;

private:
    QPushButton *leftButton;
    QSpacerItem *fixedSpacer;
    QLabel *label;
    QLineEdit *labelEdit;
    QSpacerItem *expandingSpacer;
    QPushButton *rightButton;
    EventContextMenu *contextMenu;

private slots:
    void onEditingFinished();
    void onRightButtonClicked();
    void onRenameAction();
    void onDeleteAction();
};

#endif // EVENTWIDGET_H
