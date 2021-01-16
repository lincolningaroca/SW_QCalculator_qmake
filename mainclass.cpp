#include "mainclass.h"
#include "dlgacercade.h"
#include "ui_mainclass.h"
#include <QDebug>
#include <QHeaderView>
#include <QMessageBox>

MainClass::MainClass(QWidget *parent) :
  QWidget(parent), ui(new Ui::MainClass)
{
  ui->setupUi(this);
  loadWindow();
  setUpSpinBox();
  setUpSpinBoxF();
  setUpDataCorrentometro();
  setUpDataResultados();
  //  ui->lblAcerca->installEventFilter(this);
  lblAbout();
  setTheme(ui->comboBox->currentIndex());
}

MainClass::~MainClass()
{
  delete ui;
}
/******configuraciones iniciales para los doubleSpinBox*****/

void MainClass::setUpSpinBox()
{
  /************************Velocity spin box*******************************/
  //set decimal
  //  ui->dspVelocidad1->setDecimals(3);

  //set the minimum values
  //  ui->dspVelocidad2->setFocus();
  ui->dspVelocidad1->setMinimum(0);
  ui->dspVelocidad1->setMinimum(0);
  ui->dspVelocidad1->setMinimum(0);
  //set the maximum values.
  ui->dspVelocidad1->setMaximum(std::numeric_limits<double>::max());
  ui->dspVelocidad2->setMaximum(std::numeric_limits<double>::max());
  ui->dspVelocidad3->setMaximum(std::numeric_limits<double>::max());
  //average spinbox
  ui->dsbPromedio->setMaximum(std::numeric_limits<double>::max());
  //set readonly the dsbPromedio
  ui->dsbPromedio->setReadOnly(true);

  /************************Time spin box*******************************/
  //set the minimum values
  ui->dspTiempo1->setMinimum(0);
  ui->dspTiempo2->setMinimum(0);
  ui->dspTiempo3->setMinimum(0);
  //set the maximum values.
  ui->dspTiempo1->setMaximum(std::numeric_limits<double>::max());
  ui->dspTiempo2->setMaximum(std::numeric_limits<double>::max());
  ui->dspTiempo3->setMaximum(std::numeric_limits<double>::max());
  //average spinbox
  ui->dspTiempoPromedio->setMaximum(std::numeric_limits<double>::max());
  //set readonly the dsbPromedio
  ui->dspTiempoPromedio->setReadOnly(true);
  /**************set minimum and maximun values for final caudala**************/

  /*****do read only****/
  ui->qLitrosSeg->setReadOnly(true);
  ui->qMetrosCubSeg->setReadOnly(true);
  ui->qMetrosCubDia->setReadOnly(true);
  ui->qLitrosSeg->setMaximum(std::numeric_limits<double>::max());
  ui->qLitrosSeg->setDecimals(3);
  ui->qMetrosCubDia->setMaximum(std::numeric_limits<double>::max());
  ui->qMetrosCubSeg->setMaximum(std::numeric_limits<double>::max());
  ui->qMetrosCubSeg->setDecimals(4);
  /***********no focus policy************************/
  ui->dsbPromedio->setFocusPolicy(Qt::NoFocus);
  ui->dspTiempoPromedio->setFocusPolicy(Qt::NoFocus);
  ui->qLitrosSeg->setFocusPolicy(Qt::NoFocus);
  ui->qMetrosCubDia->setFocusPolicy(Qt::NoFocus);
  ui->qMetrosCubSeg->setFocusPolicy(Qt::NoFocus);

  /***********agregando sufijos. litros***********/
  ui->dspVelocidad1->setSuffix(" Lts.");
  ui->dspVelocidad2->setSuffix(" Lts.");
  ui->dspVelocidad3->setSuffix(" Lts.");
  ui->dsbPromedio->setSuffix(" Lts.");
  /***********agregando sufijos. segundos ***********/

  ui->dspTiempo1->setSuffix(" Seg.");
  ui->dspTiempo2->setSuffix(" Seg.");
  ui->dspTiempo3->setSuffix(" Seg.");
  ui->dspTiempoPromedio->setSuffix(" Seg.");
  /***************sufijo para los caudales*************/

  ui->qLitrosSeg->setSuffix(" Lts/seg.");
  ui->qMetrosCubDia->setSuffix(" m3/día.");
  ui->qMetrosCubSeg->setSuffix(" m3/seg.");

  //resultados de caudales
}

void MainClass::setUpDataCorrentometro()
{
  QStringList colums;
  colums << "V"
         << "Velocidad (m/s)"
         << "H"
         << "Profundidad (cm)";
  ui->tableWidget_4->setColumnCount(colums.count());
  ui->tableWidget_4->setHorizontalHeaderLabels(colums);
  //  ui->tableWidget_4->verticalHeader()->setSectionResizeMode(1,QHeaderView::Fixed);
  ui->tableWidget_4->setColumnWidth(0, 20);
  ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
  //  ui->tableWidget_4->horizontalHeader()->setEditTriggers()
  ui->tableWidget_4->setColumnWidth(2, 20);
  ui->tableWidget_4->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Fixed);
  ui->tableWidget_4->horizontalHeader()->setEditTriggers(QAbstractItemView::NoEditTriggers);

  ui->tableWidget_5->setEditTriggers(QAbstractItemView::NoEditTriggers);

  //  ui->tableWidget->verticalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);

  ui->dsbTotalMetSeg_1->setMaximum(std::numeric_limits<double>::max());
  ui->dsbTotalLitSeg_1->setMaximum(std::numeric_limits<double>::max());
  ui->dsbTotalMetDia_1->setMaximum(std::numeric_limits<double>::max());
  ui->dsbTotalMetSeg_1->setDecimals(6);
  ui->dsbTotalLitSeg_1->setDecimals(6);
  ui->dsbTotalMetDia_1->setDecimals(6);

  ui->dsbAncho->setMaximum(999);
  ui->dsbMedSegmento->setMaximum(999);

  //solo lectura
  ui->dsbTotalMetDia_1->setReadOnly(true);
  ui->dsbTotalMetDia_1->setFocusPolicy(Qt::NoFocus);
  ui->dsbTotalMetSeg_1->setReadOnly(true);
  ui->dsbTotalMetSeg_1->setFocusPolicy(Qt::NoFocus);
  ui->dsbTotalLitSeg_1->setReadOnly(true);
  ui->dsbTotalLitSeg_1->setFocusPolicy(Qt::NoFocus);

  //set shortcut
  ui->brnAgregar->setShortcut(QKeySequence(Qt::Key_Enter));
}

