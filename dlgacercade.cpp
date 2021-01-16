#include "dlgacercade.h"
#include "ui_dlgacercade.h"

DlgAcercaDe::DlgAcercaDe(int theme, QWidget *parent) :
  QDialog(parent),ui(new Ui::DlgAcercaDe),_theme(theme)
{
  ui->setupUi(this);
  setWindowFlags(Qt::Dialog|Qt::MSWindowsFixedSizeDialogHint);
  setLogo(_theme);
}

DlgAcercaDe::~DlgAcercaDe()
{
  delete ui;
}

void DlgAcercaDe::on_pushButton_clicked()
{
  accept();
}

void DlgAcercaDe::setLogo(int themeA)
{
  if(themeA==0){
      QPixmap logo(":/img/logoEmpresa.png");
      ui->lblLogo->setPixmap(logo);
    }else{
      QPixmap logo2(":/img/logoEmpresa2.png");
      ui->lblLogo->setPixmap(logo2);
    }
  ui->lblLogo->setScaledContents(true);
}
