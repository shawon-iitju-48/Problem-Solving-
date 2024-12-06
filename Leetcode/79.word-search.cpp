/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution
{
public:
    int check(int i, int j, vector<vector<char>> &board, int k, string &word)
    {
        if (board[i][j] != word[k])
            return -1;
        char temp = board[i][j];
        board[i][j] = '\0';
        k++;
        if (k == word.size())
            return 0;
        if (i - 1 >= 0 and check(i - 1, j, board, k, word) == 0)
            return 0;
        else if (i + 1 < board.size() and check(i + 1, j, board, k, word) == 0)
            return 0;
        else if (j - 1 >= 0 and check(i, j - 1, board, k, word) == 0)
            return 0;
        else if (j + 1 < board[i].size() and check(i, j + 1, board, k, word) == 0)
            return 0;
        board[i][j] = temp;
        return -1;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                if (word[0] == board[i][j] and check(i, j, board, 0, word) != -1)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