void MainClass::setUpDataResultados()
{
  QStringList colums;
  colums << "Q.."
         << "Q Parciales (m3/s)";
  ui->tableWidget_5->setColumnCount(colums.count());
  ui->tableWidget_5->setHorizontalHeaderLabels(colums);
  //  ui->tableWidget_4->verticalHeader()->setSectionResizeMode(1,QHeaderView::Fixed);
  ui->tableWidget_5->setColumnWidth(0, 20);
  ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
  //  ui->tableWidget_5->setColumnWidth(2,100);
  //  ui->tableWidget_5->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Fixed);
}

void MainClass::loadWindow()
{
  setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
}

void MainClass::lblAbout()
{
  ui->lblAcerca->setText("<a href=\"whatever\">Acerca de.</a>");
  connect(ui->lblAcerca, &QLabel::linkActivated, this, &MainClass::showDialog);
}

/**********limpiar los controles***************/

void MainClass::setUpSpinBoxF()
{
  ui->dsbLongitud2->setReadOnly(true);
  ui->dsbLongitud2->setFocusPolicy(Qt::NoFocus);
  ui->dsbV1->setReadOnly(true);
  ui->dsbV1->setFocusPolicy(Qt::NoFocus);
  ui->dsbV2->setReadOnly(true);
  ui->dsbV2->setFocusPolicy(Qt::NoFocus);
  ui->dsbV3->setReadOnly(true);
  ui->dsbV3->setFocusPolicy(Qt::NoFocus);
  ui->dsb_a1s->setReadOnly(true);
  ui->dsb_a1s->setFocusPolicy(Qt::NoFocus);
  ui->dsbA1->setReadOnly(true);
  ui->dsbA1->setFocusPolicy(Qt::NoFocus);
  ui->dsbA2->setReadOnly(true);
  ui->dsbA2->setFocusPolicy(Qt::NoFocus);
  ui->dsbA3->setReadOnly(true);
  ui->dsbA3->setFocusPolicy(Qt::NoFocus);

  ui->dsb_A1->setReadOnly(true);
  ui->dsb_A1->setFocusPolicy(Qt::NoFocus);
  ui->dsb_A2->setReadOnly(true);
  ui->dsb_A2->setFocusPolicy(Qt::NoFocus);
  ui->dsb_A3->setReadOnly(true);
  ui->dsb_A3->setFocusPolicy(Qt::NoFocus);

  ui->dsb_V1->setReadOnly(true);
  ui->dsb_V1->setFocusPolicy(Qt::NoFocus);
  ui->dsb_V2->setReadOnly(true);
  ui->dsb_V2->setFocusPolicy(Qt::NoFocus);
  ui->dsb_V3->setReadOnly(true);
  ui->dsb_V3->setFocusPolicy(Qt::NoFocus);
  ui->dsb_a2s->setReadOnly(true);
  ui->dsb_a2s->setFocusPolicy(Qt::NoFocus);
  ui->dsbQ1->setReadOnly(true);
  ui->dsbQ1->setFocusPolicy(Qt::NoFocus);

  ui->dsbQ1->setDecimals(4);
  ui->dsbQ2->setReadOnly(true);
  ui->dsbQ2->setFocusPolicy(Qt::NoFocus);
  ui->dsbQ2->setDecimals(4);

  ui->dsbQ3->setReadOnly(true);
  ui->dsbQ3->setFocusPolicy(Qt::NoFocus);
  ui->dsbQ3->setDecimals(4);

  ui->dsbTotalA1->setReadOnly(true);
  ui->dsbTotalA1->setFocusPolicy(Qt::NoFocus);
  ui->dsbTotalA2->setReadOnly(true);
  ui->dsbTotalA2->setFocusPolicy(Qt::NoFocus);
  ui->dsbTotalA3->setReadOnly(true);
  ui->dsbTotalA3->setFocusPolicy(Qt::NoFocus);

  ui->dsbTotalV1->setReadOnly(true);
  ui->dsbTotalV1->setFocusPolicy(Qt::NoFocus);
  ui->dsbTotalV2->setReadOnly(true);
  ui->dsbTotalV2->setFocusPolicy(Qt::NoFocus);
  ui->dsbTotalV3->setReadOnly(true);
  ui->dsbTotalV3->setFocusPolicy(Qt::NoFocus);

  ui->dsbResQMetSeg->setReadOnly(true);
  ui->dsbResQMetSeg->setFocusPolicy(Qt::NoFocus);
  ui->dsbResQMetSeg->setDecimals(4);

  ui->dsbResQLitSeg->setReadOnly(true);
  ui->dsbResQLitSeg->setFocusPolicy(Qt::NoFocus);
  ui->dsbResQLitSeg->setDecimals(4);

  ui->dsbResQMetDia->setReadOnly(true);
  ui->dsbResQMetDia->setFocusPolicy(Qt::NoFocus);
  ui->dsbResQMetDia->setDecimals(4);

  //valores maximos para longitud
  ui->dsbLongitud1->setMaximum(999);
  ui->dsbLongitud2->setMaximum(std::numeric_limits<double>::max());
  //valores maximos y digitos decimales para el tiempo
  ui->dsbT1->setMaximum(999);
  ui->dsbT2->setMaximum(999);
  ui->dsbT3->setMaximum(999);

  //valores maximos y digitos decimales para el velocidad
  ui->dsbV1->setMaximum(std::numeric_limits<double>::max());
  ui->dsbV2->setMaximum(std::numeric_limits<double>::max());
  ui->dsbV3->setMaximum(std::numeric_limits<double>::max());

  //valores maximos y digitos decimales para el ancho inicial
  ui->dsb_a1->setMaximum(999);
  ui->dsb_a1s->setMaximum(std::numeric_limits<double>::max());
  //valores maximos y digitos decimales para la altura
  ui->dsb_h1->setMaximum(999);
  ui->dsb_h2->setMaximum(999);
  ui->dsb_h3->setMaximum(999);

  //valores maximos y digitos decimales para el area parcial
  ui->dsbA1->setMaximum(std::numeric_limits<double>::max());
  ui->dsbA2->setMaximum(std::numeric_limits<double>::max());
  ui->dsbA3->setMaximum(std::numeric_limits<double>::max());

  //valores maximos y digitos decimales para el tiempo s2
  ui->dsb_T1->setMaximum(999);
  ui->dsb_T2->setMaximum(999);
  ui->dsb_T3->setMaximum(999);

  //valores maximos y digitos decimales para ancho final
  ui->dsb_a2->setMaximum(999);
  ui->dsb_a2s->setMaximum(std::numeric_limits<double>::max());

  //valores maximos y digitos decimales para la altura s2
  ui->dsb_h1s->setMaximum(999);
  ui->dsb_h2s->setMaximum(999);
  ui->dsb_h3s->setMaximum(999);
  //valores maximos para las areas parciales
  ui->dsb_A1->setMaximum(std::numeric_limits<double>::max());
  ui->dsb_A2->setMaximum(std::numeric_limits<double>::max());
  ui->dsb_A3->setMaximum(std::numeric_limits<double>::max());

  //valores maximos y digitos decimales para los totales de caudales
  ui->dsbResQMetDia->setMaximum(std::numeric_limits<double>::max());
  ui->dsbResQMetDia->setDecimals(3);
  ui->dsbResQLitSeg->setMaximum(std::numeric_limits<double>::max());
  ui->dsbResQLitSeg->setDecimals(3);
  ui->dsbResQMetSeg->setMaximum(std::numeric_limits<double>::max());
  ui->dsbResQMetSeg->setDecimals(4);

  //valores maximos para areas totales
  ui->dsbTotalA1->setMaximum(std::numeric_limits<double>::max());
  ui->dsbTotalA2->setMaximum(std::numeric_limits<double>::max());
  ui->dsbTotalA3->setMaximum(std::numeric_limits<double>::max());
  //valores maximos para velocidad total
  ui->dsbTotalV1->setMaximum(std::numeric_limits<double>::max());
  ui->dsbTotalV2->setMaximum(std::numeric_limits<double>::max());
  ui->dsbTotalV3->setMaximum(std::numeric_limits<double>::max());
  //valores maximos para caudales parciales
  ui->dsbQ1->setMaximum(std::numeric_limits<double>::max());
  ui->dsbQ2->setMaximum(std::numeric_limits<double>::max());
  ui->dsbQ3->setMaximum(std::numeric_limits<double>::max());
}
//limpiar controles del panel caudal volumetrico.
void MainClass::on_btnLimpiar_clicked()
{
  ui->dspVelocidad1->setValue(0.00);
  ui->dspVelocidad2->setValue(0.00);
  ui->dspVelocidad3->setValue(0.00);
  ui->dspTiempo1->setValue(0.00);
  ui->dspTiempo2->setValue(0.00);
  ui->dspTiempo3->setValue(0.00);
  ui->dsbPromedio->setValue(0.00);
  ui->dspTiempoPromedio->setValue(0.00);
  ui->qLitrosSeg->setValue(0.00);
  ui->qMetrosCubDia->setValue(0.00);
  ui->qMetrosCubSeg->setValue(0.00);
  ui->dspVelocidad1->setFocus(Qt::OtherFocusReason);
  ui->dspVelocidad1->selectAll();
  //  _isClean=Clean;
}
/*********************************************************************************************************/
/*********************************************************************************************************/
/**********funciones y logica del panel de caudal por flotador********************************************/

