#include "destination.h"
#include <QDebug>
Destination::Destination(QObject *parent)
    : QObject{parent}
{}

void Destination::mySignal(QString str)
{
    qDebug()<<str;
}
