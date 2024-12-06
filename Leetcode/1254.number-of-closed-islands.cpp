class Solution
{
public:
    void mark(int i, int j, vector<vector<int>> &grid)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 0)
            return;

        grid[i][j] = 1; // Mark as visited
        mark(i - 1, j, grid);
        mark(i + 1, j, grid);
        mark(i, j - 1, grid);
        mark(i, j + 1, grid);
    }

    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        // Mark all open islands touching borders
        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0)
                mark(i, 0, grid);
            if (grid[i][n - 1] == 0)
                mark(i, n - 1, grid);
        }
        for (int j = 0; j < n; j++)
        {
            if (grid[0][j] == 0)
                mark(0, j, grid);
            if (grid[m - 1][j] == 0)
                mark(m - 1, j, grid);
        }

        // Count remaining closed islands
        int closedIslands = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    closedIslands++;
                    mark(i, j, grid);
                }
            }
        }

        return closedIslands;
    }
};
