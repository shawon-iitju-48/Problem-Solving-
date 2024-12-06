/*
 * @lc app=leetcode id=2251 lang=cpp
 *
 * [2251] Number of Flowers in Full Bloom
 */

// @lc code=start
class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people)
    {
        vector<int>startBlooming, endBlooming, ans;
        for(auto &flower: flowers)
        {
            startBlooming.push_back(flower[0]);
            endBlooming.push_back(flower[1]);
        }
        sort(begin(startBlooming), end(startBlooming));
        sort(begin(endBlooming), end(endBlooming));

        for(auto &p: people)
        {
            int blommed=upper_bound(begin(startBlooming), end(startBlooming), p)-startBlooming.begin();
            int dead=lower_bound(begin(endBlooming), end(endBlooming),p)-endBlooming.begin();
            ans.push_back(blommed-dead);
        }
        return ans;
    }
};
// @lc code=end
