cmake_minimum_required(VERSION 3.10)
project(cow_thinks)

set(CMAKE_CXX_STANDARD 17)

# Add SQLite and any other required libraries
find_package(SQLite3 REQUIRED)
find_package(Boost REQUIRED COMPONENTS system program_options)

# Add source files
add_executable(cow_thinks src/main.cpp src/cli_handler.cpp src/db_manager.cpp src/network_manager.cpp)

# Link libraries
target_link_libraries(cow_thinks SQLite::SQLite3 Boost::system Boost::program_options)