/**
 * @brief MainClass::on_dsbLongitud1_valueChanged
 * @param arg1
 * *asigna el valor de longitud 1 a longitud 2.
 */
//void MainClass::on_dsbLongitud1_valueChanged(double arg1)
//{
//  ui->dsbLongitud2->setValue(arg1/2);
//}

void MainClass::calVelocity(double val1, double val2, opV op)
{
  double res = 0;
  switch (op) {
    case opV::v1:
      res = val1 / (val2 * 100);
      ui->dsbV1->setValue(res);
      break;

    case opV::v2:
      res = val1 / (val2 * 100);
      ui->dsbV2->setValue(res);
      break;
    case opV::v3:
      res = val1 / (val2 * 100);
      ui->dsbV3->setValue(res);
      break;
    case opV::v1_c:
      res = val1 / (val2 * 100);
      ui->dsb_V1->setValue(res);
      break;
    case opV::v2_c:
      res = val1 / (val2 * 100);
      ui->dsb_V2->setValue(res);
      break;
    case opV::v3_c:
      res = val1 / (val2 * 100);
      ui->dsb_V3->setValue(res);
      break;
  }
}

void MainClass::calAreaParcial(double val1, double val2, opAParcial aP)
{
  double res = 0;
  switch (aP) {
    case MainClass::opAParcial::Ap1:
      res = (val1 * val2) / 10000;
      ui->dsbA1->setValue(res);
      break;

    case MainClass::opAParcial::Ap2:
      res = (val1 * val2) / 10000;
      ui->dsbA2->setValue(res);
      break;
    case MainClass::opAParcial::Ap3:
      res = (val1 * val2) / 10000;
      ui->dsbA3->setValue(res);
      break;
    case MainClass::opAParcial::Ap1_c:
      res = (val1 * val2) / 10000;
      ui->dsb_A1->setValue(res);
      break;
    case MainClass::opAParcial::Ap2_c:
      res = (val1 * val2) / 10000;
      ui->dsb_A2->setValue(res);
      break;
    case MainClass::opAParcial::Ap3_c:
      res = (val1 * val2) / 10000;
      ui->dsb_A3->setValue(res);
      break;
  }
}

void MainClass::calAreaTotal(double val1, double val2, C_AreaTotal aT)
{
  double res = 0;
  switch (aT) {
    case MainClass::C_AreaTotal::At1:
      res = (val1 + val2) / 2;
      ui->dsbTotalA1->setValue(res);
      break;
    case MainClass::C_AreaTotal::At2:
      res = (val1 + val2) / 2;
      ui->dsbTotalA2->setValue(res);
      break;
    case MainClass::C_AreaTotal::At3:
      res = (val1 + val2) / 2;
      ui->dsbTotalA3->setValue(res);
      break;
  }
}

void MainClass::calVelocidadTotal(double val1, double val2, MainClass::C_VelocidadTotal vT)
{
  double res = 0;
  switch (vT) {
    case MainClass::C_VelocidadTotal::Vt1:
      res = (val1 + val2) / 2;
      ui->dsbTotalV1->setValue(res);
      break;
    case MainClass::C_VelocidadTotal::Vt2:
      res = (val1 + val2) / 2;
      ui->dsbTotalV2->setValue(res);
      break;
    case MainClass::C_VelocidadTotal::Vt3:
      res = (val1 + val2) / 2;
      ui->dsbTotalV3->setValue(res);
      break;
  }
}

