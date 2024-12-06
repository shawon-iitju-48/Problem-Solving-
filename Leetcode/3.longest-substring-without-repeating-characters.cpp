/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> umap;
        int init = 0, mx = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (umap.find(s[i]) != umap.end())
            {
                for (int j = init; j < umap[s[i]]; j++)
                    umap.erase(s[j]);
                init = umap[s[i]] + 1;
            }
            umap[s[i]] = i;
            mx = max(mx, i - init + 1);
        }
        return mx;
    }
};
// @lc code=end
