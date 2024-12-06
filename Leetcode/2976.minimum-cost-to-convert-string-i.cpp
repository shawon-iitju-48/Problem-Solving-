/*
 * @lc app=leetcode id=2976 lang=cpp
 *
 * [2976] Minimum Cost to Convert String I
 */

// @lc code=start
class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        vector<vector<long long>> dist(26, vector<long long>(26, LLONG_MAX));
        for (int i = 0; i < 26; i++)
            dist[i][i] = 0;

        for (int i = 0; i < original.size(); i++)
        {
            int u = original[i] - 'a', v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        for (int k = 0; k < 26; k++)
        {
            for (int i = 0; i < 26; i++)
            {
                if (dist[i][k] == LLONG_MAX)
                    continue;
                for (int j = 0; j < 26; j++)
                {
                    if (dist[k][j] == LLONG_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        long long sum = 0;
        for (int i = 0; i < source.size(); i++)
        {
            if (dist[source[i] - 'a'][target[i] - 'a'] == LLONG_MAX)
                return -1;
            sum += dist[source[i] - 'a'][target[i] - 'a'];
        }
        return sum;
    }
};
// @lc code=end
