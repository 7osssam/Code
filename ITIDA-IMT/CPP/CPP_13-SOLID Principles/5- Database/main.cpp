#include <iostream>
#include <chrono>

class Database
{
public:
	virtual void connect() const = 0;
	virtual void disconnect() const = 0;
};

class MySQLDatabase : public Database
{
public:
	void connect() const override
	{
		std::cout << "Connecting to MySQL database." << std::endl;
	}
	void disconnect() const override
	{
		std::cout << "Disconnecting from MySQL database." << std::endl;
	}
};

class PostgreSQLDatabase : public Database
{
public:
	void connect() const override
	{
		std::cout << "Connecting to PostgreSQL database." << std::endl;
	}
	void disconnect() const override
	{
		std::cout << "Disconnecting from PostgreSQL database." << std::endl;
	}
};

class DatabaseClient
{
private:
	const Database& database;

public:
	DatabaseClient(const Database& db) : database(db)
	{
	}
	void execute()
	{
		database.connect();

		database.disconnect();
	}
};

int main()
{
	MySQLDatabase	   mysqlDatabase;
	PostgreSQLDatabase postgresDatabase;
	DatabaseClient	   client1(mysqlDatabase);
	DatabaseClient	   client2(postgresDatabase);
	client1.execute();
	client2.execute();
	return 0;
}