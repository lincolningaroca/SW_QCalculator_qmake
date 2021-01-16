#include "swdoublespinbox.h"
#include <QFocusEvent>

SWDoubleSpinBox::SWDoubleSpinBox(QWidget *parent):
  QDoubleSpinBox(parent)
{

}

QPaintEngine *SWDoubleSpinBox::paintEngine() const
{
  return QDoubleSpinBox::paintEngine();

}

void SWDoubleSpinBox::focusInEvent(QFocusEvent *event)
{
  QDoubleSpinBox::focusInEvent(event);
  selectAll();
  event->accept();
}

