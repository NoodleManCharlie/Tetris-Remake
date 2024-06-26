#include "include/Blocks.h"

#include <time.h> 
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <sstream>
#include <string>
#include <map>

#include "include/commands.h"

using std::vector;
using std::string;
using std::map;


void Blocks::blocksInit()
{
    srand(static_cast<unsigned int>(time(NULL)));
    setStashBlock();
    setCurrentBlock();
    //std::cout << "Initialized";
}

void Blocks::setCurrentBlock()
{
    Blocks::curBlockPos = stashBlockPos;
    setStashBlock();

    bn.assign(blockSize, 0);
    bi.assign(blockSize, 0);
}

void Blocks::setStashBlock()
{
    vector<vector<int>> tempStashBlockPos;
    tempStashBlockPos.assign(blockSize, {0, 0});

    bool checking;

    int xIncrease;
    int yIncrease;

    vector<int> tempStashPos = {};

    int curSize;

    //Randomzing and assigning positions to a temporary stashBlockPos
    for (curSize = 0; curSize < blockSize; curSize++)
    {
        checking = true;
        xIncrease = 0;
        yIncrease = 0;
        int h = rand() % 3;

        while(h == 0)
        {
            h = rand() % 3;
        }

        if(h == 1)
        {
            //xIncrease
            xIncrease = (rand() % 4);
            
            while(xIncrease == 0 || xIncrease == 2)
            {
                xIncrease = (rand() % 4);
            }

            xIncrease -= 2;
        }
        else
        {
            //yIncrease
            yIncrease = (rand() % 4);

            while(yIncrease == 0 || yIncrease == 2)
            {
                yIncrease = (rand() % 4);
            }

            yIncrease -= 2;
        }

        tempStashPos = {tempStashBlockPos[curSize][0] + xIncrease, tempStashBlockPos[curSize][1] + yIncrease};

        while(checking)
        {
            bool fail = false;

            for (int i = 0; i < curSize; i++)
            {
                if(tempStashBlockPos[i] == tempStashPos)
                {
                    checking = true;
                    fail = true;
                }
                else
                {
                    continue;
                }
            }

            if(fail)
            {
                h = rand() % 3;

                while(h == 0)
                {
                    h = rand() % 3;
                }

                if(h == 1)
                {
                    //xIncrease
                    xIncrease = (rand() % 4);
                    
                    while(xIncrease == 0 || xIncrease == 2)
                    {
                        xIncrease = (rand() % 4);
                    }

                    xIncrease -= 2;
                }
                else
                {
                    //yIncrease
                    yIncrease = (rand() % 4);

                    while(yIncrease == 0 || yIncrease == 2)
                    {
                        yIncrease = (rand() % 4);
                    }

                    yIncrease -= 2;
                }

                tempStashPos = {tempStashBlockPos[curSize][0] + xIncrease, tempStashBlockPos[curSize][1] + yIncrease};
            }
            else
            {
                checking = false;
            }
        }

        if(curSize+1 < blockSize)
        {
            tempStashBlockPos[curSize+1][0] = tempStashPos[0];
            tempStashBlockPos[curSize+1][1] = tempStashPos[1];
        }
    }

    vector<int> xNegatives; //(blockSize)
    vector<int> yNegatives; //(blockSize)
    int xAdjust = 0;
    int yAdjust = 0;

    xNegatives.assign(blockSize, 0);
    yNegatives.assign(blockSize, 0);

    //Finding Negative in the x and y category to be later used in the next for loop
    for(int i = 0; i < blockSize; i++)
    {
        
        if(tempStashBlockPos[i][0] < 0)
        {
            //xNegatives.insert(xNegatives.begin(), tempStashBlockPos[i][0]);
            //xNegatives.push_back(tempStashBlockPos[i][0]);
            xNegatives[i] = tempStashBlockPos[i][0];
        }
        if(tempStashBlockPos[i][1] < 0)
        {
            //yNegatives.insert(yNegatives.begin(), tempStashBlockPos[i][1]);
            //yNegatives.push_back(tempStashBlockPos[i][1]);
            yNegatives[i] = tempStashBlockPos[i][1];
        } 
    }

    int xNegativeOne = xNegatives[0];
    int yNegativeOne = yNegatives[0];
    int xNegativeTwo;
    int yNegativeTwo;

    //Finding the lowest x negative number
    for(int i = 1; i < xNegatives.size(); i++)
    {
        xNegativeTwo = xNegatives[i];

        if(xNegativeOne >= xNegativeTwo)
        {
            xNegativeOne = xNegativeTwo;
        }
    }
    xAdjust = xNegativeOne - 1;

    //Finding the lowest x negative number
    for(int i = 1; i < yNegatives.size(); i++)
    {
        yNegativeTwo = yNegatives[i];

        if(yNegativeOne >= yNegativeTwo)
        {
            yNegativeOne = yNegativeTwo;
        }
    }
    yAdjust = yNegativeOne - 1;

    //Adjusting the block positions to be in the positives
    for(int i = 0; i < curSize; i++)
    {
        tempStashBlockPos[i][0] = tempStashBlockPos[i][0] + abs(xAdjust);
        tempStashBlockPos[i][1] = tempStashBlockPos[i][1] + abs(yAdjust);
    }
    
    stashBlockPos = tempStashBlockPos;

}

