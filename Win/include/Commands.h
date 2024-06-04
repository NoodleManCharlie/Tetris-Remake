#ifndef COMMANDS_CLASS_H
#define COMMANDS_CLASS_H

//#define NOMINMAX
//#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <iostream>


class Commands
{
    public:
        void cls();
        void setCursorPosition(int x, int y);

};

#endif