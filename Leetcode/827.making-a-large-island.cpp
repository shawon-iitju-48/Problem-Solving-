/*
 * @lc app=leetcode id=827 lang=cpp
 *
 * [827] Making A Large Island
 */

// @lc code=start
class DSU
{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> parentSize;

public:
    DSU(int size)
    {
        parent.resize(size);
        rank.resize(size, 0);
        parentSize.resize(size, 1);
        iota(begin(parent), end(parent), 0);
    }
    int find_papa(int i)
    {
        if (parent[i] != i)
            parent[i] = find_papa(parent[i]);
        return parent[i];
    }

    int papa_size(int pi)
    {
        return parentSize[pi];
    }

    void do_union(int i, int j)
    {
        int pi = find_papa(i);
        int pj = find_papa(j);

        if (pi != pj)
        {
            if (rank[pi] > rank[pj])
            {
                parent[pj] = pi;
                parentSize[pi] += parentSize[pj];
            }
            else if (rank[pi] < rank[pj])
            {
                parent[pi] = pj;
                parentSize[pj] += parentSize[pi];
            }
            else
            {
                parent[pj] = pi;
                rank[pi]++;
                parentSize[pi] += parentSize[pj];
            }
        }
    }
};

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        DSU dsu(n * n);
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int x = (n * i) + j;
                    for (auto [di, dj] : directions)
                    {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n and grid[ni][nj] == 1)
                        {
                            int y = (n * ni) + nj;
                            dsu.do_union(x, y);
                        }
                    }
                }
            }
        }
        int mx = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int x = (n * i) + j;
                    mx = max(mx, dsu.papa_size(dsu.find_papa(x)));
                }
                else
                {
                    int sum = 1;
                    unordered_set<int> st;
                    for (auto [di, dj] : directions)
                    {
                        int ni = i + di, nj = j + dj;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n and grid[ni][nj] == 1)
                        {
                            int y = (n * ni) + nj;
                            st.insert(dsu.find_papa(y));
                        }
                    }
                    for (auto it = st.begin(); it != st.end(); it++)
                        sum += dsu.papa_size(*it);
                    mx = max(mx, sum);
                }
            }
        }
        return mx;
    }
};
// @lc code=end