void MainClass::calQParcial(double val1, double val2, MainClass::C_QParcial qP)
{
  double res = 0;
  switch (qP) {
    case MainClass::C_QParcial::Qp1:
      res = (val1 * val2);
      ui->dsbQ1->setValue(res);
      break;
    case MainClass::C_QParcial::Qp2:
      res = (val1 * val2);
      ui->dsbQ2->setValue(res);
      break;
    case MainClass::C_QParcial::Qp3:
      res = (val1 * val2);
      ui->dsbQ3->setValue(res);
      break;
  }
}
/********metodos para calcular el promedio de la velocidad y el tiempo.************/
void MainClass::timeAverage(QList<double> v)
{
  double res = 0;
  for (const auto &i : v) {
    res = res + i;
  }

  ui->dspTiempoPromedio->setValue(res / 3);
  //  _isClean=W_data;
}
/*********calcula el caudal en litros por segundo********/
void MainClass::qLitros_Segundos(double vProm, double tProm)
{
  double res = vProm / tProm;
  ui->qLitrosSeg->setValue(res);
  //  _isClean=W_data;
}
/*********calcula el caudal en metros cúbicos por segundo********/
void MainClass::qMetCub_segundo(double pLitrosSeg)
{
  double res = pLitrosSeg / 1000;
  ui->qMetrosCubSeg->setValue(res);
  //  _isClean=W_data;
}
/*********calcula el caudal en metros cúbicos por día********/
void MainClass::qMetCub_Dia(double qMetCubSeg)
{
  double res = qMetCubSeg * 3600 * 24;
  ui->qMetrosCubDia->setValue(res);
  //  _isClean=W_data;
  //  qDebug()<<res;
}
void MainClass::speedAverage(QList<double> v)
{
  double res = 0;
  for (const auto &i : v) {
    res = res + i;
  }
  ui->dsbPromedio->setValue(res / 3);
  //  _isClean=W_data;
}
/**********cambiar entre paginas del stackWidget**************/
void MainClass::on_btnVolumetrico_clicked()
{
  //  if(_isClean==W_data) return;

  ui->stackedWidget->setCurrentIndex(2);
  ui->dspVelocidad1->setFocus(Qt::OtherFocusReason);
  ui->dspVelocidad1->selectAll();
  //  on_btnLimpiar_clicked();r
}

void MainClass::on_btnFlotador_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);
  ui->dsbLongitud1->setFocus(Qt::OtherFocusReason);
  ui->dsbLongitud1->selectAll();
}

void MainClass::on_btnCorrectometro_clicked()
{
  ui->stackedWidget->setCurrentIndex(0);
  ui->dsbAncho->setFocus(Qt::OtherFocusReason);
  ui->dsbAncho->selectAll();
}
/**
 * metodo change de los spin box, velicidad 1,2,3
 *
 */
void MainClass::on_dspVelocidad1_valueChanged(double arg1)
{
  QList<double> v;
  v << arg1 << ui->dspVelocidad2->value() << ui->dspVelocidad3->value();
  speedAverage(v);
  qLitros_Segundos(ui->dsbPromedio->value(), ui->dspTiempoPromedio->value());
  qMetCub_segundo(ui->qLitrosSeg->value());
  qMetCub_Dia(ui->qMetrosCubSeg->value());
}

void MainClass::on_dspVelocidad2_valueChanged(double arg1)
{
  QList<double> v;
  v << ui->dspVelocidad1->value() << arg1 << ui->dspVelocidad3->value();
  speedAverage(v);
  qLitros_Segundos(ui->dsbPromedio->value(), ui->dspTiempoPromedio->value());
  qMetCub_segundo(ui->qLitrosSeg->value());
  qMetCub_Dia(ui->qMetrosCubSeg->value());
}

void MainClass::on_dspVelocidad3_valueChanged(double arg1)
{
  QList<double> v;
  v << ui->dspVelocidad1->value() << ui->dspVelocidad2->value() << arg1;
  speedAverage(v);
  qLitros_Segundos(ui->dsbPromedio->value(), ui->dspTiempoPromedio->value());
  qMetCub_segundo(ui->qLitrosSeg->value());
  qMetCub_Dia(ui->qMetrosCubSeg->value());
}
/**
 * metodo change de los spin box, tiempo 1,2,3
 *
 */

void MainClass::on_dspTiempo1_valueChanged(double arg1)
{
  QList<double> v;
  v << arg1 << ui->dspTiempo2->value() << ui->dspTiempo3->value();
  timeAverage(v);
  qLitros_Segundos(ui->dsbPromedio->value(), ui->dspTiempoPromedio->value());
  qMetCub_segundo(ui->qLitrosSeg->value());
  qMetCub_Dia(ui->qMetrosCubSeg->value());
}

void MainClass::on_dspTiempo2_valueChanged(double arg1)
{
  QList<double> v;
  v << ui->dspTiempo1->value() << arg1 << ui->dspTiempo3->value();
  timeAverage(v);
  qLitros_Segundos(ui->dsbPromedio->value(), ui->dspTiempoPromedio->value());
  qMetCub_segundo(ui->qLitrosSeg->value());
  qMetCub_Dia(ui->qMetrosCubSeg->value());
}

void MainClass::on_dspTiempo3_valueChanged(double arg1)
{
  QList<double> v;
  v << ui->dspTiempo1->value() << ui->dspTiempo2->value() << arg1;
  timeAverage(v);
  qLitros_Segundos(ui->dsbPromedio->value(), ui->dspTiempoPromedio->value());
  qMetCub_segundo(ui->qLitrosSeg->value());
  qMetCub_Dia(ui->qMetrosCubSeg->value());
}
void MainClass::calQMetrosSeg(double val1, double val2, double val3)
{
  double res = 0;
  res = (val1 + val2 + val3);
  ui->dsbResQMetSeg->setValue(res);
}

void MainClass::calQLitrosSeg(double val1)
{
  double res = 0;
  res = (val1 * 1000);
  ui->dsbResQLitSeg->setValue(res);
}

void MainClass::calQMetrosDia(double val1)
{
  double res = 0;
  res = (val1 * 3600 * 24);
  ui->dsbResQMetDia->setValue(res);
}

