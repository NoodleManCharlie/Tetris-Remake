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

        void getWidth();
        void getHeight();

        void rotate();
};

#endif