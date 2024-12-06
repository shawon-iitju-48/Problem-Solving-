/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> v;
        v.push_back({1});
        v.push_back({1, 1});
        if (numRows == 1)
            return {{1}};
        else if (numRows == 2)
            return {{1}, {1, 1}};
        else
        {
            numRows -= 2;
            while (numRows--)
            {
                vector<int> temp;
                temp.push_back(1);
                for (int i = 1; i < v[v.size() - 1].size(); i++)
                    temp.push_back(v[v.size() - 1][i] + v[v.size() - 1][i - 1]);
                temp.push_back(1);
                v.push_back(temp);
            }
            return v;
        }
    }
};
// @lc code=end
