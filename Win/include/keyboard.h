#ifndef KEYBOARD_CLASS_H
#define KEYBOARD_CLASS_H

#include <windows.h>
#include <iostream>

class keyboard
{
    public:
        bool releasedW;
        bool releasedA;
        bool releasedS;
        bool releasedD;
        bool releasedR;

        void keysInit()
        {
            bool releasedW = true;
            bool releasedA = true;
            bool releasedS = true;
            bool releasedD = true;
            bool releasedR = true;
        }

        int checkKeys()
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

            //Check is r
            if (GetAsyncKeyState(0x52) && releasedS == true)
            {
                //std::cout << "r pressed once";
                releasedR = false;
            }
            if (!(GetAsyncKeyState(0x52)))
            {
                //std::cout << "r released";
                releasedR = true;
            }

            return 0;
        }

};

#endif