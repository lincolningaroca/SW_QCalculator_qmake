#include "mainclass.h"

#include <QApplication>
#include <QStyleFactory>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  a.setApplicationName("SW_QCalulator ¡BETA_1!");
//  a.setApplicationDisplayName();
  a.setApplicationVersion("1.0");
  a.setOrganizationName("SWSystem's");

//  a.setStyle(QStyleFactory::create("Fusion"));
  MainClass w;
  w.setWindowTitle(qApp->applicationName());
  w.show();
  return a.exec();
}
