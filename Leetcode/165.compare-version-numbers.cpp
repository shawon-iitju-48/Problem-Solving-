/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

// @lc code=start
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        int m = version1.size(), n = version2.size(), i = 0, j = 0, a = 0, b = 0;
        string s = "", p = "";
        while (i < m or j < n)
        {
            cout << i << " " << j << endl;
            if (i < m and version1[i] != '.')
            {
                s += version1[i];
                i++;
            }
            if (j < n and version2[j] != '.')
            {
                p += version2[j];
                j++;
            }
            if ((version1[i] == '.' or i == m) and (version2[j] == '.' or j == n))
            {
                a = 0, b = 0;
                if (s != "")
                    a = stoi(s);
                if (p != "")
                    b = stoi(p);
                if (a < b)
                    return -1;
                else if (a > b)
                    return 1;
                if (i < m)
                    i++;
                if (j < n)
                    j++;
                s = "";
                p = "";
            }
        }
        return 0;
    }
};
// @lc code=end
