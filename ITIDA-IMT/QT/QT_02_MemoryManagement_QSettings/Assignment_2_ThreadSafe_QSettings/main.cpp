#include <QCoreApplication>
#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include "settings.h"
#include <QThreadPool>

// Function to save settings in a separate thread
void saveSettings()
{
	Settings& settings = Settings::getInstance();
	settings.SaveSettings();
}

// Function to load settings in a separate thread
void loadSettings()
{
	Settings& settings = Settings::getInstance();
	settings.LoadSettings();
}

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	// Display the thread ID
	qInfo() << "Main thread ID: " << QThread::currentThreadId();

	QCoreApplication::setOrganizationName("ITIDA");
	QCoreApplication::setApplicationName("MyApp");

	if (!Settings::getInstance().SettingsExist())
	{
		qInfo() << "Settings do not exist. Creating new settings";
		//QFuture<void> saveFuture = QtConcurrent::run(saveSettings);

		QFuture<void> saveFuture = QtConcurrent::run([]() {
			Settings::getInstance().SaveSettings();
		});
		saveFuture.waitForFinished();
	}
	else
	{
		// Load the settings in a separate thread
		//QFuture<void> loadFuture = QtConcurrent::run(loadSettings);

		QFuture<void> loadFuture = QtConcurrent::run([]() {
			Settings::getInstance().LoadSettings();
		});

		loadFuture.waitForFinished();
	}

	Settings::getInstance().DisplaySettings();

	qInfo() << "Main thread finished ID: " << QThread::currentThreadId();
	return a.exec();
}
