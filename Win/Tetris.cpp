// Built in Libraries
#include <Windows.h>
#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fstream>
//#include <sysinfoapi.h>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <algorithm> 
#include <direct.h>

// Imported Libraries
//#include "include/SDL2/SDL.h"

// My Classes
#include "include/Blocks.h"
#include "include/keyboard.h"

using std::map;
using std::string;
using std::vector;

int score = 0;
int highScore = 0;

bool game = true;

Blocks blocksClass;

keyboard keys;

// Used to make set all strings to the same length including spaces
string setStringLength(string theString, int length, bool gameElsewise)
{
    int stringLength = theString.length();
    char space = ' ';

    if (gameElsewise == false)
    {
        if (stringLength < length)
        {
            theString.resize(stringLength + (length - stringLength), space);
        }
        else if (stringLength > length)
        {
            theString.resize(length);
        }
        return theString;
    }
    else
    {
        theString.resize(length);
        return theString;
    }
}

void printInfo(int line)
{
    string offset = "";
    int Blocks = 0;

    switch (line)
    {
        case (0):
        {
            offset = "HighScore";
            offset = setStringLength(offset, 9, false);
            std::cout << offset + "|";
            break;
        }
        case (1):
        {
            offset = std::to_string(highScore);
            offset = setStringLength(offset, 9, false);
            std::cout << offset + "|";
            break;
        }
        case (2):
        {
            std::cout << "/////////|";
            break;
        }
        case (3):
        {
            offset = "  Score  ";
            offset = setStringLength(offset, 9, false);
            std::cout << offset + "|";
            break;
        }
        case (4):
        {
            offset = std::to_string(score);
            offset = setStringLength(offset, 9, false);
            std::cout << offset + "|";
            break;
        }
        case (5):
        {
            std::cout << "/////////|";
            break;
        }
        default:
        {
            offset = "";
            offset = setStringLength(offset, 9, false);
            std::cout << offset + "|";
            break;
        }
    }
}

map<int, vector<string>> createBoard(vector<string> board, int boardWidth, int boardHeight, map<int, vector<string>> fullBoard)
{
    board.insert(board.end(), boardWidth, "[ ]");

    for (int i = 1; i != (boardHeight + 1); i++)
    {
        fullBoard[i] = board;
    }

    return fullBoard;
}

void printBoard(map<int, vector<string>> fullBoard)
{
    //std::cout << "Printing Board";

    system("CLS");
    int line = 0;

    std::cout << "/////////|------------Tetris------------|\n";
    for (map<int, vector<string>>::iterator ii = fullBoard.begin(); ii != fullBoard.end(); ++ii)
    {
        printInfo(line);
        line += 1;
        vector<string> inVect = (*ii).second;
        for (unsigned j = 0; j < inVect.size(); j++)
        {
            std::cout << inVect[j];
        }
        std::cout << "|" << std::endl;
    }

}

void updateBoard(map<int, vector<string>> fullBoard)
{
    //std::cout << "Updating Board";
    

}

// Mmmmmmaaaaayyyyybbbbeeeee llllllaaaaaattttteeeerrrr
int folderStructure()
{
    // Path to the directories
    
    vector<const char *> directories = {"./main/libraries/map/highscore",
                                        "./main/libraries/iostream",
                                        "./main/libraries/vector",
                                        "./main/penguin",
                                        "./main/reset/donotenter/seriously/okbethatway/hahagetpranked"};
    

    //vector<LPCWSTR> directoriies = {"./main/libraries/map/highscore",
    //                                    "./main/libraries/iostream",
    //                                    "./main/libraries/vector",
    //                                    "./main/penguin",
    //                                    "./main/reset/donotenter/seriously/okbethatway/hahagetpranked"};
    // const char* dir = "./main/libraries";
    //  Structure which would store the metadata

    for (int i = 0; i <= directories.size(); i++)
    {
        int check = mkdir(directories[i]);

        // check if directory is created or not
        if (!check)
        {
            printf(*directories[i] + "- Directory created\n");
        }
        else
        {
            printf(*directories[i] + "- Unable to create directory\n");
        }
    }
    return 0;
}

void updateScore(int addition)
{
    score += addition;
    if (score > highScore)
    {
        highScore = score;
        std::ofstream saveData("Win/main/libraries/map/highscore/highscore.txt");
        saveData << score;
        saveData.close();
    }
}

int xAddBefore;

