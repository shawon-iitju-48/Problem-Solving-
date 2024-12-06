/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution
{
public:
    void mark(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &board)
    {
        if (i < 0 or i >= board.size() or j < 0 or j >= board[0].size() or board[i][j] == 'X' or visited[i][j] == false)
            return;

        visited[i][j] = false;

        mark(i, j - 1, visited, board);
        mark(i - 1, j, visited, board);
        mark(i, j + 1, visited, board);
        mark(i + 1, j, visited, board);
    }
    void solve(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, true));
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O' and visited[i][0])
                mark(i, 0, visited, board);
            if (board[i][n - 1] == 'O' and visited[i][n - 1])
                mark(i, n - 1, visited, board);
        }
        for (int i = 0; i < n; i++)
        {
            if (board[0][i] == 'O' and visited[0][i])
                mark(0, i, visited, board);
            if (board[m - 1][i] == 'O' and visited[m - 1][i])
                mark(m - 1, i, visited, board);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] and board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
// @lc code=end
