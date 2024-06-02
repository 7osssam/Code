#ifndef SETTINGS_H
#define SETTINGS_H

#include <QSettings>
#include <QDebug>
#include <QCoreApplication>
#include <QMutex>
class Settings
{
private:
	QSettings  settings;
	QMutex    mutex;

	Settings(const QString& filePath);

	// delete copy constructor and assignment operator
	Settings(const Settings&) = delete;
	Settings& operator=(const Settings&) = delete;

	bool	 SaveVal(const QString& group, const QString& key, const QVariant& value);
	QVariant LoadVal(const QString& group, const QString& key, const QVariant& defaultValue = QVariant{});

public:
	static Settings& getInstance();

	void SaveSettings();
	void LoadSettings();

	void DisplaySettings();

	bool SettingsExist(); // New method to check if settings exist
};

#endif					  // SETTINGS_H
