#include <QCoreApplication>
#include "QDebug"
#include "backend.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Backend *temp = new Backend();

    return a.exec();
}
