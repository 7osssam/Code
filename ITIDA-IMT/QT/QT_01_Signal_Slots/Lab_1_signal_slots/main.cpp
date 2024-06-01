#include <QCoreApplication>
#include "sourse.h"
#include "destination.h"
int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Sourse mySourse;
	Destination myDestination;

	QObject::connect(&mySourse, &Sourse::mySignal, &myDestination, &Destination::mySignal);

	mySourse.test();

	return a.exec();
}
