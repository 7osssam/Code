#ifndef TRAFFICCONTROL_H
#define TRAFFICCONTROL_H

#include <QObject>
#include "trafficlight.h"
class TrafficControl : public QObject
{
	Q_OBJECT
public:
	explicit TrafficControl(QObject* parent = nullptr);

signals:

public slots:
	void ChangeState(State currentState);
};

#endif // TRAFFICCONTROL_H
