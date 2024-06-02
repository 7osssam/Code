#include "trafficcontrol.h"
#include <QDebug>
TrafficControl::TrafficControl(QObject *parent)
	: QObject{parent}
{
}

void TrafficControl::ChangeState(State currentState)
{
	switch (currentState)
	{
	case State::Red:
		qInfo() << "STOP!";
		break;
	case State::Yellow:
		qInfo() << "Prepare to stop!";
		break;
	case State::Green:
		qInfo() << "Go!";
		break;
	case State::INVALID:
		qCritical() << "Invalid state!";
		break;
	}
}