//}
/******metodos del panel caudal flotador*****/
void MainClass::on_dsbLongitud1_valueChanged(double arg1)
{
  ui->dsbLongitud2->setValue((arg1 / 2));
  //  if(ui->dsbT1->value()!=0)
  calVelocity(ui->dsbLongitud2->value(), ui->dsbT1->value(), v1);

  calVelocity(ui->dsbLongitud2->value(), ui->dsbT2->value(), v2);
  calVelocity(ui->dsbLongitud2->value(), ui->dsbT3->value(), v3);
  calVelocity(ui->dsbLongitud2->value(), ui->dsb_T1->value(), v1_c);
  calVelocity(ui->dsbLongitud2->value(), ui->dsb_T2->value(), v2_c);
  calVelocity(ui->dsbLongitud2->value(), ui->dsb_T3->value(), v3_c);

  //calcular velocidad total
  //  if(ui->dsbV1->value()!=0 && ui->dsb_V1->value()!=0)
  calVelocidadTotal(ui->dsbV1->value(), ui->dsb_V1->value(), C_VelocidadTotal::Vt1);

  calVelocidadTotal(ui->dsbV2->value(), ui->dsb_V2->value(), C_VelocidadTotal::Vt2);
  calVelocidadTotal(ui->dsbV3->value(), ui->dsb_V3->value(), C_VelocidadTotal::Vt3);
  //calcular caudales parciales
  //  if(ui->dsbTotalA1->value()!=0 && ui->dsbTotalV1->value()!=0)
  calQParcial(ui->dsbTotalA1->value(), ui->dsbTotalV1->value(), MainClass::C_QParcial::Qp1);
  calQParcial(ui->dsbTotalA2->value(), ui->dsbTotalV2->value(), MainClass::C_QParcial::Qp2);
  calQParcial(ui->dsbTotalA3->value(), ui->dsbTotalV3->value(), MainClass::C_QParcial::Qp3);
  //calcular caudal total, de los caudales
  calQMetrosSeg(ui->dsbQ1->value(), ui->dsbQ2->value(), ui->dsbQ3->value());
  calQLitrosSeg(ui->dsbResQMetSeg->value());
  calQMetrosDia(ui->dsbResQMetSeg->value());
}

void MainClass::on_dsbT1_valueChanged(double arg1)
{
  if (arg1 == 0) {
    ui->dsbV1->setValue(0);
    return;
  }
  calVelocity(ui->dsbLongitud2->value(), arg1, v1);
}

void MainClass::on_dsbT2_valueChanged(double arg1)
{
  if (arg1 == 0) {
    ui->dsbV2->setValue(0);
    return;
  }
  calVelocity(ui->dsbLongitud2->value(), arg1, v2);
}

void MainClass::on_dsbT3_valueChanged(double arg1)
{
  if (arg1 == 0) {
    ui->dsbV3->setValue(0);
    return;
  }
  calVelocity(ui->dsbLongitud2->value(), arg1, v3);
}

void MainClass::on_dsb_T1_valueChanged(double arg1)
{
  if (arg1 == 0) {
    ui->dsb_V1->setValue(0);
    return;
  }
  calVelocity(ui->dsbLongitud2->value(), arg1, v1_c);
}

void MainClass::on_dsb_T2_valueChanged(double arg1)
{
  if (arg1 == 0) {
    ui->dsb_V2->setValue(0);
    return;
  }
  calVelocity(ui->dsbLongitud2->value(), arg1, v2_c);
}

void MainClass::on_dsb_T3_valueChanged(double arg1)
{
  if (arg1 == 0) {
    ui->dsb_V3->setValue(0);
    return;
  }
  calVelocity(ui->dsbLongitud2->value(), arg1, v3_c);
}

void MainClass::on_dsb_a1_valueChanged(double arg1)
{
  double res = 0;
  res = (arg1 / 3);
  ui->dsb_a1s->setValue(res);

  calAreaParcial(ui->dsb_a1s->value(), ui->dsb_h1->value(), opAParcial::Ap1);
  calAreaParcial(ui->dsb_a1s->value(), ui->dsb_h2->value(), opAParcial::Ap2);
  calAreaParcial(ui->dsb_a1s->value(), ui->dsb_h3->value(), opAParcial::Ap3);

  //calcular areas totales
  calAreaTotal(ui->dsbA1->value(), ui->dsb_A1->value(), MainClass::C_AreaTotal::At1);
  calAreaTotal(ui->dsbA2->value(), ui->dsb_A2->value(), MainClass::C_AreaTotal::At2);
  calAreaTotal(ui->dsbA3->value(), ui->dsb_A3->value(), MainClass::C_AreaTotal::At3);

  //calcular areas parciales
  calAreaParcial(ui->dsb_a1s->value(), ui->dsb_h1->value(), MainClass::opAParcial::Ap1);
  calAreaParcial(ui->dsb_a1s->value(), ui->dsb_h2->value(), MainClass::opAParcial::Ap2);
  calAreaParcial(ui->dsb_a1s->value(), ui->dsb_h3->value(), MainClass::opAParcial::Ap3);
  calAreaTotal(ui->dsbA1->value(), ui->dsb_A1->value(), MainClass::C_AreaTotal::At1);
  calAreaTotal(ui->dsbA2->value(), ui->dsb_A2->value(), MainClass::C_AreaTotal::At2);
  calAreaTotal(ui->dsbA3->value(), ui->dsb_A3->value(), MainClass::C_AreaTotal::At3);
}

void MainClass::on_dsb_a2_valueChanged(double arg1)
{
  double res = 0;
  res = (arg1 / 3);
  ui->dsb_a2s->setValue(res);

  calAreaParcial(ui->dsb_a2s->value(), ui->dsb_h1s->value(), opAParcial::Ap1_c);
  calAreaParcial(ui->dsb_a2s->value(), ui->dsb_h2s->value(), opAParcial::Ap2_c);
  calAreaParcial(ui->dsb_a2s->value(), ui->dsb_h3s->value(), opAParcial::Ap3_c);

  //calcular areas totales
  calAreaTotal(ui->dsbA1->value(), ui->dsb_A1->value(), MainClass::C_AreaTotal::At1);
  calAreaTotal(ui->dsbA2->value(), ui->dsb_A2->value(), MainClass::C_AreaTotal::At2);
  calAreaTotal(ui->dsbA3->value(), ui->dsb_A3->value(), MainClass::C_AreaTotal::At3);

  //calcular areas parciales
  calAreaParcial(ui->dsb_a1s->value(), ui->dsb_h1->value(), MainClass::opAParcial::Ap1);
  calAreaParcial(ui->dsb_a1s->value(), ui->dsb_h2->value(), MainClass::opAParcial::Ap2);
  calAreaParcial(ui->dsb_a1s->value(), ui->dsb_h3->value(), MainClass::opAParcial::Ap3);
  calAreaTotal(ui->dsbA1->value(), ui->dsb_A1->value(), MainClass::C_AreaTotal::At1);
  calAreaTotal(ui->dsbA2->value(), ui->dsb_A2->value(), MainClass::C_AreaTotal::At2);
  calAreaTotal(ui->dsbA3->value(), ui->dsb_A3->value(), MainClass::C_AreaTotal::At3);
}

