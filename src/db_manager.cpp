#include <sqlite3.h>
#include "include/utils.h"

void init_database() {
    sqlite3* db;
    int rc = sqlite3_open("cow_thinks.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Opened database successfully!" << std::endl;
    }
    sqlite3_close(db);
}

void add_new_entry()
{
    sqlite3* db;
}