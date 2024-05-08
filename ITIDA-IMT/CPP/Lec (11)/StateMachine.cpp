#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cassert>

// states
enum class State
{
	Play,
	Pause,
	Stop
};

// map to store state strings ( for display functions )
std::map<State, std::string> stateStrings = {
	{State::Play, "Play"}, {State::Pause, "Pause"}, {State::Stop, "Stop"}};

// Map to store valid transitions {State,{vectors of valid transitions}}
std::map<State, std::vector<State>> transitions = {{State::Play, {State::Pause, State::Stop}},
												   {State::Pause, {State::Play, State::Stop}},
												   {State::Stop, {State::Play}}};

bool ChangeState(State currentState, State nextState)
{
	// search for nextState in the vector of valid transitions for currentState in the map
	if (std::find(transitions[currentState].begin(), transitions[currentState].end(), nextState) !=
		transitions[currentState].end())
	{
		return true;
	}
	return false;
}

void DisplayCurrentState(State currentState)
{
	std::cout << "=====================================\n";
	std::cout << "	  Current state: " << stateStrings[currentState] << std::endl;
	std::cout << "=====================================\n";
}

bool HandleInput(int& input)
{
	std::cout << "Enter command:\n";
	std::cout << "1. Play\n";
	std::cout << "2. Pause\n";
	std::cout << "3. Stop\n";
	std::cin >> input;

	if (input >= 1 && input <= 3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//@unit test for ChangeState function
// testing all valid and invalid transitions
void test_ChangeState()
{
	// test variables
	State currentState{};
	State nextState{};

	// testing all valid transitions
	// Play -> Pause & Play -> Stop
	currentState = State::Play;
	nextState = State::Pause;
	assert(ChangeState(currentState, nextState) == true);
	nextState = State::Stop;
	assert(ChangeState(currentState, nextState) == true);

	// Pause -> Play & Pause -> Stop
	currentState = State::Pause;
	nextState = State::Play;
	assert(ChangeState(currentState, nextState) == true);
	nextState = State::Stop;
	assert(ChangeState(currentState, nextState) == true);

	// Stop -> Play
	currentState = State::Stop;
	nextState = State::Play;
	assert(ChangeState(currentState, nextState) == true);

	// testing invalid transitions
	currentState = State::Play;
	nextState = State::Play;
	assert(ChangeState(currentState, nextState) == false);

	currentState = State::Pause;
	nextState = State::Pause;
	assert(ChangeState(currentState, nextState) == false);

	currentState = State::Stop;
	nextState = State::Stop;
	assert(ChangeState(currentState, nextState) == false);

	currentState = State::Stop;
	nextState = State::Pause;
	assert(ChangeState(currentState, nextState) == false);

	std::cout << "===== All tests passed =====\n";
}

int main()
{
	test_ChangeState();
	State currentState = State::Stop;
	int	  input{};

	while (true)
	{
		DisplayCurrentState(currentState);

		if (HandleInput(input))
		{
			State nextState;
			switch (input)
			{
				case 1:
					nextState = State::Play;
					break;
				case 2:
					nextState = State::Pause;
					break;
				case 3:
					nextState = State::Stop;
					break;
			}

			if (ChangeState(currentState, nextState))
			{
				std::cout << "Transitioning from " << stateStrings[currentState] << " => "
						  << stateStrings[nextState] << std::endl;
				currentState = nextState;
			}
			else
			{
				std::cout << "ERROR: Invalid transition from " << stateStrings[currentState] << " => "
						  << stateStrings[nextState] << std::endl;
			}
		}
		else
		{
			std::cout << "ERROR: +++++++++ Invalid input +++++++++\n";
		}
	}

	return 0;
}