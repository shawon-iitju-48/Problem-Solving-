/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int m = maze.size(), n = maze[0].size();
        vector<pair<int, int>> directions = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';

        while (!q.empty())
        {
            int i = q.front()[0], j = q.front()[1], level = q.front()[2];
            q.pop();

            if ((i == 0 or j == 0 or i == m - 1 or j == n - 1) and (i != entrance[0] or j != entrance[1]))
                return level;

            for (int d = 0; d < 4; d++)
            {
                int newI = i + directions[d].first;
                int newJ = j + directions[d].second;
                if (newI >= 0 and newI < m and newJ >= 0 and newJ < n and maze[newI][newJ] == '.')
                {
                    q.push({newI, newJ, level + 1});
                    maze[newI][newJ] = '+';
                }
            }
        }
        return -1;
    }
};
// @lc code=end
