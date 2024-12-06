/*
 * @lc app=leetcode id=1958 lang=cpp
 *
 * [1958] Check if Move is Legal
 */

// @lc code=start
class Solution
{
public:
    bool check(int row, int col, int rf, int cf, vector<vector<char>> &board, char maincolor, char targetcolor)
    {
        int i = row + rf, j = col + cf, sum = 0;
        while (i >= 0 and j >= 0 and i < 8 and j < 8)
        {
            if (board[i][j] == maincolor)
            {
                if (sum == 0)
                    return false;
                return true;
            }
            if (board[i][j] == '.')
                return false;

            if (board[i][j] == targetcolor)
                sum++;

            i = i + rf, j = j + cf;
        }
        return false;
    }
    bool checkMove(vector<vector<char>> &board, int rMove, int cMove, char color)
    {
        char targetcolor = 'W';
        if (color == 'W')
            targetcolor = 'B';

        vector<pair<int, int>> directions = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
        for (auto [rf, cf] : directions)
        {
            if (check(rMove, cMove, rf, cf, board, color, targetcolor))
                return true;
        }
        return false;
    }
};
// @lc code=end
