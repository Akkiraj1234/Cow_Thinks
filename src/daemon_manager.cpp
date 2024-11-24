#include <unistd.h>
#include <iostream>

void start_daemon() {
    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "Failed to fork process." << std::endl;
        exit(1);
    }
    if (pid > 0) {
        std::cout << "Daemon started with PID: " << pid << std::endl;
        exit(0);
    }
    // Child process continues here
}
