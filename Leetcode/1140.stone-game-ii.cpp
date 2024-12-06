/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
class Solution
{
public:
    int dpmax[100][105], dpmin[100][105];
    int minimizeBob(int idx, int m, vector<int> &piles)
    {
        if (idx >= piles.size())
            return 0;

        if (dpmin[idx][m] != -1)
            return dpmin[idx][m];

        int res = INT_MAX;
        for (int i = idx; i < idx + (2 * m) && i < piles.size(); i++)
            res = min(res, maximizeAlice(i + 1, max(i - idx + 1, m), piles));

        return dpmin[idx][m] = res;
    }
    int maximizeAlice(int idx, int m, vector<int> &piles)
    {
        if (idx >= piles.size())
            return 0;

        if (dpmax[idx][m] != -1)
            return dpmax[idx][m];

        int res = 0, sum = 0;
        for (int i = idx; i < idx + (2 * m) && i < piles.size(); i++)
        {
            sum += piles[i];
            res = max(res, sum + minimizeBob(i + 1, max(i - idx + 1, m), piles));
        }
        return dpmax[idx][m] = res;
    }

    int stoneGameII(vector<int> &piles)
    {
        memset(dpmax, -1, sizeof(dpmax));
        memset(dpmin, -1, sizeof(dpmin));
        return maximizeAlice(0, 1, piles);
    }
};
// @lc code=end
