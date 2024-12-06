/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int ans = 1, ln = s.size() - 1, window, front = 0, back = 0, maxfreq = 1;
        unordered_map<char, int> umap;
        while (back <= ln)
        {
            umap[s[back]]++;
            maxfreq = max(maxfreq, umap[s[back]]);
            window = back - front + 1;
            if (window - maxfreq <= k)
            {
                ans = max(ans, window);
                back++;
            }
            else
            {
                umap[s[front]]--;
                umap[s[back]]--;
                front++;
                maxfreq=1;
                for(auto &item:umap)
                maxfreq=max(item.second,maxfreq);
            }
        }
        return ans;
    }
};
// @lc code=end
