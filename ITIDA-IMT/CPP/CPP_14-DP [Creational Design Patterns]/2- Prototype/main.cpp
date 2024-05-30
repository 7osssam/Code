#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <vector>

enum Game_Character_t
{
	Warrior_t,
	Mage_t
};

class Game_Character
{
protected:
	int						 health_;
	int						 power_;
	std::string				 name_;
	std::vector<std::string> weapons_;

public:
	Game_Character(int health, int power, std::string name, std::vector<std::string> weapons) :
		health_(health), power_(power), name_(name), weapons_(weapons)
	{
	}
	virtual void draw() const = 0;

	void display_info() const
	{
		std::cout << "==========================" << std::endl;
		std::cout << "Game Character: " << std::endl;
		std::cout << "Name: " << name_ << std::endl;
		std::cout << "Health: " << health_ << std::endl;
		std::cout << "Power: " << power_ << std::endl;
		std::cout << "Weapons: " << std::endl;

		for (const auto& weapon: weapons_)
		{
			std::cout << weapon << std::endl;
		}
		std::cout << "==========================" << std::endl;
	}

	virtual std::unique_ptr<Game_Character> Clone() = 0;
};

class Warrior : public Game_Character
{
private:
public:
	Warrior(int health, int power, std::string name, std::vector<std::string> weapons) :
		Game_Character(health, power, name, weapons)
	{
	}

	void draw() const override
	{
		std::cout << __FUNCTION__ << " Warrior" << std::endl;
	}

	std::unique_ptr<Game_Character> Clone() override
	{
		return std::make_unique<Warrior>(health_, power_, name_, weapons_);
	}
};

class Mage : public Game_Character
{
private:
	/* data */
public:
	Mage(int health, int power, std::string name, std::vector<std::string> weapons) :
		Game_Character(health, power, name, weapons)
	{
	}
	void draw() const override
	{
		std::cout << __FUNCTION__ << " Mage" << std::endl;
	}

	std::unique_ptr<Game_Character> Clone() override
	{
		return std::make_unique<Mage>(health_, power_, name_, weapons_);
	}
};

class Client
{
private:
	std::map<Game_Character_t, std::unique_ptr<Game_Character>> MapOfGameCharacters;

public:
	void registerGameCharacter(Game_Character_t s, std::unique_ptr<Game_Character> ptr)
	{
		MapOfGameCharacters[s] = std::move(ptr);
	}

	std::unique_ptr<Game_Character> createGameCharacter(Game_Character_t s)
	{
		if (MapOfGameCharacters.count(s))
		{
			return MapOfGameCharacters[s]->Clone();
		}
		else
		{
			return nullptr;
		}
	}
};

int main()
{
	auto ptr1 = std::make_unique<Warrior>(100, 50, "Warrior", std::vector<std::string>{"Sword", "Shield"});

	auto ptr2 = std::make_unique<Mage>(100, 50, "Mage", std::vector<std::string>{"Staff", "Magic"});

	ptr1->draw();
	ptr1->display_info();
	ptr2->draw();
	ptr2->display_info();

	Client c;
	c.registerGameCharacter(Warrior_t, std::move(ptr1));
	c.registerGameCharacter(Mage_t, std::move(ptr2));

	auto ptr4 = c.createGameCharacter(Warrior_t);
	auto ptr5 = c.createGameCharacter(Mage_t);

	ptr4->draw();
	ptr4->display_info();

	ptr5->draw();
	ptr5->display_info();
}
