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
    std::cout << "Stashed Block" << "\n";
    setCurrentBlock();
    std::cout << "Set Current Block" << "\n";
    std::cout << "Initialized";
}

void Blocks::setCurrentBlock()
{
    Blocks::curBlockPos = stashBlockPos;
    setStashBlock();
}

void Blocks::setStashBlock()
{
    std::cout << "start" << "\n";
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

        xIncrease = (rand() % 4);
        yIncrease = (rand() % 4);

        while(xIncrease == 0)
        {
            xIncrease = (rand() % 4);
        }
        while(yIncrease == 0)
        {
            yIncrease = (rand() % 4);
        }

        xIncrease -= 2;
        yIncrease -= 2;

        std::cout << "X & Y Increase Assigned" << "\n";

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
                xIncrease = (rand() % 4);
                yIncrease = (rand() % 4);

                while(xIncrease == 0)
                {
                    xIncrease = (rand() % 4);
                }
                while(yIncrease == 0)
                {
                    yIncrease = (rand() % 4);
                }

                xIncrease -= 2;
                yIncrease -= 2;

                std::cout << "X & Y Checked Increase Assigned" << "\n";

                tempStashPos = {tempStashBlockPos[curSize][0] + xIncrease, tempStashBlockPos[curSize][1] + yIncrease};
                std::cout << "Temp Pos Assigned" << "\n";
            }
            else
            {
                checking = false;
            }
        }
        std::cout << "Checked" << "\n";

        if(curSize+1 < blockSize)
        {
            tempStashBlockPos[curSize+1][0] = tempStashPos[0];
            tempStashBlockPos[curSize+1][1] = tempStashPos[1];
        }
        std::cout << "Assigned" << "\n";
    }
  
    std::cout << "Block Pos made" << "\n";

    vector<int> xNegatives; //(blockSize)
    vector<int> yNegatives; //(blockSize)
    int xAdjust = 0;
    int yAdjust = 0;

    xNegatives.assign(blockSize, 0);
    yNegatives.assign(blockSize, 0);

    //Finding Negative in the x and y category to be later used in the next for loop
    for(int i = 0; i < blockSize; i++)
    {
        std::cout << "I: " << i << "\n";
        std::cout << "X Position: " << tempStashBlockPos[i][0] << "\n";
        std::cout << "Y Position: " << tempStashBlockPos[i][1] << "\n";
        
        if(tempStashBlockPos[i][0] < 0)
        {
            //xNegatives.insert(xNegatives.begin(), tempStashBlockPos[i][0]);
            //xNegatives.push_back(tempStashBlockPos[i][0]);
            xNegatives[i] = tempStashBlockPos[i][0];
            std::cout << "X Negatives: " << xNegatives[i] << "\n";
        }
        if(tempStashBlockPos[i][1] < 0)
        {
            //yNegatives.insert(yNegatives.begin(), tempStashBlockPos[i][1]);
            //yNegatives.push_back(tempStashBlockPos[i][1]);
            yNegatives[i] = tempStashBlockPos[i][1];
            std::cout << "Y Negatives: " << yNegatives[i] << "\n";
        } 
    }

    int xNegativeOne = xNegatives[0];
    int yNegativeOne = yNegatives[0];
    int xNegativeTwo;
    int yNegativeTwo;

    //Finding the lowest x negative number
    for(int i = 1; i < xNegatives.size(); i++)
    {
        std::cout << "X Negative One: " << xNegativeOne << "\n";
        std::cout << "X Negative Two: " << xNegativeTwo << "\n";
        xNegativeTwo = xNegatives[i];

        if(xNegativeOne >= xNegativeTwo)
        {
            xNegativeOne = xNegativeTwo;
        }
        std::cout << "X Negative One: " << xNegativeOne << "\n";
        std::cout << "X Negative Two: " << xNegativeTwo << "\n";
    }
    xAdjust = xNegativeOne - 1;

    //Finding the lowest x negative number
    for(int i = 1; i < yNegatives.size(); i++)
    {
        std::cout << "Y Negative One: " << yNegativeOne << "\n";
        std::cout << "Y Negative Two: " << yNegativeTwo << "\n";
        yNegativeTwo = yNegatives[i];

        if(yNegativeOne >= yNegativeTwo)
        {
            yNegativeOne = yNegativeTwo;
        }
        std::cout << "Y Negative One: " << yNegativeOne << "\n";
        std::cout << "Y Negative Two: " << yNegativeTwo << "\n";
    }
    yAdjust = yNegativeOne - 1;

    std::cout << "xAdjust: " << xAdjust << "\n";
    std::cout << "yAdjust: " << yAdjust << "\n";

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