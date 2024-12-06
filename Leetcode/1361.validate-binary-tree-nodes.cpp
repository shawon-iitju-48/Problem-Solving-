/*
 * @lc app=leetcode id=1361 lang=cpp
 *
 * [1361] Validate Binary Tree Nodes
 */

// @lc code=start
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

    void do_union(int pi, int pj)
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
};

class Solution
{
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
    {
        DSU dsu(n);
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            int root = dsu.find_papa(i);
            if (leftChild[i] != -1)
            {
                indegree[leftChild[i]]++;
                if (indegree[leftChild[i]] > 1)
                    return false;
                int left = dsu.find_papa(leftChild[i]);
                if (root == left)
                    return false;
                dsu.do_union(root, left);
            }
            if (rightChild[i] != -1)
            {
                indegree[rightChild[i]]++;
                if (indegree[rightChild[i]] > 1)
                    return false;
                int right = dsu.find_papa(rightChild[i]);
                if (root == right)
                    return false;
                dsu.do_union(root, right);
            }
        }
        int papa = dsu.find_papa(0);
        for (int i = 1; i < n; i++)
            if (dsu.find_papa(i) != papa)
                return false;
        return true;
    }
};
// @lc code=end
