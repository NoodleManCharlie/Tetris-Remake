#ifndef BRICK_CLASS_H
#define BRICK_CLASS_H

#include <vector>
using std::vector;

class Brick
{
    public:
        class SquareBrick {
            public:
                vector<int> brick1 = {0, 0}; 
                vector<int> brick2 = {1, 0}; 
                vector<int> brick3 = {0, 1}; 
                vector<int> brick4 = {1, 1}; 

                vector<vector<int>> getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4);

        };

        class LBrick {
            public:
                vector<int> brick1 = {0, 0}; 
                vector<int> brick2 = {0, 1}; 
                vector<int> brick3 = {0, 2}; 
                vector<int> brick4 = {1, 2}; 

                vector<vector<int>> getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4);
        };

        class LBackwardsBrick {
            public:
                vector<int> brick1 = {0, 0}; 
                vector<int> brick2 = {1, 0}; 
                vector<int> brick3 = {0, 1}; 
                vector<int> brick4 = {0, 2}; 

                vector<vector<int>> getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4);
        };

        class TBrick {
            public:
                vector<int> brick1 = {0, 0}; 
                vector<int> brick2 = {1, 0}; 
                vector<int> brick3 = {2, 0}; 
                vector<int> brick4 = {1, 1}; 

                vector<vector<int>> getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4);
        };

        class ZBrick {
            public:
                vector<int> brick1 = {0, 0}; 
                vector<int> brick2 = {0, 1}; 
                vector<int> brick3 = {1, 1}; 
                vector<int> brick4 = {1, 2}; 

                vector<vector<int>> getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4);
        };

        class ZBackwardsBrick {
            public:
                vector<int> brick1 = {0, 0}; 
                vector<int> brick2 = {1, 0}; 
                vector<int> brick3 = {1, 1}; 
                vector<int> brick4 = {2, 1}; 

                vector<vector<int>> getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4);
        };

        class StraightBrick {
            public:
                vector<int> brick1 = {0, 0}; 
                vector<int> brick2 = {1, 0}; 
                vector<int> brick3 = {2, 0}; 
                vector<int> brick4 = {3, 0}; 

                vector<vector<int>> getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4);
        };
};

#endif