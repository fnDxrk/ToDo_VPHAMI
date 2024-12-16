#ifndef EVENTWIDGET_H
#define EVENTWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QLabel>
#include <QLineEdit>

class EventWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EventWidget(QWidget *parent = nullptr);

private:
    QPushButton* leftButton;
    QSpacerItem* fixedSpacer;
    QLabel* label;
    QLineEdit* lineEdit;
    QSpacerItem* expandingSpacer;
    QPushButton* rightButton;

private slots:
    void onEditFinished();
};

#endif // EVENTWIDGET_H
