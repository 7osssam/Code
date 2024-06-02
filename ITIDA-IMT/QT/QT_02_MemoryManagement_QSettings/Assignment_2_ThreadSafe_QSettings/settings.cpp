#include "settings.h"
#include <QThread>
#include <QMutexLocker>

Settings::Settings(const QString& filePath) : settings(filePath, QSettings::IniFormat)
{
	qInfo() << "Settings initialized with file:" << filePath;
}

bool Settings::SaveVal(const QString& group, const QString& key, const QVariant& value)
{
	qInfo() << "Mutex locked for SaveVal in thread:" << QThread::currentThreadId();
	QMutexLocker locker(&mutex); // Lock the mutex

	bool status = false;

	settings.beginGroup(group);

	settings.setValue(key, value);

	if (settings.status() == QSettings::NoError)
	{
		status = true;
		qInfo() << "Saved successfully";
	}
	else
	{
		qCritical() << "Error in saving";
	}

	settings.endGroup();

	qInfo() << Q_FUNC_INFO << settings.status();

	return status;
}

QVariant Settings::LoadVal(const QString& group, const QString& key, const QVariant& defaultValue)
{
	qInfo() << "Mutex locked for LoadVal in thread:" << QThread::currentThreadId();

	QMutexLocker locker(&mutex); // Lock the mutex

	QVariant value;

	settings.beginGroup(group);

	if (!settings.contains(key))
	{
		qWarning() << "Key" << key << "not found";
		settings.endGroup();
		return defaultValue;
	}

	value = settings.value(key, defaultValue);

	if (settings.status() != QSettings::NoError)
	{
		qCritical() << "Error in loading";
	}

	settings.endGroup();

	qInfo() << Q_FUNC_INFO << settings.status();
	return value;
}

Settings& Settings::getInstance()
{
	static Settings instance(QCoreApplication::organizationName() + "/" +
							 QCoreApplication::applicationName() + ".ini");

	return instance;
}

void Settings::SaveSettings()
{
	SaveVal("Group1", "Font_Color", "Black");
	SaveVal("Group1", "Font_Size", 20);
	SaveVal("Group2", "Font_Color", "Yellow");
	SaveVal("Group2", "Font_Size", 34);

	qInfo() << Q_FUNC_INFO;
}

void Settings::LoadSettings()
{
	QString Color1 = LoadVal("Group1", "Font_Color", "White").toString();
	qint32	size1 = LoadVal("Group1", "Font_Size", 10).toInt();
	QString Color2 = LoadVal("Group2", "Font_Color", "White").toString();
	qint32	size2 = LoadVal("Group2", "Font_Size", 10).toInt();

	qInfo() << Q_FUNC_INFO;
}

void Settings::DisplaySettings()
{
	foreach (const QString& group, settings.childGroups())
	{
		qInfo() << "Group:" << group;
		settings.beginGroup(group);
		foreach (const QString& key, settings.childKeys())
		{
			qInfo() << "__ Key:" << key;
			qInfo() << "_____ Value:" << settings.value(key).toString();
		}
		settings.endGroup();
	}
}

bool Settings::SettingsExist()
{
	settings.beginGroup("Group1");
	bool group1Exists = settings.contains("Font_Color") && settings.contains("Font_Size");
	settings.endGroup();

	settings.beginGroup("Group2");
	bool group2Exists = settings.contains("Font_Color") && settings.contains("Font_Size");
	settings.endGroup();

	return group1Exists && group2Exists;
}
