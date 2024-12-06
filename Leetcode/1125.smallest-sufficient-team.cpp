/*
 * @lc app=leetcode id=1125 lang=cpp
 *
 * [1125] Smallest Sufficient Team
 */

// @lc code=start
class Solution
{
public:
    pair<int, string> solve(int idx, int state, int &n, vector<vector<int>> &people, vector<vector<pair<int, string>>> &dp)
    {
        if (idx >= people.size())
        {
            if (state == (1 << n) - 1)
                return {0, ""};

            return {INT_MAX, ""};
        }

        if (dp[idx][state].first != -1)
            return dp[idx][state];

        int newstate = 0;

        pair<int, string> p = solve(idx + 1, state, n, people, dp), q, ans = p;

        for (auto &i : people[idx])
            newstate |= (1 << i);

        q = solve(idx + 1, state | newstate, n, people, dp);

        if (q.first != INT_MAX and 1 + q.first < p.first)
            ans = make_pair(1 + q.first, to_string(idx) + "," + q.second);

        return dp[idx][state] = ans;
    }
    vector<int> stringToVector(const string &s)
    {
        vector<int> result;
        int num = 0;
        for (char c : s)
        {
            if (c == ',')
            {
                result.push_back(num);
                num = 0;
            }
            else
                num = num * 10 + (c - '0');
        }
        return result;
    }
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people)
    {
        int n = req_skills.size();
        unordered_map<string, int> rqskill;

        for (int i = 0; i < n; i++)
            rqskill[req_skills[i]] = i;

        vector<vector<int>> p(people.size());
        for (int i = 0; i < people.size(); i++)
        {
            for (auto &in : people[i])
                p[i].push_back(rqskill[in]);
        }
        vector<vector<pair<int, string>>> dp(people.size(), vector<pair<int, string>>(1 << n, {-1, ""}));
        return stringToVector(solve(0, 0, n, p, dp).second);
    }
};
// @lc code=end
