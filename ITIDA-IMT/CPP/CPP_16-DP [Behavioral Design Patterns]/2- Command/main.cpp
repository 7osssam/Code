#include <iostream>
#include <memory>
#include <string>

// Command Pattern
// 1. Command
// 2. ConcreteCommand
// 3. Invoker
// 4. Receiver

// Command Interface
class Command
{
public:
	virtual void execute() = 0;
};

// Receiver Classes
class Light
{
public:
	void turnOn()
	{
		std::cout << "Light is turned on.\n";
	}

	void turnOff()
	{
		std::cout << "Light is turned off.\n";
	}
};

class Thermostat
{
public:
	void setTemperature(int temperature)
	{
		std::cout << "Thermostat temperature set to " << temperature << " degrees Celsius.\n";
	}
};

class Speaker
{
public:
	void playMusic(const std::string& music)
	{
		std::cout << "Playing music: " << music << "\n";
	}
};

// Concrete Command Classes
class LightOnCommand : public Command
{
private:
	std::shared_ptr<Light> light;

public:
	LightOnCommand(std::shared_ptr<Light> light) : light(light)
	{
	}

	void execute() override
	{
		light->turnOn();
	}
};

class LightOffCommand : public Command
{
private:
	std::shared_ptr<Light> light;

public:
	LightOffCommand(std::shared_ptr<Light> light) : light(light)
	{
	}

	void execute() override
	{
		light->turnOff();
	}
};

class SetTemperatureCommand : public Command
{
private:
	std::shared_ptr<Thermostat> thermostat;
	int							temperature;

public:
	SetTemperatureCommand(std::shared_ptr<Thermostat> thermostat, int temp) :
		thermostat(thermostat), temperature(temp)
	{
	}

	void execute() override
	{
		thermostat->setTemperature(temperature);
	}
};

class PlayMusicCommand : public Command
{
private:
	std::shared_ptr<Speaker> speaker;
	std::string				 music;

public:
	PlayMusicCommand(std::shared_ptr<Speaker> speaker, const std::string& music) :
		speaker(speaker), music(music)
	{
	}

	void execute() override
	{
		speaker->playMusic(music);
	}
};

// Invoker Class
class RemoteControl
{
private:
	std::shared_ptr<Command> command;

public:
	void setCommand(std::shared_ptr<Command> command)
	{
		this->command = command;
	}

	void pressButton()
	{
		if (command)
		{
			command->execute();
		}
	}
};

int main()
{
	auto light = std::make_shared<Light>();
	auto thermostat = std::make_shared<Thermostat>();
	auto speaker = std::make_shared<Speaker>();

	auto lightOnCommand = std::make_shared<LightOnCommand>(light);
	auto lightOffCommand = std::make_shared<LightOffCommand>(light);
	auto setTemperatureCommand = std::make_shared<SetTemperatureCommand>(thermostat, -5);
	auto playMusicCommand = std::make_shared<PlayMusicCommand>(speaker, "Marwan Palo");

	RemoteControl remoteControl;

	remoteControl.setCommand(lightOnCommand);
	remoteControl.pressButton();

	remoteControl.setCommand(lightOffCommand);
	remoteControl.pressButton();

	remoteControl.setCommand(setTemperatureCommand);
	remoteControl.pressButton();

	remoteControl.setCommand(playMusicCommand);
	remoteControl.pressButton();

	return 0;
}
