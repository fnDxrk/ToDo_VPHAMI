#ifndef EVENTWIDGET_H
#define EVENTWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QLabel>
#include <QLineEdit>
#include <QIcon>

class EventWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EventWidget(QWidget *parent = nullptr);

private:
    QPushButton *leftButton;
    QSpacerItem *fixedSpacer;
    QLabel *label;
    QLineEdit *labelEdit;
    QSpacerItem *expandingSpacer;
    QPushButton *rightButton;

private slots:
    void onEditingFinished();
};

#endif // EVENTWIDGET_H
