#pragma once
#include "api.h"
#include <QToolBar>
#include <QDoubleSpinBox>

class EXPORTED Toolbar : public QToolBar
{
public:
    Toolbar(QWidget* parent);
    ~Toolbar();

private:
    QDoubleSpinBox* m_bpmWidget;

    double m_defaultSingleStep;
    double m_smallSingleStep;
};