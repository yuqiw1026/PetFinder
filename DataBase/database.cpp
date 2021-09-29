#include "database.h"

/**
 * @brief Database::Database    throws an exception to indicate databases
 *                              must have a game
 */
Database::Database() {
    std::cerr << "Name must be provided to Database class "
              << "during creation.\n";
    exit(-1);
}

/**
 * @brief Database::Database    creates a database with a name if the
 *                              necessary drivers exist
 * @param nameIn                the name of the database
 */
Database::Database(std::string nameIn) {

    if (!QSqlDatabase::drivers().contains("QSQLITE")) {
        std::cerr << "Unable to load database; missing SQLITE driver"
                  << std::endl;
        exit(-1);
    }

    name = nameIn;
    if(nameIn == "UserInfo.sqlite"){
         location = "../../../../project";
    }else if(nameIn == "test.sqlite"){
         location = "../../../../UnitTest";
    }

    open();
}

/**
 * @brief Database::Database    creates a database with a location and name
 *                              if the necessary drivers exist
 * @param locationIn            the file location of the database
 * @param nameIn                the name of the database
 */
Database::Database(std::string locationIn, std::string nameIn) {
    if (!QSqlDatabase::drivers().contains("QSQLITE")) {
        std::cerr << "Unable to load database; missing SQLITE driver"
                  << std::endl;
        exit(-1);
    }

    name = nameIn;
    location = locationIn;

    open();
}

/**
 * @brief Database::~Database   closes the database
 */
Database::~Database() {
    database.close();
}


/**
 * @brief Database::open    tries to open this database
 * @return  whether this database opened successfully
 */
bool Database::open() {
    if(QSqlDatabase::contains()){
        database = QSqlDatabase::database();
    }else{
        std::string fullName = location +
                QString(QDir::separator()).toStdString() + name;

        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName(QString::fromStdString(fullName));
    }
    if (!database.open()) {
        std::cerr << "Database does not open -- "
                  << database.lastError().text().toStdString()
                  << std::endl;

        //std::cerr << "  File -- " << fullName << std::endl;
        return false;
    }

    std::cerr << "Opened database successfully\n";
    return true;
}

/**
 * @brief Database::print   prints this database's status
 * @param sout              where to print status to
 */
void Database::print(std::ostream &sout) {

    sout << "DB Name : " << name     << std::endl;
    sout << "DB Loc  : " << location << std::endl;

    sout << "Status  : "
         << (database.open() ? "open" : "closed")
         << std::endl;
}

/**
 * @brief runQuery     runs the sql statement
 * @param Qstring     the sql statement
 */
void Database::runQuery(QString str){
    QSqlQuery qry;
    if(!qry.exec(str)){
        qDebug() << "error running query";
    }
}
