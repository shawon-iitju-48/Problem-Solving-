/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<char, int> freq, freq1, g1, g2, g3;
        int flag = 0;
        for (int i = 0; i < 9; i++)
        {
            freq.clear(), freq1.clear();
            if (i == 3 or i == 6)
            {
                g1.clear();
                g2.clear();
                g3.clear();
            }
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                    freq[board[i][j]]++;
                if (freq[board[i][j]] > 1)
                {
                    flag = 1;
                    break;
                }
                if (board[j][i] != '.')
                    freq1[board[j][i]]++;
                if (freq1[board[j][i]] > 1)
                {
                    flag = 1;
                    break;
                }
                if (j < 3 and board[i][j] != '.')
                    g1[board[i][j]]++;
                if (g1[board[i][j]] > 1)
                {
                    flag = 1;
                    break;
                }
                if (j >= 3 and j < 6 and board[i][j] != '.')
                    g2[board[i][j]]++;
                if (g2[board[i][j]] > 1)
                {
                    flag = 1;
                    break;
                }
                if (j >= 6 and j < 9 and board[i][j] != '.')
                    g3[board[i][j]]++;
                if (g3[board[i][j]] > 1)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 1)
            return false;
        else
            return true;
    }
};
// @lc code=end
