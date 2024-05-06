#include "include/Blocks.h"

#include <time.h> 
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <sstream>
using std::vector;


void Blocks::blocksInit()
{
    srand(static_cast<unsigned int>(time(NULL)));
    setStashBlock();
    setCurrentBlock();
    std::cout << "Initialized";
}

void Blocks::setCurrentBlock()
{
    Blocks::curBlockPos = stashBlockPos;
    setStashBlock();
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

        xIncrease = (rand() % 4) - 2;
        yIncrease = (rand() % 4) - 2;

        tempStashPos = {tempStashBlockPos[curSize][0] + xIncrease, tempStashBlockPos[curSize][1] + yIncrease};

        while(checking)
        {
            bool fail;

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
                xIncrease = rand() % 4 - 2;
                yIncrease = rand() % 4 - 2;

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
  
    vector<int> xNegatives;
    vector<int> yNegatives;
    int xAdjust = 0;
    int yAdjust = 0;

    //xNegatives.assign(blockSize, 0);
    //yNegatives.assign(blockSize, 0);

    //Finding Negative in the x and y category to be later used in the next for loop
    for(int i = 0; i < blockSize; i++)
    {
        std::cout << tempStashBlockPos[i][0] << "\n";
        std::cout << tempStashBlockPos[i][1] << "\n";
        
        if(tempStashBlockPos[i][0] < 0)
        {
            xNegatives.insert(xNegatives.end(), tempStashBlockPos[i][0]);
            std::cout << xNegatives[i] << "\n";
        }
        if(tempStashBlockPos[i][1] < 0)
        {
            yNegatives.insert(yNegatives.end(), tempStashBlockPos[i][1]);
            std::cout << yNegatives[i] << "\n";
        }
    }

    std::string response;
    std::cin >> response;

    int xNegativeOne = xNegatives[0];
    int yNegativeOne = yNegatives[0];
    int xNegativeTwo;
    int yNegativeTwo;

    //Finding the lowest x negative number
    for(int i = 1; i < xNegatives.size(); i++)
    {
        xNegativeTwo = xNegatives[i];

        if(xNegativeOne <= xNegativeTwo)
        {
            xNegativeOne = xNegativeTwo;
        }
    }
    xAdjust = xNegativeOne;

    //Finding the lowest x negative number
    for(int i = 1; i < yNegatives.size(); i++)
    {
        yNegativeTwo = yNegatives[i];

        if(yNegativeOne <= yNegativeTwo)
        {
            yNegativeOne = yNegativeTwo;
        }
    }
    yAdjust = yNegativeOne;

    //Adjusting the block positions to be in the positives
    for(int i = 0; i < curSize; i++)
    {
        tempStashBlockPos[i][0] = tempStashBlockPos[i][0] + abs(xAdjust);
        tempStashBlockPos[i][1] = tempStashBlockPos[i][1] + abs(yAdjust);
    }

    std::cout << "Block Positions: \n";
    std::cout << tempStashBlockPos[0][0] << "\n" << tempStashBlockPos[0][1] << "\n"  << tempStashBlockPos[1][0] << "\n" << tempStashBlockPos[1][1] << "\n" << tempStashBlockPos[2][0] << "\n" << tempStashBlockPos[2][1] << "\n" << tempStashBlockPos[3][0] << "\n" << tempStashBlockPos[3][1] << "\n";
    //stashBlockPos = tempStashBlockPos;

}

void Blocks::getWidth()
{
    for(int brick = 0; brick < curBlockPos.size(); brick++)
    {
        //curBlockPos
    }
}

void Blocks::getHeight()
{
    
}

void Blocks::rotate()
{
    //curBlockPos
}