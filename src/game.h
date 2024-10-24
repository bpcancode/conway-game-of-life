#pragma once
#include "grid.h"

class Game
{
public:
    Game();
    int state = 0;
    void Draw();
    void Update();
    void UpdateState();

private:
    int gameSate;
    Grid grid = Grid(100, 100);
};

