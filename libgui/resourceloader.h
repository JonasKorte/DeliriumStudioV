#pragma once
#include "api.h"
#include <iostream>
#include <Qt>
#include <QFile>
#include <QString>
#include <QIODevice>
#include <QTextStream>

class EXPORTED ResourceLoader
{
public:
    static QString Load(const char* path);
};