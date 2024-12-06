/*
 * @lc app=leetcode id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

// @lc code=start
class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        queue<pair<int, int>> q;
        q.push({0, 1});
        vector<bool> vis(n * n + 1, false);
        vis[1] = true;

        while (!q.empty())
        {
            int step = q.front().first;
            int node = q.front().second;
            q.pop();

            if (node == n * n)
                return step;

            for (int i = node + 1; i <= min(node + 6, n * n); i++)
            {
                int next = i, row = n - 1 - (next - 1) / n;
                int col = (next - 1) % n;

                if (row % 2 == n % 2)
                    col = n - 1 - col;

                if (board[row][col] != -1)
                    next = board[row][col];

                if (!vis[next])
                {
                    vis[next] = true;
                    q.push({step + 1, next});
                }
            }
        }
        return -1;
    }
};

// @lc code=end