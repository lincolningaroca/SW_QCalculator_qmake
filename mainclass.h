#ifndef MAINCLASS_H
#define MAINCLASS_H

#include <QWidget>
#include "swdoublespinbox.h"
#include <QMouseEvent>
#include "qeasysettings.hpp"

namespace Ui {
class MainClass;
}

class MainClass : public QWidget
{
  Q_OBJECT

public:

  explicit MainClass(QWidget *parent = nullptr);
  ~MainClass();
  enum opV{v1,v2,v3,v1_c,v2_c,v3_c};
  enum class opAParcial{Ap1,Ap2,Ap3,Ap1_c,Ap2_c,Ap3_c};
  enum class  C_AreaTotal{At1,At2,At3};
  enum class  C_VelocidadTotal{Vt1,Vt2,Vt3};
  enum class  C_QParcial{Qp1,Qp2,Qp3};
  //enumeracion para las columnas del QTableWidget caudal correntometro
  enum ColNames{V,Velocidad,H,Profundidad};

private slots:
  void on_btnLimpiar_clicked();
  void on_btnVolumetrico_clicked();
  void on_btnFlotador_clicked();
  void on_btnCorrectometro_clicked();
  void on_dspVelocidad1_valueChanged(double arg1);
  void on_dspVelocidad2_valueChanged(double arg1);
  void on_dspVelocidad3_valueChanged(double arg1);
  void on_dspTiempo1_valueChanged(double arg1);
  void on_dspTiempo2_valueChanged(double arg1);
  void on_dspTiempo3_valueChanged(double arg1);
  void on_dsbLongitud1_valueChanged(double arg1);
  void on_dsbT1_valueChanged(double arg1);
  void on_dsbT2_valueChanged(double arg1);
  void on_dsbT3_valueChanged(double arg1);
  void on_dsb_T1_valueChanged(double arg1);
  void on_dsb_T2_valueChanged(double arg1);
  void on_dsb_T3_valueChanged(double arg1);
  void on_dsb_a1_valueChanged(double arg1);
  void on_dsb_a2_valueChanged(double arg1);
  void on_dsb_h1_valueChanged(double arg1);
  void on_dsb_h2_valueChanged(double arg1);
  void on_dsb_h3_valueChanged(double arg1);
  void on_dsb_h1s_valueChanged(double arg1);
  void on_dsb_h2s_valueChanged(double arg1);
  void on_dsb_h3s_valueChanged(double arg1);
  void on_dsbV1_valueChanged(double arg1);
  void on_dsb_V1_valueChanged(double arg1);
  void on_dsbV2_valueChanged(double arg1);
  void on_dsb_V2_valueChanged(double arg1);
  void on_dsbV3_valueChanged(double arg1);
  void on_dsb_V3_valueChanged(double arg1);
  void on_dsbA1_valueChanged(double arg1);
  void on_dsb_A1_valueChanged(double arg1);
  void on_dsbA2_valueChanged(double arg1);
  void on_dsb_A2_valueChanged(double arg1);
  void on_dsbA3_valueChanged(double arg1);
  void on_dsb_A3_valueChanged(double arg1);
  void on_dsbTotalA1_valueChanged(double arg1);
  void on_dsbTotalV1_valueChanged(double arg1);
  void on_dsbTotalA2_valueChanged(double arg1);
  void on_dsbTotalV2_valueChanged(double arg1);
  void on_dsbTotalA3_valueChanged(double arg1);
  void on_dsbTotalV3_valueChanged(double arg1);
  void on_dsbQ1_valueChanged(double arg1);
  void on_dsbQ2_valueChanged(double arg1);
  void on_dsbQ3_valueChanged(double arg1);
  void on_pushButton_clicked();
  //  void on_pushButton_4_clicked();

  void on_brnAgregar_clicked();
  void on_pushButton_6_clicked();
  //  void on_checkBox_stateChanged(int arg1);
  void on_pushButton_5_clicked();
  void on_pushButton_7_clicked();

  void on_comboBox_activated(int index);

private:
  Ui::MainClass *ui;
  /**********************************************************************/
  //metodos, funciones y variables definidos por el programador del panel caudal volumetrico
  void speedAverage(QList<double> v);
  void timeAverage(QList<double> v);
  void qLitros_Segundos(double vProm,double tProm);
  void qMetCub_segundo(double pLitrosSeg);
  void qMetCub_Dia(double qMetCubSeg);
  void setUpSpinBox();
  void setUpDataCorrentometro();
  void setUpDataResultados();
  void setData(int _rowCount);
  void setDataRes();
  void calcularTotales();
  void limpiarCtrCorr();
  bool validarDatos();
  //metodo que carga las configuraciones iniciales del form pricipal
  void loadWindow();
  void lblAbout();
  void setTheme(int index);
  void showDialog();
  int theme=0;

  uint v=0;
  uint h=0;
  bool calculate=false;


  /**********************************************************************/
  /**********************************************************************/
  //metodos, funciones y variables definidos por el programador del panel caudal flotador
  void setUpSpinBoxF();
  void calVelocity(double val1, double val2, opV op);
  void calAreaParcial(double val1, double val2, opAParcial aP);
  void calAreaTotal(double val1, double val2, C_AreaTotal aT);
  void calVelocidadTotal(double val1, double val2, C_VelocidadTotal vT);
  void calQParcial(double val1, double val2, C_QParcial qP);
  void calQMetrosSeg(double val1, double val2, double val3);
  void calQLitrosSeg(double val1);
  void calQMetrosDia(double val1);
  //


  // QPaintDevice interface
  //public:
  //  virtual QPaintEngine *paintEngine() const override;
  //  // QObject interface
  //  virtual bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // MAINCLASS_H
