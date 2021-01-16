#ifndef SWDOUBLESPINBOX_H
#define SWDOUBLESPINBOX_H

#include <QDoubleSpinBox>
#include <QObject>

class SWDoubleSpinBox : public QDoubleSpinBox
{
  Q_OBJECT
public:
  SWDoubleSpinBox(QWidget *parent);

  // QPaintDevice interface
public:
  virtual QPaintEngine *paintEngine() const override;

  // QWidget interface
protected:
  virtual void focusInEvent(QFocusEvent *event) override;
};

#endif // SWDOUBLESPINBOX_H
