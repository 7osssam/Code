#ifndef SOURSE_H
#define SOURSE_H

#include <QObject>

class Sourse : public QObject
{
    Q_OBJECT
public:
    explicit Sourse(QObject *parent = nullptr);

    void test();

signals:
    void mySignal(QString str);
};

#endif // SOURSE_H
