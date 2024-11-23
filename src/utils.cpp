#include <iostream>
#include <utility> 
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <stdio.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

std::pair<int,int> getTerminalSize()
{
    int width = 80;
    int height = 30;

#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    if (GetConsoleScreenBufferInfo(hStdout, &csbi)) {
        width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    }
#else
    struct winsize w;
    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) != -1) {
        width = w.ws_col;
        height = w.ws_row;
    }
#endif

    return {width, height};
}


bool virtual_terminal_activate()
{
#ifdef _WIN32
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return false;
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return false;
    }
    return true;

#endif
    return true;
}


void scroll_up()
{
    std::cout<<"\x1b[2J\x1b[H\r";
}