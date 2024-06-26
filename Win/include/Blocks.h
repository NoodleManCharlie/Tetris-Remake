#ifndef BLOCKS_CLASS_H
#define BLOCKS_CLASS_H

#include <time.h> 
#include <cstdlib>
#include <vector>
#include <string>
#include <map>

#include "Commands.h"

using std::vector;
using std::map;
using std::string;



class Blocks
{
    public:
        int blockSize = 4; //Tetris
        
        int boardWidth = 10;
        int boardHeight = 20;

        int xAdd;

        vector<int> bn;
        vector<int> bi;
        int bxAdd;
        int byPos;

        bool brickOnScreen = false;
        int yPos = 0;
        bool inAir = true;
        vector<vector<int>> holder;
        vector<vector<int>> heights;

        vector<vector<int>> curBlockPos;
        //vector<vector<int>> curBlockSize;

        vector<vector<int>> stashBlockPos;
        //vector<vector<int>> stashBlockSize;

        Commands command;

        void blocksInit();

        void setCurrentBlock();
        void setStashBlock();

        int getWidth();
        int getHeight();

        void rotate();

        vector<vector<int>> getTop();
        vector<vector<int>> getBottom();

        void setCursorPosition(int x, int y);

        void moveBlock(map<int, vector<string>> &fullBoard, string fill, string remove, int yPos);
};

#endif