int Blocks::getWidth()
{
    int widthBrickOne = curBlockPos[0][0];
    int widthBrickTwo;

    for(int brick = 1; brick < curBlockPos.size(); brick++)
    {
        widthBrickTwo = curBlockPos[brick][0];
        
        if(widthBrickOne < widthBrickTwo)
        {
            widthBrickOne = widthBrickTwo;
        }
    }

    //std::cout << "Width: " << widthBrickOne;
    return widthBrickOne;
}

int Blocks::getHeight()
{
    int heightBrickOne = curBlockPos[0][1];
    int heightBrickTwo;

    for(int brick = 1; brick < curBlockPos.size(); brick++)
    {
        heightBrickTwo = curBlockPos[brick][1];
        
        if(heightBrickOne < heightBrickTwo)
        {
            heightBrickOne = heightBrickTwo;
        }
    }

    return heightBrickOne;
}

void Blocks::rotate()
{
    int width = getWidth();
    int height = getHeight();

    int hold;

    if(!(xAdd == (boardWidth - width - (height - 2))))
    {
        for(int i = 0; i < blockSize; i++)
        {
            curBlockPos[i][0] = width - (curBlockPos[i][0] - 1);

            hold = curBlockPos[i][1];

            curBlockPos[i][1] = curBlockPos[i][0];
            curBlockPos[i][0] = hold;
        }
    }
} 

vector<vector<int>> Blocks::getTop()
{
    vector<vector<int>> hold;
    int height = getHeight();

    for(int i = 0; i < blockSize; i++)
    {
        if(curBlockPos[i][1] == height)
        {
            hold.push_back(curBlockPos[i]);
        }
    }

    return hold;
}

vector<vector<int>> Blocks::getBottom()
{
    vector<vector<int>> hold;

    for(int i = 0; i < blockSize; i++)
    {
        if(curBlockPos[i][1] == 1)
        {
            hold.push_back(curBlockPos[i]);
        }
    }

    return hold;
}

void Blocks::moveBlock(map<int, vector<string>> &fullBoard, string fill, string remove, int yPos)
{
    command.setCursorPosition(0, 0);

    //10 <- Info, *3 <- scale, -1 <- put in middle
    int i;
    int n;

    if(inAir)
    {
        for(int b = 0; b < blockSize; b++)
        {
            i = bi[b];
            n = bn[b];

            //fullBoard[bi[b] + yPos][bn[b] + xAdd] = remove;

            command.setCursorPosition(((n + bxAdd) * 3) + 10, i + byPos);
            std::cout << remove;
            command.setCursorPosition(0, 0);
        }
    }

    for(int b = 0; b < blockSize; b++)
    {
        n = curBlockPos[b][0];
        i = curBlockPos[b][1];

        //fullBoard[i + yPos][n + xAdd] = fill;

        command.setCursorPosition(((n + xAdd) * 3) + 10, i + yPos);
        std::cout << fill;
        command.setCursorPosition(0, 0);

        bi[b] = curBlockPos[b][1];
        bn[b] = curBlockPos[b][0];
        bxAdd = xAdd;
        byPos = yPos;
    }
}