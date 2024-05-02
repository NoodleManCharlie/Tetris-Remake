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

    for (curSize = 0; curSize < blockSize; curSize++)
    {
        checking = true;

        xIncrease = rand() % 4 - 2;
        yIncrease = rand() % 4 - 2;

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
    
    stashBlockPos = tempStashBlockPos;
}