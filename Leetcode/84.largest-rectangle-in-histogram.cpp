/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> ps, ns;
        stack<int> psk, nsk;
        psk.push(0), ps.push_back(-1);
        for (int i = 1; i < heights.size(); i++)
        {
            while (!psk.empty())
            {
                if (heights[psk.top()] < heights[i])
                {
                    ps.push_back(psk.top());
                    psk.push(i);
                    break;
                }
                else
                    psk.pop();
                if (psk.empty())
                {
                    psk.push(i);
                    ps.push_back(-1);
                    break;
                }
            }
        }
        ns.resize(heights.size());
        heights.push_back(-1);
        nsk.push(heights.size() - 1);
        ns[ns.size() - 1] = heights.size()-1, nsk.push(heights.size() - 2);
        for (int i = ns.size() - 2; i >= 0; i--)
        {
            while (!nsk.empty())
            {
                if (heights[nsk.top()] < heights[i])
                {
                    ns[i]=nsk.top();
                    nsk.push(i);
                    break;
                }
                else
                    nsk.pop();
            }
        }
        int mx = 0, area;
        for (int i = 0; i < ps.size(); i++)
        {
            area = (ns[i] - ps[i] - 1) * heights[i];
            mx = max(mx, area);
        }
        return mx;
    }
};
// @lc code=end
