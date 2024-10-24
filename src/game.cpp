#include "game.h"
#include <raylib.h>

Game::Game()
{
    gameSate = 0;
}

void Game::Draw()
{
    grid.Draw();
}

void Game::Update()
{
    if(gameSate == 0)
    {
        grid.DrawOnCell();
    } else if(gameSate == 1)
    {
        grid.UpdateCell();
    }
}

void Game::UpdateState()
{
    if(IsKeyPressed(KEY_SPACE))
    {
        gameSate = 1;
    }
    if(IsKeyPressed(KEY_R))
    {
        gameSate = 0;
        grid.initilize();
    }
}
