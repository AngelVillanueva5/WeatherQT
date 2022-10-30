#ifndef DEVELOPER_H
#define DEVELOPER_H

#include <QWidget>

namespace Ui {
class developer;
}

class developer : public QWidget
{
    Q_OBJECT

public:
    explicit developer(QWidget *parent = nullptr);
    ~developer();

private:
    Ui::developer *ui;
};

#endif // DEVELOPER_H
