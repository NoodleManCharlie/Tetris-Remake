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

        void blocksInit();

        void setCurrentBlock();
        void setStashBlock();

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

};

#endif