#include <QCoreApplication>
#include <QTextStream>
#include "trafficlight.h"
#include "trafficcontrol.h"
int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	TrafficLight   mytrafficLight;
	TrafficControl mytrafficControl;

	// connect signal from trafficlight to slot from trafficcontrol
	QObject::connect(&mytrafficLight, &TrafficLight::ChangeState, &mytrafficControl,
					 &TrafficControl::ChangeState);

	qInfo() << "Enter command:\n";
	qInfo() << "1. RED\n";
	qInfo() << "2. YELLOW\n";
	qInfo() << "3. GREEN\n";
	// get input from user
	QTextStream input(stdin);
	int			userInput;
	input >> userInput;

	mytrafficLight.HandleInput(userInput);

	mytrafficLight.run();

	return a.exec();
}
