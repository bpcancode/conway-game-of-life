#include "grid.h"
#include <raylib.h>

Grid::Grid(int row, int col)
{
    this->row = row;
    this->col = col;
    cellSize = GetScreenWidth() / col;

    initilize();
}

void Grid::Draw()
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            Color color = grid[i][j] == 1 ? BLACK : WHITE;
            DrawRectangle(i *cellSize + 1, j * cellSize + 1, cellSize-1, cellSize-1, color);
        }
    }
}

void Grid::SetCell(int row, int col)
{
    grid[row][col] = 1;
}

void Grid::DrawOnCell()
{
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON) || IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
        int x = GetMouseX() / cellSize;
        int y = GetMouseY() / cellSize;
        if(x >= 0 && x < row && y >= 0 && y < col){
            grid[x][y] = 1;
        }
    }
}

void Grid::UpdateCell()
{
    std::vector<std::vector<int>> newGrid = grid;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int neighbors = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) {
                        continue;
                    }
                    int x_pos = i + x;
                    int y_pos = j + y;
                    if (x_pos >= 0 && x_pos < row && y_pos >= 0 && y_pos < col) {
                        neighbors += grid[x_pos][y_pos];
                    }
                }
            }
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                }
            } else {
                if (neighbors == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
    }
    grid = newGrid;
}

void Grid::initilize()
{
    if(grid.size() > 0)
    {
        for (auto& row : grid) std::fill(row.begin(), row.end(), 0);
    } 
    else
    {
        grid.resize(row);
        for(int i =0; i < row; i++)
        {
            grid[i].resize(col, 0);
        }
    }
}
