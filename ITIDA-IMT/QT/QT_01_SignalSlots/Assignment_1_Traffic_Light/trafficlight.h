#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H
#include <QObject>

enum class State
{
	Red,
	Yellow,
	Green,
	INVALID
};

class TrafficLight : public QObject
{
	Q_OBJECT
public:
	explicit TrafficLight(QObject* parent = nullptr);

	bool HandleInput(int& input);

	void run();

	void test_ChangeState();

signals:
	// will be send to trafficcontrol
	bool ChangeState(State currentState);

private:
	State currentState;
};

#endif // TRAFFICLIGHT_H