void MainClass::on_dsb_h1_valueChanged(double arg1)
{
  calAreaParcial(ui->dsb_a1s->value(), arg1, opAParcial::Ap1);
}

void MainClass::on_dsb_h2_valueChanged(double arg1)
{
  calAreaParcial(ui->dsb_a1s->value(), arg1, opAParcial::Ap2);
}

void MainClass::on_dsb_h3_valueChanged(double arg1)
{
  calAreaParcial(ui->dsb_a1s->value(), arg1, opAParcial::Ap3);
}

void MainClass::on_dsb_h1s_valueChanged(double arg1)
{
  calAreaParcial(ui->dsb_a2s->value(), arg1, opAParcial::Ap1_c);
}

void MainClass::on_dsb_h2s_valueChanged(double arg1)
{
  calAreaParcial(ui->dsb_a2s->value(), arg1, opAParcial::Ap2_c);
}

void MainClass::on_dsb_h3s_valueChanged(double arg1)
{
  calAreaParcial(ui->dsb_a2s->value(), arg1, opAParcial::Ap3_c);
}

void MainClass::on_dsbV1_valueChanged(double arg1)
{
  //calcular velocidad total
  calVelocidadTotal(arg1, ui->dsb_V1->value(), C_VelocidadTotal::Vt1);
}

void MainClass::on_dsb_V1_valueChanged(double arg1)
{
  calVelocidadTotal(ui->dsbV1->value(), arg1, C_VelocidadTotal::Vt1);
}

void MainClass::on_dsbV2_valueChanged(double arg1)
{
  calVelocidadTotal(arg1, ui->dsb_V2->value(), C_VelocidadTotal::Vt2);
}

void MainClass::on_dsb_V2_valueChanged(double arg1)
{
  calVelocidadTotal(ui->dsbV2->value(), arg1, C_VelocidadTotal::Vt2);
}

void MainClass::on_dsbV3_valueChanged(double arg1)
{
  calVelocidadTotal(arg1, ui->dsb_V3->value(), C_VelocidadTotal::Vt3);
}

void MainClass::on_dsb_V3_valueChanged(double arg1)
{
  calVelocidadTotal(ui->dsb_V3->value(), arg1, C_VelocidadTotal::Vt3);
}

void MainClass::on_dsbA1_valueChanged(double arg1)
{
  calAreaTotal(arg1, ui->dsb_A1->value(), MainClass::C_AreaTotal::At1);
}

void MainClass::on_dsb_A1_valueChanged(double arg1)
{
  calAreaTotal(ui->dsbA1->value(), arg1, MainClass::C_AreaTotal::At1);
}

void MainClass::on_dsbA2_valueChanged(double arg1)
{
  calAreaTotal(arg1, ui->dsb_A2->value(), MainClass::C_AreaTotal::At2);
}

void MainClass::on_dsb_A2_valueChanged(double arg1)
{
  calAreaTotal(ui->dsbA2->value(), arg1, MainClass::C_AreaTotal::At2);
}

void MainClass::on_dsbA3_valueChanged(double arg1)
{
  calAreaTotal(arg1, ui->dsb_A3->value(), MainClass::C_AreaTotal::At3);
}

void MainClass::on_dsb_A3_valueChanged(double arg1)
{
  calAreaTotal(ui->dsbA3->value(), arg1, MainClass::C_AreaTotal::At3);
}

void MainClass::on_dsbTotalA1_valueChanged(double arg1)
{
  calQParcial(arg1, ui->dsbTotalV1->value(), MainClass::C_QParcial::Qp1);
}

void MainClass::on_dsbTotalV1_valueChanged(double arg1)
{
  calQParcial(ui->dsbTotalA1->value(), arg1, MainClass::C_QParcial::Qp1);
  calQMetrosSeg(ui->dsbQ1->value(), ui->dsbQ2->value(), ui->dsbQ3->value());
  calQLitrosSeg(ui->dsbResQMetSeg->value());
  calQMetrosDia(ui->dsbResQMetSeg->value());
}

void MainClass::on_dsbTotalA2_valueChanged(double arg1)
{
  calQParcial(arg1, ui->dsbTotalV2->value(), MainClass::C_QParcial::Qp2);
}

void MainClass::on_dsbTotalV2_valueChanged(double arg1)
{
  calQParcial(ui->dsbTotalA2->value(), arg1, MainClass::C_QParcial::Qp2);
  calQMetrosSeg(ui->dsbQ1->value(), ui->dsbQ2->value(), ui->dsbQ3->value());
  calQLitrosSeg(ui->dsbResQMetSeg->value());
  calQMetrosDia(ui->dsbResQMetSeg->value());
}

void MainClass::on_dsbTotalA3_valueChanged(double arg1)
{
  calQParcial(arg1, ui->dsbTotalV3->value(), MainClass::C_QParcial::Qp3);
}

void MainClass::on_dsbTotalV3_valueChanged(double arg1)
{
  calQParcial(ui->dsbTotalA3->value(), arg1, MainClass::C_QParcial::Qp3);
  calQMetrosSeg(ui->dsbQ1->value(), ui->dsbQ2->value(), ui->dsbQ3->value());
  calQLitrosSeg(ui->dsbResQMetSeg->value());
  calQMetrosDia(ui->dsbResQMetSeg->value());
}

void MainClass::on_dsbQ1_valueChanged(double arg1)
{
  //calcular caudal total, de los caudales
  calQMetrosSeg(arg1, ui->dsbQ2->value(), ui->dsbQ3->value());
  calQLitrosSeg(ui->dsbResQMetSeg->value());
  calQMetrosDia(ui->dsbResQMetSeg->value());
}

void MainClass::on_dsbQ2_valueChanged(double arg1)
{
  //calcular caudal total, de los caudales
  calQMetrosSeg(ui->dsbQ1->value(), arg1, ui->dsbQ3->value());
  calQLitrosSeg(ui->dsbResQMetSeg->value());
  calQMetrosDia(ui->dsbResQMetSeg->value());
}

