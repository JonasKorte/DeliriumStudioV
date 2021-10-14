#include "toolbar.h"

Toolbar::Toolbar(QWidget* parent) : QToolBar(parent)
{
    this->m_defaultSingleStep = 1.0;
    this->m_smallSingleStep = 0.1;

    this->m_bpmWidget = new QDoubleSpinBox(this);

    this->m_bpmWidget->setRange(10.0, 255.0);
    this->m_bpmWidget->setDecimals(1);
    this->m_bpmWidget->setValue(120.00);
    this->m_bpmWidget->setSingleStep(this->m_defaultSingleStep);

    this->addWidget(this->m_bpmWidget);
}

Toolbar::~Toolbar()
{
    delete (this->m_bpmWidget);
}