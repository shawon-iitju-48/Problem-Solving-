/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>group;
        for(int i=0;i<strs.size();i++)
        {
            string ss=strs[i];
            sort(ss.begin(), ss.end());
            group[ss].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto it = group.begin(); it != group.end(); ++it)
            ans.push_back(it->second);
        return ans;

    }
};
// @lc code=end

