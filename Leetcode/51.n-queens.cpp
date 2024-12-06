/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> ans;
    void mark(int newrow, int col, vector<string> &board)
    {
        int n = board.size();

        // Mark the entire row
        for (int i = 0; i < n; i++)
            board[newrow][i] = '.';

        // Mark the entire column
        for (int i = 0; i < n; i++)
            board[i][col] = '.';

        // Mark diagonals
        int a = newrow - 1, b = col + 1;
        while (a >= 0 && b < n)
        {
            board[a][b] = '.';
            a--;
            b++;
        }

        a = newrow + 1, b = col - 1;
        while (a < n && b >= 0)
        {
            board[a][b] = '.';
            a++;
            b--;
        }

        a = newrow - 1, b = col - 1;
        while (a >= 0 && b >= 0)
        {
            board[a][b] = '.';
            a--;
            b--;
        }

        a = newrow + 1, b = col + 1;
        while (a < n && b < n)
        {
            board[a][b] = '.';
            a++;
            b++;
        }

        // Place the queen
        board[newrow][col] = 'Q';
    }

    int queenplace(int col, vector<string> &board)
    {
        int n = board.size();

        if (col == n)
        {
            ans.push_back(board);
            return 0;
        }

        vector<string> original = board;
        int newrow = 0;
        int verdict;

        do
        {
            int flag = 0;
            for (int i = newrow; i < n; i++)
            {
                if (board[i][col] == '1')
                {
                    flag = 1;
                    newrow = i;
                    break;
                }
            }

            if (flag == 0)
                return -1;

            mark(newrow, col, board);

            verdict = queenplace(col + 1, board);
            if (verdict == -1)
            {
                original[newrow][col] = '.'; // Mark this spot as invalid
                board = original;
                newrow++;
            }

        } while (verdict == -1 && newrow < n);

        return -1;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<string> board(n, string(n, '1')); // Initialize the board with '1'
        queenplace(0, board);
        return ans;
    }
};
// @lc code=end
