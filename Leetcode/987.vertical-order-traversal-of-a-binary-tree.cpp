/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        TreeNode *temp = root;
        vector<vector<int>> ans;
        map<int, vector<pair<int, int>>> mp;
        int level = 0, hd = 0, cnt = 0;
        queue<pair<pair<TreeNode *, int>, int>> q;
        q.push(make_pair(make_pair(root, 0), 0));
        while (!q.empty())
        {
            temp = q.front().first.first;
            level = q.front().first.second;
            hd = q.front().second;
            if (temp->left != NULL)
                q.push(make_pair(make_pair(temp->left, level + 1), hd - 1));
            if (temp->right != NULL)
                q.push(make_pair(make_pair(temp->right, level + 1), hd + 1));
            mp[hd].push_back(make_pair(temp->val, level));
            q.pop();
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            vector<pair<int, int>> v = it->second;
            vector<int> xd;
            int curr = 0;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i].second != v[curr].second)
                {
                    sort(v.begin() + curr, v.begin() + i);
                    curr = i;
                }
            }
            sort(v.begin() + curr, v.end());
            for (int i = 0; i < v.size(); i++)
                xd.push_back(v[i].first);
            ans.push_back(xd);
        }
        return ans;
    }
};
// @lc code=end
