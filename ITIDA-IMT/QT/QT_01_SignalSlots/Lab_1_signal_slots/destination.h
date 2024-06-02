#ifndef DESTINATION_H
#define DESTINATION_H

#include <QObject>

class Destination : public QObject
{
    Q_OBJECT
public:
    explicit Destination(QObject *parent = nullptr);

signals:

public slots:
      void mySignal(QString str);
};

#endif // DESTINATION_H
