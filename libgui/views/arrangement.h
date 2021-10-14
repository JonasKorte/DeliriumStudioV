#pragma once
#include "api.h"
#include <QGraphicsView>

enum ClipType
{
    CT_AUDIO,
    CT_MIDI
};

class EXPORTED ArrangementView : public QGraphicsView
{
public:
    ArrangementView(QWidget* parent);
};