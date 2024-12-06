/*
 * @lc app=leetcode id=752 lang=cpp
 *
 * [752] Open the Lock
 */

// @lc code=start
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> vis, dead;
        for (auto &d : deadends)
            dead.insert(d);

        queue<pair<string, int>> q;
        if (dead.find("0000") == dead.end())
        {
            q.push({"0000", 0});
            vis.insert("0000");
        }

        while (!q.empty())
        {
            string node = q.front().first;
            int step = q.front().second;

            if (node == target)
                return step;

            q.pop();

            for (int i = 0; i < 4; i++)
            {
                char original = node[i];
                int x = node[i] - '0', y;

                y = (x - 1 + 10) % 10;
                char ch = y + '0';
                node[i] = ch;
                if (vis.find(node) == vis.end() and dead.find(node) == dead.end())
                {
                    q.push({node, step + 1});
                    vis.insert(node);
                }
                node[i] = original;

                y = (x + 1 + 10) % 10;
                ch = y + '0';
                node[i] = ch;
                if (vis.find(node) == vis.end() and dead.find(node) == dead.end())
                {
                    q.push({node, step + 1});
                    vis.insert(node);
                }
                node[i] = original;
            }
        }
        return -1;
    }
};
// @lc code=end
