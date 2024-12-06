/*
 * @lc app=leetcode id=1208 lang=cpp
 *
 * [1208] Get Equal Substrings Within Budget
 */

// @lc code=start
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int sum=0, i=0,mx=0;
        for(int j=0;j<s.size();j++)
        {
            sum+=abs((s[j]-'a')-(t[j]-'a'));
            while(sum>maxCost)
            {
                sum-=abs((s[i]-'a')-(t[i]-'a'));
                i++;
            }
            mx=max(mx, j-i+1);
        }
        return mx;
    }
};
// @lc code=end

