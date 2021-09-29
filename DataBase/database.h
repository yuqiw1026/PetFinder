#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <QtSql>
#include <iostream>

/**
 * @brief The Database class opens an SQLite database.
 */
class Database
{
public:
    /**
     * @brief Database  throws exception because database must have name
     */
    Database();

    /**
     * @brief Database  creates a database with a name
     * @param nameIn    the name of the database
     */
    Database(std::string nameIn);

    /**
     * @brief Database      creates a database with a location and name
     * @param locationIn    the file location of the database
     * @param nameIn        the name of the database
     */
    Database(std::string locationIn, std::string nameIn);

    /**
     * @brief ~Database     cleans up this database
     */
    ~Database();

    /**
     * @brief open      tries to open this database
     * @return true if opening was successful
     */
    bool open();

    /**
     * @brief print     prints this database's status
     * @param sout      the output to print to
     */
    void print(std::ostream &sout);

    /**
     * @brief runQuery     runs the sql statement
     * @param Qstring     the sql statement
     */
    void runQuery(QString str);

private:
    std::string name;
    std::string location;
    QSqlDatabase database;
};
#endif // DATABASE_H
