class Solution
{
public:
    double dfs(string src, string des, unordered_set<string> &vis, unordered_map<string, vector<pair<string, double>>> &adj)
    {
        if (adj.find(src) == adj.end() || adj.find(des) == adj.end())
            return -1.0;

        vis.insert(src);
        for (auto &vec : adj[src])
        {
            if (vec.first == des)
                return vec.second;

            if (vis.find(vec.first) == vis.end())
            {
                double x = dfs(vec.first, des, vis, adj);
                if (x != -1.0)
                    return x * vec.second;
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pair<string, double>>> adj;
        double x;
        for (int i = 0; i < equations.size(); i++)
        {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            x = 1 / values[i];
            adj[equations[i][1]].push_back({equations[i][0], x});
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            unordered_set<string> vis;
            double result = dfs(queries[i][0], queries[i][1], vis, adj);
            ans.push_back(result);
        }

        return ans;
    }
};
