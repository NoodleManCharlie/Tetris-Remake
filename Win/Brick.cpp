#include "include/Bricks.h"

#include <vector>
using std::vector;

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
vector<vector<int>> Brick::SquareBrick::getHighest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
{
    vector<vector<int>> hold;
    if(brick1[1] == 1)
    {
        hold.push_back(brick1);
    }
    if(brick2[1] == 1)
    {
        hold.push_back(brick2);
    }
    if(brick3[1] == 1)
    {
        hold.push_back(brick3);
    }
    if(brick4[1] == 1)
    {
        hold.push_back(brick4);
    }

    return hold;
}

vector<vector<int>> Brick::LBrick::getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
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
vector<vector<int>> Brick::LBrick::getHighest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
{
    vector<vector<int>> hold;
    if(brick1[1] == 2)
    {
        hold.push_back(brick1);
    }
    if(brick2[1] == 2)
    {
        hold.push_back(brick2);
    }
    if(brick3[1] == 2)
    {
        hold.push_back(brick3);
    }
    if(brick4[1] == 2)
    {
        hold.push_back(brick4);
    }

    return hold;
}

vector<vector<int>> Brick::LBackwardsBrick::getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
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
vector<vector<int>> Brick::LBackwardsBrick::getHighest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
{
    vector<vector<int>> hold;
    if(brick1[1] == 2)
    {
        hold.push_back(brick1);
    }
    if(brick2[1] == 2)
    {
        hold.push_back(brick2);
    }
    if(brick3[1] == 2)
    {
        hold.push_back(brick3);
    }
    if(brick4[1] == 2)
    {
        hold.push_back(brick4);
    }

    return hold;
}

vector<vector<int>> Brick::TBrick::getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
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
vector<vector<int>> Brick::TBrick::getHighest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
{
    vector<vector<int>> hold;
    if(brick1[1] == 1)
    {
        hold.push_back(brick1);
    }
    if(brick2[1] == 1)
    {
        hold.push_back(brick2);
    }
    if(brick3[1] == 1)
    {
        hold.push_back(brick3);
    }
    if(brick4[1] == 1)
    {
        hold.push_back(brick4);
    }

    return hold;
}

vector<vector<int>> Brick::ZBrick::getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
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
vector<vector<int>> Brick::ZBrick::getHighest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
{
    vector<vector<int>> hold;
    if(brick1[1] == 2)
    {
        hold.push_back(brick1);
    }
    if(brick2[1] == 2)
    {
        hold.push_back(brick2);
    }
    if(brick3[1] == 2)
    {
        hold.push_back(brick3);
    }
    if(brick4[1] == 2)
    {
        hold.push_back(brick4);
    }

    return hold;
}

vector<vector<int>> Brick::ZBackwardsBrick::getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
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
vector<vector<int>> Brick::ZBackwardsBrick::getHighest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
{
    vector<vector<int>> hold;
    if(brick1[1] == 1)
    {
        hold.push_back(brick1);
    }
    if(brick2[1] == 1)
    {
        hold.push_back(brick2);
    }
    if(brick3[1] == 1)
    {
        hold.push_back(brick3);
    }
    if(brick4[1] == 1)
    {
        hold.push_back(brick4);
    }

    return hold;
}

vector<vector<int>> Brick::StraightBrick::getLowest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
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
vector<vector<int>> Brick::StraightBrick::getHighest(vector<int> brick1, vector<int> brick2, vector<int> brick3, vector<int> brick4)
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