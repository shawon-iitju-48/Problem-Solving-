/*
 * @lc app=leetcode id=1899 lang=cpp
 *
 * [1899] Merge Triplets to Form Target Triplet
 */

// @lc code=start
class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        int aa = 0, bb = 0, cc = 0;
        for (int i = 0; i < triplets.size(); i++)
        {
            int a = triplets[i][0], b = triplets[i][1], c = triplets[i][2];
            if (a == target[0] and b <= target[1] and c <= target[2])
                aa = 1;
            if (b == target[1] and a <= target[0] and c <= target[2])
                bb = 1;
            if (c == target[2] and a <= target[0] and b <= target[1])
                cc = 1;
            if (aa == 1 and bb == 1 and cc == 1)
                break;
        }
        if (aa == 1 and bb == 1 and cc == 1)
            return true;
        else
            return false;
    }
};
// @lc code=end
