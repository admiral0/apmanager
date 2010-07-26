#include <QtGui/QApplication>
#include "apmanager.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    apmanager foo;
    foo.show();
    return app.exec();
}
