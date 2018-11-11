#include <QCoreApplication>
#include <QDebug>
#include <QSerialPort>

#include <stdlib.h>

#include "LinuxConstants.h"
#include "LinuxFunctions.h"

void addGetter() {
    using namespace Key;

//    X11::downKey(Alt);
//    X11::downKey(Enter);
//    X11::upKey(Enter);
//    X11::upKey(Alt);

//    X11::downKey(Down);
//    X11::upKey(Down);

//    X11::downKey(Enter);
//    X11::upKey(Enter);

    X11::downKey(Left);
    X11::upKey(Left);

    system("kdialog --passivepopup 'Добавлен геттер/сеттер' 5");
}

void pressLeft() {
    using namespace Key;
//    X11::downKey(Left);
//    X11::upKey(Left);
    X11::downKey(Control);
    X11::downKey(C);
    X11::upKey(C);
    X11::upKey(Control);
}

void pressMiddle() {
    using namespace Key;
//    X11::downKey(Space);
//    X11::upKey(Space);
    X11::downKey(Control);
    X11::downKey(V);
    X11::upKey(V);
    X11::upKey(Control);
}

void pressRight() {
    using namespace Key;
//    X11::downKey(Right);
//    X11::upKey(Right);
    X11::downKey(Control);
    X11::downKey(S);
    X11::upKey(S);
    X11::upKey(Control);
}

void handleByteFromDevice(char byte) {
    switch (byte) {
//    case 'g':
//        addGetter();
//        break;
    case 'l':
        pressLeft();
        break;
    case 'm':
        pressMiddle();
        break;
    case 'r':
        pressRight();
        break;
    }
}

class C {
    int x;
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    X11::openDisplay();

    QSerialPort port;
    port.setPortName("/dev/ttyUSB0");
    port.setBaudRate(QSerialPort::Baud115200);
    if (!port.open(QIODevice::ReadOnly))
        qCritical() << "Unable to open port" << port.portName();

    QObject::connect(&port, &QSerialPort::readyRead, [&] {
        QByteArray bytes = port.readAll();
        for (int byteNumber = 0; byteNumber < bytes.length(); ++ byteNumber) {
            char byte = bytes.at(byteNumber);
            handleByteFromDevice(byte);
        }
    });

    return a.exec();
}
