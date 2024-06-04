#include <QCoreApplication>
#include <QTime>
#include <QSharedPointer>
#include <QList>
#include <QDebug>
#include <QThread>
#include <QTimer>

class Message
{
private:
	QString message_;
	QTime	time_stamp_;

public:
	Message(QString message) : message_(message), time_stamp_(QTime::currentTime())
	{
	}

	void display()
	{
		qDebug() << "Message: " << message_ << " Time: " << time_stamp_.toString();
	}

	~Message()
	{
	}
};

class MessageManager
{
private:
	QList<QSharedPointer<Message>> messages_;

public:
	MessageManager(/* args */)
	{
	}

	void addMessage(QSharedPointer<Message> message)
	{
		messages_.append(message);
	}

	void removeMessage(QSharedPointer<Message> message)
	{
		messages_.removeOne(message);
	}

	void displayMessages()
	{
		for (auto message: messages_)
		{
			message.data()->display();
		}
	}

	~MessageManager()
	{
	}
};

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	MessageManager manager;

	manager.addMessage(QSharedPointer<Message>(new Message("Hello")));

	QThread::sleep(1);

	manager.addMessage(QSharedPointer<Message>(new Message("World")));
	QThread::sleep(1);

	manager.addMessage(QSharedPointer<Message>(new Message("Goodbye")));
	QThread::sleep(1);

	manager.displayMessages();

	QCoreApplication::quit();

	//return a.exec();
}
