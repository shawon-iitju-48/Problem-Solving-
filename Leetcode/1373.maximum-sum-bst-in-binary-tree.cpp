class Solution
{
public:
    // {isBST, sum, minimum value, maximum value}
    int mx = 0;
    vector<int> solve(TreeNode *root)
    {
        if (root == NULL)
            return {1, 0, INT_MAX, INT_MIN};

        vector<int> leftsub = solve(root->left);
        vector<int> rightsub = solve(root->right);

        if (root->val > leftsub[3] and root->val < rightsub[2] and leftsub[0] == rightsub[0] and leftsub[0] == 1)
        {
            int sum = root->val + leftsub[1] + rightsub[1];
            mx = max(mx, sum);
            return {1, sum, min(leftsub[2], root->val), max(root->val, rightsub[3])};
        }
        return {0, 0, INT_MAX, INT_MIN};
    }
    int maxSumBST(TreeNode *root)
    {
        solve(root);
        return mx;
    }
};
