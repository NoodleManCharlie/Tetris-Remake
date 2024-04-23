#include "include/keyboard.h"

bool releasedW;
bool releasedA;
bool releasedS;
bool releasedD;

#include <windows.h>
#include <iostream>

void keyboard::keysInit()
{
    bool releasedW = true;
    bool releasedA = true;
    bool releasedS = true;
    bool releasedD = true;
}

int keyboard::checkKeys()
{
    //Check for a
    if (GetAsyncKeyState(0x41) && releasedA == true)
    {
        //std::cout << "a pressed once";
        releasedA = false;
        return -1;
    }
    if (!(GetAsyncKeyState(0x41)))
    {
        //std::cout << "a released";
        releasedA = true;
    }

    //Check for d
    if (GetAsyncKeyState(0x44) && releasedD == true)
    {
        //std::cout << "d pressed once";
        releasedD = false;
        return 1;
    }
    if (!(GetAsyncKeyState(0x44)))
    {
        //std::cout << "d released";
        releasedD = true;
    }

    //Check if w
    if (GetAsyncKeyState(0x57) && releasedW == true)
    {
        //std::cout << "w pressed once";
        releasedW = false;
    }
    if (!(GetAsyncKeyState(0x57)))
    {
        //std::cout << "w released";
        releasedW = true;
    }

    //Check is s
    if (GetAsyncKeyState(0x53) && releasedS == true)
    {
        //std::cout << "s pressed once";
        releasedS = false;
    }
    if (!(GetAsyncKeyState(0x53)))
    {
        //std::cout << "s released";
        releasedS = true;
    }

    return 0;
}