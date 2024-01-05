#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
#include <sysinfoapi.h>
#include <sstream>
#include <cstdlib>
#include <time.h> 
#include <algorithm>

#include "include/Bricks.h"

using std::string;
using std::vector;
using std::map;

int score = 0;
int highScore = 0;

bool game = true;

//Used to make set all strings to the same length including spaces
string setStringLength(string theString, int length, bool gameElsewise)
{
    int stringLength = theString.length();
    char space = ' ';

    if(gameElsewise == false)
    {
        if(stringLength < length)
        {
            theString.resize(stringLength+(length-stringLength), space);
        }
        else if(stringLength  > length)
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

    switch(line)
    {
        case(0):
        {
            offset = "HighScore";
            offset = setStringLength(offset, 9, false);
            std::cout << offset + "|";
            break;
        }
        case(1):
        {
            offset = std::to_string(highScore);
            offset = setStringLength(offset, 9, false);
            std::cout << offset + "|";
            break;
        }
        case(2):
        {
            std::cout << "/////////|";
            break;
        }
        case(3):
        {
            offset = "  Score  ";
            offset = setStringLength(offset, 9, false);
            std::cout << offset + "|";
            break;
        }
        case(4):
        {
            offset = std::to_string(score);
            offset = setStringLength(offset, 9, false);
            std::cout << offset + "|";
            break;
        }
        case(5):
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

    for(int i = 1; i != (boardHeight+1); i++)
    {
        fullBoard[i] = board;
    }

    
    return fullBoard;
}

void printBoard(map<int, vector<string>> fullBoard)
{
    system("CLS");
    int line = 0;

    std::cout << "/////////|------------Tetris------------|\n";
    for(map<int, vector<string> >::iterator ii=fullBoard.begin(); ii!=fullBoard.end(); ++ii)
    {
        printInfo(line);
        line += 1;
        vector <string> inVect = (*ii).second;
        for (unsigned j=0; j<inVect.size(); j++)
        {
            std::cout << inVect[j];
        }
        std::cout << "|";
        std::cout << std::endl;
    }
}

//Mmmmmmaaaaayyyyybbbbeeeee llllllaaaaaattttteeeerrrr
int folderStructure()
{
    // Path to the directories
    vector<const char*> directories = { "./main/libraries/map/highscore", 
                                        "./main/libraries/iostream", 
                                        "./main/libraries/vector", 
                                        "./main/penguin", 
                                        "./main/reset/donotenter/seriously/okbethatway/hahagetpranked"};
    //const char* dir = "./main/libraries";
    // Structure which would store the metadata

    for(int i=0; i <= directories.size(); i++)
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
    if(score > highScore)
    {
        highScore = score;
        std::ofstream saveData("Win/main/libraries/map/highscore/highscore.txt");
        saveData << score;
        saveData.close();
    }
}

//Function used in fixedUpdate
void wait(DWORD interval)
{
	DWORD startTime = GetTickCount();

	while(GetTickCount() < (startTime + interval))
	{
		//DO NOTHING JUST WAIT
	}
}

void moveBlock( map<int, vector<string>>& fullBoard, string fill, int usedBrick, int yPos,
            Brick::SquareBrick     sqrBrick,
            Brick::LBrick          lBrick,
            Brick::LBackwardsBrick lBackBrick,
            Brick::TBrick          tBrick,
            Brick::ZBrick          zBrick,
            Brick::ZBackwardsBrick zBackBrick,
            Brick::StraightBrick   straightBrick 
)
{
    int i;
    int n;

            switch(usedBrick)
            {
                case(1):
                {
                    i = sqrBrick.brick1[1];
                    n = sqrBrick.brick1[0];
                    fullBoard[i+yPos][n] = fill;
                    i = sqrBrick.brick2[1];
                    n = sqrBrick.brick2[0];
                    fullBoard[i+yPos][n] = fill;
                    i = sqrBrick.brick3[1];
                    n = sqrBrick.brick3[0];
                    fullBoard[i+yPos][n] = fill;
                    i = sqrBrick.brick4[1];
                    n = sqrBrick.brick4[0];
                    fullBoard[i+yPos][n] = fill;

                    break;
                }
                case(2):
                {
                    i = lBrick.brick1[1];
                    n = lBrick.brick1[0];
                    fullBoard[i+yPos][n] = fill;
                    i = lBrick.brick2[1];
                    n = lBrick.brick2[0];
                    fullBoard[i+yPos][n] = fill;
                    i = lBrick.brick3[1];
                    n = lBrick.brick3[0];
                    fullBoard[i+yPos][n] = fill;
                    i = lBrick.brick4[1];
                    n = lBrick.brick4[0];
                    fullBoard[i+yPos][n] = fill;

                    break;
                }
                case(3):
                {
                    i = lBackBrick.brick1[1];
                    n = lBackBrick.brick1[0];
                    fullBoard[i+yPos][n] = fill;
                    i = lBackBrick.brick2[1];
                    n = lBackBrick.brick2[0];
                    fullBoard[i+yPos][n] = fill;
                    i = lBackBrick.brick3[1];
                    n = lBackBrick.brick3[0];
                    fullBoard[i+yPos][n] = fill;
                    i = lBackBrick.brick4[1];
                    n = lBackBrick.brick4[0];
                    fullBoard[i+yPos][n] = fill;

                    break;
                }
                case(4):
                {
                    i = tBrick.brick1[1];
                    n = tBrick.brick1[0];
                    fullBoard[i+yPos][n] = fill;
                    i = tBrick.brick2[1];
                    n = tBrick.brick2[0];
                    fullBoard[i+yPos][n] = fill;
                    i = tBrick.brick3[1];
                    n = tBrick.brick3[0];
                    fullBoard[i+yPos][n] = fill;
                    i = tBrick.brick4[1];
                    n = tBrick.brick4[0];
                    fullBoard[i+yPos][n] = fill;

                    break;
                }
                case(5):
                {
                    i = zBrick.brick1[1];
                    n = zBrick.brick1[0];
                    fullBoard[i+yPos][n] = fill;
                    i = zBrick.brick2[1];
                    n = zBrick.brick2[0];
                    fullBoard[i+yPos][n] = fill;
                    i = zBrick.brick3[1];
                    n = zBrick.brick3[0];
                    fullBoard[i+yPos][n] = fill;
                    i = zBrick.brick4[1];
                    n = zBrick.brick4[0];
                    fullBoard[i+yPos][n] = fill;

                    break;
                }
                case(6):
                {
                    i = zBackBrick.brick1[1];
                    n = zBackBrick.brick1[0];
                    fullBoard[i+yPos][n] = fill;
                    i = zBackBrick.brick2[1];
                    n = zBackBrick.brick2[0];
                    fullBoard[i+yPos][n] = fill;
                    i = zBackBrick.brick3[1];
                    n = zBackBrick.brick3[0];
                    fullBoard[i+yPos][n] = fill;
                    i = zBackBrick.brick4[1];
                    n = zBackBrick.brick4[0];
                    fullBoard[i+yPos][n] = fill;

                    break;
                }
                case(7):
                {
                    i = straightBrick.brick1[1];
                    n = straightBrick.brick1[0];
                    fullBoard[i+yPos][n] = fill;
                    i = straightBrick.brick2[1];
                    n = straightBrick.brick2[0];
                    fullBoard[i+yPos][n] = fill;
                    i = straightBrick.brick3[1];
                    n = straightBrick.brick3[0];
                    fullBoard[i+yPos][n] = fill;
                    i = straightBrick.brick4[1];
                    n = straightBrick.brick4[0];
                    fullBoard[i+yPos][n] = fill;

                    break;
                }
            }
}

vector<Brick::SquareBrick*> squareBricks = {};
vector<Brick::LBrick*> lBricks = {};
vector<Brick::LBackwardsBrick*> lBackwardsBricks = {};
vector<Brick::TBrick*> tBricks = {};
vector<Brick::ZBrick*> zBricks = {};
vector<Brick::ZBackwardsBrick*> zBackwardsBricks = {};
vector<Brick::StraightBrick*> straightBricks = {};

string brickType;

void fixedUpdate(map<int, vector<string>> fullBoard, int boardHeight)
{
    bool brickOnScreen = false;
    int yPos = 0;
    int usedBrick;
    bool inAir = true;
    vector<vector<int>> holder;

    while(game)
    {
        //DETERMINES HOW OFTEN UPDATES
      //VVVVVVVVVVVVVVVVVVVVVVVV
        int solutionTime = 350; // 1 second

        int timer;
        int counter = 0;
        DWORD interval = 20;	// 10th of a second

        DWORD start = GetTickCount(); // program starts

        for (timer = 0; timer < solutionTime; timer+=interval)
        {
            wait(interval);
            counter++;
        }



        if(!brickOnScreen)
        {
            usedBrick = 1 + rand() % 8;
            brickOnScreen = true;
            yPos += 1;

        }
        else if(brickOnScreen)
        {
            Brick::SquareBrick sqrBrick;
            Brick::LBrick lBrick;
            Brick::LBackwardsBrick lBackBrick;
            Brick::TBrick tBrick;
            Brick::ZBrick zBrick;
            Brick::ZBackwardsBrick zBackBrick;
            Brick::StraightBrick straightBrick;
            int i;
            int n;

            usedBrick = 1;

            switch(usedBrick)
            {
                case(1):
                {
                    brickType = "Square";

                    moveBlock(fullBoard, "[/]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    printBoard(fullBoard);
                    if(inAir)
                    {
                        moveBlock(fullBoard, "[ ]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    }

                    holder = sqrBrick.getLowest(sqrBrick.brick1, sqrBrick.brick2, sqrBrick.brick3, sqrBrick.brick4);

                    brickOnScreen = true;
                    break;
                }
                case(2):
                {
                    brickType = "L";

                    moveBlock(fullBoard, "[/]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    printBoard(fullBoard);
                    if(inAir)
                    {
                        moveBlock(fullBoard, "[ ]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    }

                    brickOnScreen = true;
                    break;
                }
                case(3):
                {
                    brickType = "LBack";

                    moveBlock(fullBoard, "[/]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    fullBoard[i+yPos][n] = "[/]";
                    printBoard(fullBoard);
                    if(inAir)
                    {
                        moveBlock(fullBoard, "[ ]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    }

                    brickOnScreen = true;
                    break;
                }
                case(4):
                {
                    brickType = "T";

                    moveBlock(fullBoard, "[/]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    printBoard(fullBoard);
                    if(inAir)
                    {
                        moveBlock(fullBoard, "[ ]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    }

                    brickOnScreen = true;
                    break;
                }
                case(5):
                {
                    brickType = "Z";

                    moveBlock(fullBoard, "[/]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    printBoard(fullBoard);
                    if(inAir)
                    {
                        moveBlock(fullBoard, "[ ]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    }

                    brickOnScreen = true;
                    break;
                }
                case(6):
                {
                    brickType = "ZBack";

                    moveBlock(fullBoard, "[/]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    fullBoard[i+yPos][n] = "[/]";
                    printBoard(fullBoard);
                    if(inAir)
                    {
                        moveBlock(fullBoard, "[ ]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    }

                    brickOnScreen = true;
                    break;
                }
                case(7):
                {
                    brickType = "Straight";

                    moveBlock(fullBoard, "[/]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    printBoard(fullBoard);
                    if(inAir)
                    {
                        moveBlock(fullBoard, "[ ]", usedBrick, yPos, sqrBrick, lBrick, lBackBrick, tBrick, zBrick, zBackBrick, straightBrick);
                    }

                    brickOnScreen = true;
                    break;
                }
            }
            //std::cout << holder[0][1];
            int position = holder[0][1];
            if(position + yPos == boardHeight-1)
            {
                brickOnScreen = false;
                yPos = 0;
                inAir = false;
                brickOnScreen = false;
            }
            else if(yPos < (boardHeight))
            {
                yPos += 1;
                inAir = true;
            }
        }
    }
    
}

int main() 
{   
    //time_t timeForRand = time(NULL);
    srand(static_cast<unsigned int>(time(NULL)));

    string response;

    std::ifstream readData("Win/main/libraries/map/highscore/highscore.txt");

    string red = "";

    std::getline(readData, red); 
    if(red == "")
    {
        std::ifstream readDData("main/libraries/map/highscore/highscore.txt");

        std::getline(readDData, red); 
    }
    highScore = std::stoi(red);

    readData.close();

    std::cout << "Welcome to Tetris \nWhen your Ready, type \"Y\" and enter: ";

    std::cin >> response;
    system("CLS");
    
    int boardWidth = 10;
    int boardHeight = 20;

    vector<string> board;
    map<int, vector<string>> fullBoard;
    fullBoard = createBoard(board, boardWidth, boardHeight, fullBoard);
    fixedUpdate(fullBoard, boardHeight);

    std::cin >> response;
    return 0;
}