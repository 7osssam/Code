#include <iostream>
#include <memory>
#include <vector>

// Chain of Responsibility components:
// 1. Handler
// 2. ConcreteHandler
// 3. Client

enum class IssueType
{
	Hardware,
	Software,
	Other
};

class Request
{
public:
	Request(IssueType type) : type(type)
	{
	}

	IssueType getType() const
	{
		return type;
	}

private:
	IssueType type;
};

// Handler
class Handler
{
public:
	virtual void handle_request(const Request& request) = 0;
	virtual void set_successor(std::shared_ptr<Handler> successor) = 0;
};

// ConcreteHandler
class HardwareSpecialist : public Handler
{
private:
	std::shared_ptr<Handler> successor_;

public:
	void handle_request(const Request& request) override
	{
		if (request.getType() == IssueType::Hardware)
		{
			std::cout << "Hardware issue handled by Hardware Specialist.\n";
		}
		else if (successor_ != nullptr)
		{
			successor_->handle_request(request);
		}
	}

	void set_successor(std::shared_ptr<Handler> successor) override
	{
		successor_ = successor;
	}
};

// ConcreteHandler
class SoftwareExpert : public Handler
{
private:
	std::shared_ptr<Handler> successor_;

public:
	void handle_request(const Request& request) override
	{
		if (request.getType() == IssueType::Software)
		{
			std::cout << "Software issue handled by Software Expert.\n";
		}
		else if (successor_ != nullptr)
		{
			successor_->handle_request(request);
		}
	}

	void set_successor(std::shared_ptr<Handler> successor) override
	{
		successor_ = successor;
	}
};

// ConcreteHandler (end of the chain)
class Generalist : public Handler
{
public:
	void handle_request(const Request& request) override
	{
		std::cout << "Issue handled by Generalist.\n";
	}

	void set_successor(std::shared_ptr<Handler> successor) override
	{
		// Do nothing
	}
};

// Client
class HelpDesk
{
private:
	std::vector<std::shared_ptr<Handler>> handlers_;

public:
	HelpDesk()
	{
		handlers_.push_back(std::make_shared<HardwareSpecialist>());
		handlers_.push_back(std::make_shared<SoftwareExpert>());
		handlers_.push_back(std::make_shared<Generalist>());

		// until -1
		for (size_t i = 0; i < handlers_.size() - 1; i++)
		{
			// for each handler, set the next handler as its successor
			handlers_[i]->set_successor(handlers_[i + 1]);
		}
	}

	void make_request(const Request& request)
	{
		handlers_[0]->handle_request(request);
	}
};

int main()
{
	HelpDesk helpDesk;
	helpDesk.make_request(Request(IssueType::Hardware));
	helpDesk.make_request(Request(IssueType::Software));
	helpDesk.make_request(Request(IssueType::Other));

	return 0;
}