void MainClass::on_dsbQ3_valueChanged(double arg1)
{
  //calcular caudal total, de los caudales
  calQMetrosSeg(ui->dsbQ1->value(), ui->dsbQ2->value(), arg1);
  calQLitrosSeg(ui->dsbResQMetSeg->value());
  calQMetrosDia(ui->dsbResQMetSeg->value());
}

//limpiar controles del panel caudal flotador
void MainClass::on_pushButton_clicked()
{
  ui->dsbLongitud1->setValue(0);
  ui->dsbT1->setValue(0);
  ui->dsbT2->setValue(0);
  ui->dsbT3->setValue(0);
  ui->dsbV1->setValue(0);
  ui->dsbV2->setValue(0);
  ui->dsbV3->setValue(0);
  ui->dsb_a1->setValue(0);
  ui->dsb_a1s->setValue(0);
  ui->dsb_h1->setValue(0);
  ui->dsb_h2->setValue(0);
  ui->dsb_h3->setValue(0);
  ui->dsbA1->setValue(0);
  ui->dsbA2->setValue(0);
  ui->dsbA3->setValue(0);
  ui->dsb_T1->setValue(0);
  ui->dsb_T2->setValue(0);
  ui->dsb_T3->setValue(0);
  ui->dsb_V1->setValue(0);
  ui->dsb_V2->setValue(0);
  ui->dsb_V3->setValue(0);
  ui->dsb_a2->setValue(0);
  ui->dsb_a2s->setValue(0);
  ui->dsb_h1s->setValue(0);
  ui->dsb_h2s->setValue(0);
  ui->dsb_h3s->setValue(0);
  ui->dsb_A1->setValue(0);
  ui->dsb_A2->setValue(0);
  ui->dsb_A3->setValue(0);
  ui->dsbTotalA1->setValue(0);
  ui->dsbTotalA2->setValue(0);
  ui->dsbTotalA3->setValue(0);
  ui->dsbTotalV1->setValue(0);
  ui->dsbTotalV2->setValue(0);
  ui->dsbTotalV3->setValue(0);
  ui->dsbQ1->setValue(0);
  ui->dsbQ2->setValue(0);
  ui->dsbQ3->setValue(0);
  ui->dsbResQMetSeg->setValue(0);
  ui->dsbResQLitSeg->setValue(0);
  ui->dsbResQMetDia->setValue(0);
  ui->dsbLongitud1->setFocus(Qt::OtherFocusReason);
}

void MainClass::on_brnAgregar_clicked()
{
  if (calculate == true)
    return;
  if (ui->dsbSecciones->value() == 0) {
    QMessageBox::warning(this,
                         qApp->applicationName(),
                         "El numero de segmentos debe ser mayor a cero.");
    ui->dsbSecciones->setFocus(Qt::OtherFocusReason);
    ui->dsbSecciones->selectAll();
    return;
  }
  if (ui->tableWidget_4->rowCount() != 0) {
    return;
  }
  setData(ui->dsbSecciones->value());
}
void MainClass::setData(int _rowCount)
{
  for (int i = 0; i <= _rowCount; i++) {
    int rowCount = ui->tableWidget_4->rowCount();
    //  ui->tableWidget_4->setRowCount(rowCount);
    //primera columna
    ui->tableWidget_4->insertRow(rowCount);
    //  qDebug()<<rowCount;
    QTableWidgetItem *item = new QTableWidgetItem(QString("v %1").arg(v));
    ui->tableWidget_4->setItem(rowCount, V, item);
    item->setFlags(item->flags() ^ Qt::ItemIsEnabled);

    //segunda columna columna
    //  ui->tableWidget_4->insertRow(rowCount);

    QTableWidgetItem *item1 = new QTableWidgetItem(0);
    ui->tableWidget_4->setItem(rowCount, Velocidad, item1);
    ui->tableWidget_4->setCellWidget(rowCount, Velocidad, new SWDoubleSpinBox(this));
    QDoubleSpinBox *sb = qobject_cast<QDoubleSpinBox *>(
      ui->tableWidget_4->cellWidget(rowCount, Velocidad));
    sb->setValue(0);
    //  qDebug()<<item1->data(Qt::DisplayRole).toString();
    //tercera columna columna
    //  ui->tableWidget_4->insertRow(rowCount);
    QTableWidgetItem *item2 = new QTableWidgetItem(QString("h %1").arg(h));
    ui->tableWidget_4->setItem(rowCount, H, item2);
    item2->setFlags(item2->flags() & (~Qt::ItemIsEnabled));
    //cuarta columna columna
    //  ui->tableWidget_4->insertRow(rowCount);
    QTableWidgetItem *item3 = new QTableWidgetItem(0);
    ui->tableWidget_4->setItem(rowCount, Profundidad, item3);
    ui->tableWidget_4->setCellWidget(rowCount, Profundidad, new SWDoubleSpinBox(this));
    QDoubleSpinBox *sb2 = qobject_cast<QDoubleSpinBox *>(
      ui->tableWidget_4->cellWidget(rowCount, Profundidad));
    sb2->setValue(0);
    v++;
    h++;
  }
}

void MainClass::setDataRes()
{
  for (int i = 0; i < ui->tableWidget_4->rowCount() - 1; i++) {
    //calcular m3/s

    int rowCount = ui->tableWidget_5->rowCount();
    ui->tableWidget_5->insertRow(rowCount);
    //      QTableWidgetItem *item=new QTableWidgetItem();
    ui->tableWidget_5->setItem(i, 0, new QTableWidgetItem(QString("Q %1").arg(i + 1)));
    //      if(i==ui->tableWidget_4->rowCount()){
    //           ui->tableWidget_5->setItem(i,0,new QTableWidgetItem(QString("te")));
    //           break;
    //          }
  }
  //  calcularTotales();
  //  qDebug()<<ui->tableWidget_4->rowCount();
}

