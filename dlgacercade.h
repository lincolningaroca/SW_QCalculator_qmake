#ifndef DLGACERCADE_H
#define DLGACERCADE_H

#include <QDialog>

namespace Ui {
class DlgAcercaDe;
}

class DlgAcercaDe : public QDialog
{
    Q_OBJECT

public:
    explicit DlgAcercaDe(int theme, QWidget *parent = nullptr);
    ~DlgAcercaDe();

private slots:
    void on_pushButton_clicked();
    void setLogo(int themeA);

private:
    Ui::DlgAcercaDe *ui;
    int _theme=0;
};

#endif // DLGACERCADE_H
