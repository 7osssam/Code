#include "trafficlight.h"
#include <QDebug>
#include <QTextStream>

TrafficLight::TrafficLight(QObject *parent)
	: QObject{parent}, currentState{State::Red}
{
	// connect(this, &TrafficLight::ChangeState, );
}

bool TrafficLight::HandleInput(int &input)
{


	if (input < 1 || input > 3)
	{
		qCritical() << "Invalid input!";
		currentState = State::INVALID;
		return false;
	}

	if (input == 1)
	{
		currentState = State::Red;
	}
	else if (input == 2)
	{
		currentState = State::Yellow;
	}
	else if (input == 3)
	{
		currentState = State::Green;
	}

	return true;
}

void TrafficLight::run()
{
	emit ChangeState(currentState);
}

void TrafficLight::test_ChangeState()
{
}
