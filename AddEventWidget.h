#ifndef ADDEVENTWIDGET_H
#define ADDEVENTWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QLabel>
#include <QIcon>

class AddEventWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AddEventWidget(QWidget *parent = nullptr);

signals:
    void leftButtonClicked();

private:
    QPushButton *leftButton;
    QSpacerItem *fixedSpacer;
    QLabel *label;
    QSpacerItem *expandingSpacer;

private slots:

};

#endif // ADDEVENTWIDGET_H
