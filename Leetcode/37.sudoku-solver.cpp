/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution
{
public:
    bool check(int &i, int &j, int &target, vector<vector<char>> &board)
    {
        for (int m = 0; m < 9; m++)
        {
            if (board[i][m] - '0' == target or board[m][j] - '0' == target)
                return false;
        }

        int row = i / 3, col = j / 3;
        row *= 3, col *= 3;
        for (int m = row; m < row + 3; m++)
        {
            for (int n = col; n < col + 3; n++)
            {
                if (board[m][n] - '0' == target)
                    return false;
            }
        }
        return true;
    }
    int sudokusolver(int idx, vector<pair<int, int>> &indices, vector<vector<char>> &board)
    {
        if (idx == indices.size())
            return 0;

        int i = indices[idx].first, j = indices[idx].second;

        for (int m = 1; m <= 9; m++)
        {
            if (check(i, j, m, board))
            {
                board[i][j] = m + '0';
                if (sudokusolver(idx + 1, indices, board) != -1)
                    return 0;
                board[i][j] = '.';
            }
        }
        return -1;
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        vector<pair<int, int>> indices;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    indices.push_back(make_pair(i, j));
            }
        }
        sudokusolver(0, indices, board);
    }
};
// @lc code=end
