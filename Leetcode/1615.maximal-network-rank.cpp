/*
 * @lc app=leetcode id=1615 lang=cpp
 *
 * [1615] Maximal Network Rank
 */

// @lc code=start
class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<int> count(n, 0);
        vector<vector<bool>> isConnected(n, vector<bool>(n, false));
        int mx = 0;
        for (int i = 0; i < roads.size(); i++)
        {
            count[roads[i][0]]++;
            count[roads[i][1]]++;
            isConnected[roads[i][0]][roads[i][1]] = true;
            isConnected[roads[i][1]][roads[i][0]] = true;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int cnt = count[i] + count[j];
                if (isConnected[i, j])
                    cnt--;
                mx = max(mx, cnt);
            }
        }
        return mx;
    }
};
// @lc code=end
