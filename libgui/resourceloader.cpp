#include "resourceloader.h"

QString ResourceLoader::Load(const char* path)
{
    QFile styleSheet(path);
    if (styleSheet.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        QTextStream in(&styleSheet);

        QString data = "";

        while (!in.atEnd())
        {
            QString line = in.readLine();

            data.append(line);
            data.append(" ");
        }

        return data;
    }
    else
    {
        std::cerr << "Failed to load stylesheet at " << path << std::endl;

        return "";
    }
}