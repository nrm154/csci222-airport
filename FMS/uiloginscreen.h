#ifndef UILOGINSCREEN_H
#define UILOGINSCREEN_H

#include <QDialog>

namespace Ui {
class UILoginScreen;
}

class UILoginScreen : public QDialog
{
    Q_OBJECT

public:
    explicit UILoginScreen(QWidget *parent = 0);
    ~UILoginScreen();

private:
    Ui::UILoginScreen *ui;

private slots:
    void LoginPressed();
};

#endif // UILOGINSCREEN_H
