#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <vector>

// Memento Pattern
// 1. Originator
// 2. Memento
// 3. Caretaker

// Memento
class Memento
{
private:
	std::string state_;
	std::string text_;

public:
	Memento(std::string state, std::string text) : state_(state), text_(text)
	{
	}

	std::string getState() const
	{
		return state_;
	}

	std::string getText() const
	{
		return text_;
	}
};

// Originator
class Originator // TextEditor
{
private:
	std::string state_;
	std::string text_;

public:
	void setState(std::string state)
	{
		state_ = state;
	}

	void setText(std::string text)
	{
		text_ = text;
	}

	std::shared_ptr<Memento> createMemento() // Backup
	{
		return std::make_shared<Memento>(state_, text_);
	}

	void restoreMemento(std::shared_ptr<Memento> memento) // Restore
	{
		state_ = memento->getState();
		text_ = memento->getText();
	}

	void displayData() const
	{
		std::cout << "Text: " << text_ << std::endl;
		std::cout << "State: " << state_ << std::endl;
	}

	void saveToFile(const std::string& filename) const
	{
		std::ofstream file(filename);
		if (file.is_open())
		{
			file << state_ << std::endl;
			file << text_ << std::endl;
			file.close();
			std::cout << "Document saved to " << filename << std::endl;
		}
		else
		{
			std::cerr << "Unable to open file " << filename << std::endl;
		}
	}

	void loadFromFile(const std::string& filename)
	{
		std::ifstream file(filename);
		if (file.is_open())
		{
			std::getline(file, state_);
			std::getline(file, text_);
			file.close();
			std::cout << "Document loaded from " << filename << std::endl;
		}
		else
		{
			std::cerr << "Can't open :" << filename << std::endl;
		}
	}
};

// Caretaker
class Caretaker // TextEditorManager
{
private:
	std::shared_ptr<Originator>			  TextEditor_;
	std::vector<std::shared_ptr<Memento>> mementos_;

public:
	Caretaker(std::shared_ptr<Originator> TextEditor) : TextEditor_(TextEditor)
	{
	}

	void backup()
	{
		mementos_.push_back(TextEditor_->createMemento());
		std::cout << "Backup created ======> " << std::endl;
	}

	void undo()
	{
		if (mementos_.empty())
		{
			std::cout << "No more mementos to restore" << std::endl;
			return;
		}

		auto memento = mementos_.back();
		mementos_.pop_back();
		TextEditor_->restoreMemento(memento);
	}
};

int main()
{
	auto TextEditor = std::make_shared<Originator>();
	auto TextEditorManager = std::make_shared<Caretaker>(TextEditor);

	TextEditor->setState("State1");
	TextEditor->setText("Text1");
	TextEditor->displayData();

	TextEditorManager->backup();
	TextEditor->saveToFile("backup.txt"); // Save document state to file

	TextEditor->setState("this is a new state");
	TextEditor->setText("Text2");
	TextEditor->displayData();

	TextEditor->setState("State3");
	TextEditor->setText("Text3");
	TextEditor->displayData();
	TextEditor->loadFromFile("backup.txt"); // Load document state from file

	TextEditor->displayData();

	return 0;
}
