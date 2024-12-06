/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */

// @lc code=start
class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int cnt = 0, j;
        for (int i = 0; i < board[0].size(); i++)
        {
            for (int j = 0; j < board.size(); j++)
            {
                if (board[j][i] == 'X')
                {
                    if (j > 0 and board[j - 1][i] == '.')
                    {
                        if (i > 0 and board[j][i - 1] == '.')
                            cnt++;
                        else if (i == 0)
                            cnt++;
                    }
                    else if (j == 0)
                    {
                        if (i > 0 and board[j][i - 1] == '.')
                            cnt++;
                        else if (i == 0)
                            cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
// @lc code=end
