/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[150]={0},b[150]={0};
        for(int i=0;i<s.size();i++)
        a[s[i]]++;
        for(int i=0;i<t.size();i++)
        b[t[i]]++;
        if(s.size()!=t.size())
        return false;
        else
        {
            int flag=0;
            for(int i=0;i<t.size();i++)
            {
                if(a[t[i]]==0 || b[t[i]]!=a[t[i]])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            return true;
            else return false;
        }
    }
};
// @lc code=end

