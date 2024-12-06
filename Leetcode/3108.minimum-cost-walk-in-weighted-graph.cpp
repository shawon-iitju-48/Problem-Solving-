#include <vector>
#include <unordered_map>
#include <climits>
#include <numeric>
#include <iostream>
using namespace std;

class DSU
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int size)
    {
        parent.resize(size);
        rank.resize(size, 0);
        iota(begin(parent), end(parent), 0);
    }

    int find_papa(int i)
    {
        if (parent[i] != i)
            parent[i] = find_papa(parent[i]);
        return parent[i];
    }

    void do_union(int i, int j)
    {
        int pi = find_papa(i);
        int pj = find_papa(j);

        if (pi != pj)
        {
            if (rank[pi] > rank[pj])
                parent[pj] = pi;
            else if (rank[pi] < rank[pj])
                parent[pi] = pj;
            else
            {
                parent[pj] = pi;
                rank[pi]++;
            }
        }
    }
};

class Solution
{
public:
    int dfs(int vertex, vector<bool> &visited, vector<vector<pair<int, int>>> &adj, int &mul)
    {
        visited[vertex] = true;

        for (auto &edge : adj[vertex])
        {
            int neighbor = edge.first;
            int weight = edge.second;

            // AND operation on edge weight
            mul &= weight;

            if (!visited[neighbor])
                dfs(neighbor, visited, adj, mul);
        }
        return mul;
    }

    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        DSU dsu(n);
        vector<vector<pair<int, int>>> adj(n);
        unordered_map<int, int> componentCost;
        vector<bool> visited(n, false);

        // Build adjacency list and union-find structure
        for (auto &edge : edges)
        {
            dsu.do_union(edge[0], edge[1]);
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        // Precompute the AND result for each connected component
        for (int i = 0; i < n; i++)
        {
            int component = dsu.find_papa(i);
            if (componentCost.find(component) == componentCost.end())
            {
                int mul = INT_MAX;
                dfs(i, visited, adj, mul);
                componentCost[component] = mul;
            }
        }

        // Answer the queries
        vector<int> ans;
        for (auto &q : query)
        {
            int rootX = dsu.find_papa(q[0]);
            int rootY = dsu.find_papa(q[1]);

            if (rootX != rootY)
                ans.push_back(-1); // Different components
            else
                ans.push_back(componentCost[rootX]); // Same component
        }

        return ans;
    }
};
