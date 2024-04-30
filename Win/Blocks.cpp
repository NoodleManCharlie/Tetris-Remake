#include "include/Blocks.h"

#include <time.h> 
#include <iostream>
#include <cstdlib>
#include <vector>
using std::vector;


void Blocks::blocksInit()
{
    srand(static_cast<unsigned int>(time(NULL)));
    setStashBlock();
    std::cout << "Initialized";
}

void Blocks::setCurrentBlock()
{
    Blocks::curBlockPos = stashBlockPos;
    setStashBlock();
}

void Blocks::setStashBlock()
{
    bool checking;

    int xIncrease;
    int yIncrease;

    vector<int> tempStashPos;

    Blocks::stashBlockPos = {{0, 0}};
    int curSize;

    for (curSize = -1; curSize < Blocks::blockSize; curSize++)
    {
        checking = true;

        xIncrease = rand() % 4 - 2;
        yIncrease = rand() % 4 - 2;

        tempStashPos = {stashBlockPos[curSize][0] + xIncrease, stashBlockPos[curSize][1] + yIncrease};

        while(checking)
        {
            bool fail;

            for (int i = 0; i < curSize; i++)
            {
                if(stashBlockPos[i] == tempStashPos)
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

                tempStashPos = {stashBlockPos[curSize][0] + xIncrease, stashBlockPos[curSize][1] + yIncrease};
            }
            else
            {
                checking = false;
            }
        }
    }
    
}


/*
vector<vector<int>> Brick::SquareBrick::getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
{
    vector<vector<int>> hold;
    if(brick1[1] == 0)
    {
        hold.push_back(brick1);
    }
    if(brick2[1] == 0)
    {
        hold.push_back(brick2);
    }
    if(brick3[1] == 0)
    {
        hold.push_back(brick3);
    }
    if(brick4[1] == 0)
    {
        hold.push_back(brick4);
    }

    return hold;
}
*/