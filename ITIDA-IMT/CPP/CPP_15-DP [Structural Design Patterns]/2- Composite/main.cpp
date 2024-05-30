#include <iostream>
#include <vector>

// Composite pattern

// Component
class UIComponent
{
public:
	virtual void draw() = 0;
};

// Leaf
class Button : public UIComponent
{
private:
	std::string name;

public:
	Button(const std::string& name) : name(name)
	{
	}

	void draw() override
	{
		std::cout << "Button: " << name << "\n";
	}
};

// Composite
class Panel : public UIComponent
{
private:
	std::string				  name;
	std::vector<UIComponent*> components;

public:
	Panel(const std::string& name) : name(name)
	{
	}

	void addComponent(UIComponent* component)
	{
		components.push_back(component);
	}

	void draw() override
	{
		std::cout << "Drawing panel: " << std::endl;
		for (UIComponent* component: components)
		{
			component->draw();
		}
	}
};

// Client
int main()
{
	Button newButton("New");
	newButton.draw();

	Button okButton("OK");
	Button cancelButton("Cancel");

	Panel panel("Panel");
	panel.addComponent(&okButton);
	panel.addComponent(&cancelButton);

	panel.draw();

	return 0;
}