// Function used in fixedUpdate
void wait(DWORD interval, map<int, vector<string>> &fullBoard, int boardHeight, int boardWidth)
{
    DWORD startTime = GetTickCount();

    while (GetTickCount() < (startTime + interval))
    {
        int returned = keys.checkKeys();

        xAddBefore = blocksClass.xAdd;
        if(returned == 2)
        {
            blocksClass.rotate();
            blocksClass.moveBlock(fullBoard, "[/]", "[ ]", blocksClass.yPos);
            //printBoard(fullBoard);
            //blocksClass.moveBlock(fullBoard, "[ ]", yPos);
        }
        else
        {
            blocksClass.xAdd += returned;
        }
        if (blocksClass.xAdd == -2)
        {
            blocksClass.xAdd = -1;
        }
        else if (blocksClass.xAdd == (boardWidth - (blocksClass.getWidth()))) //Board width 10 - Block Width - 1
        {
            blocksClass.xAdd = boardWidth - blocksClass.getWidth() - 1;
        }
        else if (xAddBefore != blocksClass.xAdd)
        {
            blocksClass.moveBlock(fullBoard, "[/]", "[ ]", blocksClass.yPos);
            //printBoard(fullBoard);

            blocksClass.holder = blocksClass.getBottom();
            blocksClass.heights = blocksClass.getTop();

            int position = blocksClass.holder[0][1];
            if (position + blocksClass.yPos == (boardHeight - (blocksClass.heights[0][1])))
            {
                blocksClass.brickOnScreen = false;
                blocksClass.yPos = 0;
                blocksClass.inAir = false;
            }
            if (blocksClass.inAir)
            {
                //blocksClass.moveBlock(fullBoard, "[ ]", yPos);
            }
        }
    }
}

void fixedUpdate(map<int, vector<string>> fullBoard, int boardHeight, int boardWidth)
{
    blocksClass.brickOnScreen = false;
    blocksClass.yPos = 0;
    blocksClass.inAir = true;

    //SDL_Event event;

    while (game)
    {
        int round = -1;
        round += 1;

        if (!blocksClass.brickOnScreen)
        {
            blocksClass.setCurrentBlock();
            blocksClass.brickOnScreen = true;
            blocksClass.yPos += 1;
            blocksClass.inAir = true;
            round = 0;
            blocksClass.xAdd = 0;
        }
        
        // DETERMINES HOW OFTEN UPDATES
        // VVVVVVVVVVVVVVVVVVVVVVVV
        int solutionTime = 350; // 1 second
        if (keys.releasedS == false)
        {
            solutionTime = 50; // 7th of a second
        }
        else if (keys.releasedS == true)
        {
            solutionTime = 350; // 1 second
        }

        int timer;
        int counter = 0;
        DWORD interval = 20;

        DWORD start = GetTickCount(); // program starts

        for (timer = 0; timer < solutionTime; timer += interval)
        {

            wait(interval, fullBoard, boardHeight, boardWidth);

            counter++;
        }

        

        if (blocksClass.brickOnScreen && round <= 1)
        {
            int i;
            int n;

            blocksClass.moveBlock(fullBoard, "[/]", "[ ]",  blocksClass.yPos);
            //printBoard(fullBoard);
            blocksClass.holder = blocksClass.getBottom();
            blocksClass.heights = blocksClass.getTop();

            int position = blocksClass.holder[0][1];
            
            if (position + blocksClass.yPos == (boardHeight - (blocksClass.heights[0][1])))
            {
                blocksClass.brickOnScreen = false;
                blocksClass.yPos = 0;
                blocksClass.inAir = false;
            } 
            
            if (blocksClass.inAir)
            {
                //blocksClass.moveBlock(fullBoard, "[ ]", yPos);
            }
            
            if (blocksClass.yPos < (boardHeight - (blocksClass.heights[0][1])))
            {
                blocksClass.yPos += 1;
                blocksClass.inAir = true;
            }
            
        }
        
    }
}

//int argv, char **args
int main()
{
    std::ios::sync_with_stdio(false);
    string response;

    blocksClass.blocksInit();
    system("CLS");

    keys.keysInit();

    // time_t timeForRand = time(NULL);
    srand(static_cast<unsigned int>(time(NULL) ));

    std::ifstream readData("Win/main/libraries/map/highscore/highscore.txt");

    string red = "";

    std::getline(readData, red);
    if (red == "")
    {
        std::ifstream readDData("main/libraries/map/highscore/highscore.txt");

        std::getline(readDData, red);
    }
    highScore = std::stoi(red);

    readData.close();

    system("CLS");
    std::cout << "Welcome to Tetris \nWhen your Ready, type \"Y\" and enter: ";

    std::cin >> response;
    system("CLS");

    vector<string> board;
    map<int, vector<string>> fullBoard;
    fullBoard = createBoard(board, blocksClass.boardWidth, blocksClass.boardHeight, fullBoard);
    printBoard(fullBoard);
    fixedUpdate(fullBoard, blocksClass.boardHeight, blocksClass.boardWidth);

    std::cin >> response;
    return 0;
}

/* TO ADD
-Frame Buffers (Maybe it will help the smoothness of the program? As in not the fill in of the current)
-Or some way to only update the changed pixels
-Music? Be a good way to learn how to do audio
-Roatation
-Preformance upgrades - Make use of multi threading and garbage to make creating new block a background process.
*/

/*
USEFUL RESEARCH?

For Key inputs - maybe SDL 2 could be useful?
https://www.libsdl.org/

SDL according to Geeks for Geeks
"SDL is Simple DirectMedia Layer.It is a cross-platform development library designed to provide low level access to audio,
keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D.It can be used to make animations and video games.
It basically provides a set of APIs to interact with various devices like graphics hardware, audio, keyboard, mouse, etc."

Look into this and how it deals with graphics. Also how widley it is used
*/

//Checkout https://www.youtube.com/watch?v=dc7CIkZcWYE - Atlas OS makes Windows Faster