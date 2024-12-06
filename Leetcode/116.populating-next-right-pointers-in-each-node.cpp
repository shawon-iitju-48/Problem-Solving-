/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    void nodeconnect(Node *left, Node *right)
    {
        if (left == NULL or right == NULL)
            return;
        left->next = right;
        nodeconnect(left->left, left->right);
        nodeconnect(right->left, right->right);
        nodeconnect(left->right, right->left);
    }
    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;
        nodeconnect(root->left, root->right);
        return root;
    }
};
// @lc code=end
