/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;
        unordered_map<int, vector<int>> ulta;

        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;

        vector<int>key;
        for (auto it = freq.begin(); it != freq.end(); it++)
                ulta[it->second].push_back(it->first);

        for (auto it = ulta.begin(); it != ulta.end(); it++)
                key.push_back(it->first);
        sort(key.begin(),key.end());
        vector<int> ans, temp;
        int cnt = k;

        for (int i = key.size()-1; i >=0; i--)
        {
                temp = ulta[key[i]];
                for (int j = 0; j < temp.size(); j++)
                {
                    if (cnt > 0)
                    {
                        ans.push_back(temp[j]);
                        cnt--;
                    }
                    else
                     break;
                }
            if(cnt==0)
            break;
        }
        return ans;
    }
};
// @lc code=end
