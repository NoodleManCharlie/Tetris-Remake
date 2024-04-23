#ifndef BLOCKS_CLASS_H
#define BLOCKS_CLASS_H

#include <time.h> 
#include <cstdlib>
#include <vector>
using std::vector;

class Blocks
{
    public:
        int blockSize = 4; //Tetris

        vector<vector<int>> curBlockPos;
        vector<vector<int>> curBlockSize;

        vector<vector<int>> stashBlockPos;
        vector<vector<int>> stashBlockSize;

        //void blocksInit();

        //void setCurrentBlock();
        //void setStashBlock();

        void blocksInit()
        {
            srand(static_cast<unsigned int>(time(NULL)));
            setStashBlock();
        }

        void setCurrentBlock()
        {
            Blocks::curBlockPos = stashBlockPos;
            setStashBlock();
        }

        void setStashBlock()
        {
            bool checking;

            int xIncrease;
            int yIncrease;

            vector<int> tempStashPos;

            Blocks::stashBlockPos = {{0, 0}};
            int curSize;

            for (curSize = 0; curSize < Blocks::blockSize; curSize++)
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
};
/*
        class SquareBrick {
            public:
                vector<int> brick1 = {0, 0}; 
                vector<int> brick2 = {1, 0}; 
                vector<int> brick3 = {0, 1}; 
                vector<int> brick4 = {1, 1}; 

                vector<vector<int>> getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4);
                vector<vector<int>> getHighest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4);

        };
*/

#endif