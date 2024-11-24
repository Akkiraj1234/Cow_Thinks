#include <iostream>
#include <string>
#include <sqlite3.h>

// Function to initialize SQLite database
void init_database() {
    sqlite3* db;
    int rc = sqlite3_open("cow_thinks.db", &db);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Database initialized successfully!" << std::endl;

        // Create a table if it doesn't exist
        const char* create_table_sql = "CREATE TABLE IF NOT EXISTS messages (id INTEGER PRIMARY KEY, content TEXT);";
        char* err_msg = nullptr;
        rc = sqlite3_exec(db, create_table_sql, nullptr, nullptr, &err_msg);
        if (rc != SQLITE_OK) {
            std::cerr << "Failed to create table: " << err_msg << std::endl;
            sqlite3_free(err_msg);
        } else {
            std::cout << "Table ready!" << std::endl;
        }
    }
    sqlite3_close(db);
}

// Function to parse arguments
void handle_arguments(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: cow_thinks -say <message>\n";
        return;
    }

    std::string command = argv[1];
    if (command == "-say" && argc > 2) {
        std::string message = argv[2];
        std::cout << "Cow says: " << message << std::endl;
        
        // Store the message in the database
        sqlite3* db;
        sqlite3_open("cow_thinks.db", &db);
        std::string insert_sql = "INSERT INTO messages (content) VALUES ('" + message + "');";
        char* err_msg = nullptr;
        int rc = sqlite3_exec(db, insert_sql.c_str(), nullptr, nullptr, &err_msg);
        if (rc != SQLITE_OK) {
            std::cerr << "Failed to insert message: " << err_msg << std::endl;
            sqlite3_free(err_msg);
        } else {
            std::cout << "Message stored successfully!" << std::endl;
        }
        sqlite3_close(db);
    } else {
        std::cout << "Invalid command.\nUsage: cow_thinks -say <message>\n";
    }
}

int main(int argc, char* argv[]) {
    std::cout << "Welcome to Cow_Thinks!" << std::endl;

    // Initialize SQLite database
    init_database();

    // Handle command-line arguments
    handle_arguments(argc, argv);

    return 0;
}
