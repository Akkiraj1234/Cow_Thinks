#include <stdio.h>
#include <wchar.h>
#include <windows.h>
#include <iostream>

int main()
{
    // Set output mode to handle virtual terminal sequences
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return GetLastError();
    }

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return GetLastError();
    }

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return GetLastError();
    }
    
    std::cout<<"a lot of text\nalot of text\na lot of text\n";
    std::cout<<"\x1b[2J\x1b[H\r";
    wprintf(L"\x1b[2J\x1b[H\r");

    return 0;
}