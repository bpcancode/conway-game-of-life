#pragma once
#include <vector>

class Grid
{
public:
    Grid(int row, int col);
    void Draw();
    void SetCell(int row, int col);
    void DrawOnCell();
    void UpdateCell();
    void initilize();

private:
    int row;
    int col;
    int cellSize;
    std::vector<std::vector<int>> grid;
};