void MainClass::calcularTotales()
{
  double res, value1, value2, value3, value4 = 0;

  for (int i = 0; i < ui->tableWidget_4->rowCount() - 1; i++) {
    QDoubleSpinBox *spb1 = qobject_cast<QDoubleSpinBox *>(ui->tableWidget_4->cellWidget(i, 1));
    value1 = spb1->value();
    QDoubleSpinBox *spb2 = qobject_cast<QDoubleSpinBox *>(
      ui->tableWidget_4->cellWidget(i + 1, 1));
    value2 = spb2->value();
    QDoubleSpinBox *spb3 = qobject_cast<QDoubleSpinBox *>(ui->tableWidget_4->cellWidget(i, 3));
    value3 = spb3->value();
    QDoubleSpinBox *spb4 = qobject_cast<QDoubleSpinBox *>(
      ui->tableWidget_4->cellWidget(i + 1, 3));
    value4 = spb4->value();
    res = (((value1 + value2) / 2) * (ui->dsbMedSegmento->value() * (value3 + value4) / 2))
          / 10000;
    ui->tableWidget_5->setItem(i, 1, new QTableWidgetItem(QString::number(res)));
  }
  double result = 0;
  for (int i = 0; i < ui->tableWidget_5->rowCount(); i++) {
    result = result + ui->tableWidget_5->item(i, 1)->data(Qt::DisplayRole).toDouble();
    //      qDebug()<<ui->tableWidget_5->item(i,1)->data(Qt::DisplayRole);
  }
  ui->dsbTotalMetSeg_1->setValue(result);
  //  qDebug()<<result;
  ui->dsbTotalLitSeg_1->setValue((ui->dsbTotalMetSeg_1->value() * 1000));
  ui->dsbTotalMetDia_1->setValue((ui->dsbTotalMetSeg_1->value() * 3600 * 24));
  calculate = true;
}

void MainClass::limpiarCtrCorr()
{
  ui->dsbAncho->setValue(0);
  ui->dsbSecciones->setValue(0);
  ui->dsbMedSegmento->setValue(0);
  //  ui->tableWidget_4->clear();
  //  ui->tableWidget_5->clear();
  if (ui->tableWidget_4->rowCount() != -1) {
    for (int i = ui->tableWidget_4->rowCount(); i >= 0; i--) {
      ui->tableWidget_4->removeRow(i);
    }
  }
  if (ui->tableWidget_5->rowCount() != -1) {
    for (int i = ui->tableWidget_5->rowCount(); i >= 0; i--) {
      ui->tableWidget_5->removeRow(i);
    }
  }
  ui->dsbTotalMetDia_1->setValue(0);
  ui->dsbTotalMetSeg_1->setValue(0);
  ui->dsbTotalLitSeg_1->setValue(0);

  v = 0;
  h = 0;

  ui->dsbAncho->setFocus(Qt::OtherFocusReason);
}

bool MainClass::validarDatos()
{
  if (ui->dsbAncho->value() == 0 || ui->dsbSecciones->value() == 0
      || ui->dsbMedSegmento->value() == 0) {
    QMessageBox::warning(this, qApp->applicationName(), "ingrese todos los datos.");
    return false;
  }

  for (int i = 0; i < ui->tableWidget_4->rowCount() - 2; i++) {
    QDoubleSpinBox *spb1 = qobject_cast<QDoubleSpinBox *>(
      ui->tableWidget_4->cellWidget(i + 1, 1));
    QDoubleSpinBox *spb2 = qobject_cast<QDoubleSpinBox *>(
      ui->tableWidget_4->cellWidget(i + 1, 3));
    if (spb1->value() == 0 || spb2->value() == 0) {
      QMessageBox::warning(this, qApp->applicationName(), "ingrese todos los datos.");
      return false;
    }
  }
  return true;
}

void MainClass::on_pushButton_6_clicked()
{
  //  ui->tableWidget_4->setCurrentIndex()
  if (ui->tableWidget_4->currentRow() != -1) {
    ui->tableWidget_4->removeRow(ui->tableWidget_4->currentRow());
    v--;
    h--;
    //      calculate=true;
  }
  if (ui->tableWidget_4->currentRow() == -1) {
    if (ui->tableWidget_5->rowCount() != -1) {
      for (int i = ui->tableWidget_5->rowCount(); i >= 0; i--) {
        ui->tableWidget_5->removeRow(i);
      }
    }
  }
  ui->dsbTotalMetDia_1->setValue(0);
  ui->dsbTotalMetSeg_1->setValue(0);
  ui->dsbTotalLitSeg_1->setValue(0);
  ui->dsbSecciones->setValue(ui->tableWidget_4->rowCount() - 1);
  calculate = false;
}

void MainClass::on_pushButton_5_clicked()
{
  if (!validarDatos())
    return;
  if (!calculate && ui->tableWidget_4->rowCount() != 0) {
    setDataRes();
    calcularTotales();
  }
  //  ui->dsbTotalMetSeg_1->setValue()
  //  qDebug()<<ui->tableWidget_5->item(0,1)->data(Qt::DisplayRole);
}

void MainClass::on_pushButton_7_clicked()
{
  limpiarCtrCorr();
  calculate = false;
}

void MainClass::on_comboBox_activated(int index)
{
  setTheme(index);
}
void MainClass::setTheme(int index)
{
  //  QEasySettings::Style style=static_cast<QEasySettings::Style>(index);
  //  QEasySettings::setStyle(style);

  QString styleSheet;
  styleSheet
    = "QDoubleSpinBox#dsbLongitud2,#dsbV1,#dsbV2,#dsbV3,#dsb_a1s,#dsbA1,#dsbA2,"
      "#dsbA3,#dsb_V1,#dsb_V2,#dsb_V3,#dsb_a2s,#dsb_A1,#dsb_A2,#dsb_A3,#dsbQ1,#dsbQ2,#dsbQ3,"
      "#dsbTotalA1,#dsbTotalA2,#dsbTotalA3,#dsbTotalV1,#dsbTotalV2,#dsbTotalV3,#dsbResQMetSeg"
      ",#dsbResQLitSeg,#dsbResQMetDia,#dsbPromedio,#dspTiempoPromedio,#qMetrosCubSeg,#"
      "qLitrosSeg,"
      "#qMetrosCubDia,#dsbTotalMetSeg_1,#dsbTotalLitSeg_1,#dsbTotalMetDia_1{"
      "background-color: #262626;"
      "color: rgb(249, 38, 114);"
      "}";
  //setStyleSheet(styleSheet);
  if (index == 0) {
    //      qDebug()<<index;

    QEasySettings::setStyle(QEasySettings::Style::lightFusion);
    setStyleSheet(styleSheet);
    theme = 0;
  } else {
    QEasySettings::setStyle(QEasySettings::Style::darkFusion);
    setStyleSheet(styleSheet);
    theme = 1;
    //      qDebug()<<index;
  }
}

void MainClass::showDialog()
{
  DlgAcercaDe *acercade = new DlgAcercaDe(theme, this);
  acercade->setWindowTitle(qApp->applicationName().append(" - Acerca de"));
  acercade->exec();
}
