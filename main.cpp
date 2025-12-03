#include <QApplication>
#include <QFile>
#include <QDebug>
#include "WelcomeWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFile file("welcome.qss");
    if(file.open(QFile::ReadOnly)) {
        QString style = QString::fromUtf8(file.readAll());
        app.setStyleSheet(style);
    }

    WelcomeWindow welcome;
    welcome.show();

    return app.exec();
}
