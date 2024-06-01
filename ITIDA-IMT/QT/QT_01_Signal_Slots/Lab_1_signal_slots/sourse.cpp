#include "sourse.h"

Sourse::Sourse(QObject *parent)
	: QObject{parent}
{
}

void Sourse::test()
{
	emit mySignal("Hello From Source");
}
