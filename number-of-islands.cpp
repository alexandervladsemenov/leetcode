#include "common.h"

int numIslands(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &visited)
{
    visited[i][j] = 1;
    for (int ii = i - 1; ii <= i + 1; ii++)
    {
        for (int jj = j - 1; jj <= j + 1; jj++)
        {

            if (ii < 0)
                continue;
            if (jj < 0)
                continue;
            if (ii >= grid.size())
                continue;
            if (jj >= grid[0].size())
                continue;
            if (ii - i != 0 && jj - j != 0)
                continue;
            if (grid[ii][jj] == '1' && visited[ii][jj] == 0)
            {
                numIslands(ii, jj, grid, visited);
            }
        }
    }
    return 1;
}

int numIslands(vector<vector<char>> &grid)
{
    std::vector<std::vector<int>> visited(grid.size());
    for (auto &v : visited)
    {
        v = std::vector<int>(grid[0].size());
    }
    int islands = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1' && visited[i][j] == 0)
            {
                islands += numIslands(i, j, grid, visited);
            }
        }
    }
    return islands;
}

int main()
{
    // vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    vector<vector<char>> grid = {{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    std::cout << numIslands(grid) << std::endl;
    return 0;
}