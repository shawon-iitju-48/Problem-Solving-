/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans = "";
        queue<TreeNode *> q;
        TreeNode *temp;

        if (root == NULL)
            return ans;

        q.push(root);
        ans += to_string(root->val) + ",";
        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp->left != NULL)
            {
                q.push(temp->left);
                ans += to_string(temp->left->val) + ",";
            }
            else
                ans += "n,";
            if (temp->right != NULL)
            {
                q.push(temp->right);
                ans += to_string(temp->right->val) + ",";
            }
            else
                ans += "n,";
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;

        int index = 0;
        queue<TreeNode *> q;
        TreeNode *node;

        size_t commaPos = data.find(',', index);
        string temp = data.substr(index, commaPos - index);
        int num = stoi(temp);

        TreeNode *root = new TreeNode(num);
        q.push(root);

        index = commaPos + 1;

        while (!q.empty() and index < data.size())
        {
            node = q.front();
            q.pop();

            if (data[index] != 'n')
            {
                commaPos = data.find(',', index);
                temp = data.substr(index, commaPos - index);
                num = stoi(temp);
                TreeNode *newnode = new TreeNode(num);
                q.push(newnode);
                node->left = newnode;
                index = commaPos + 1;
            }
            else
                index += 2;

            if (data[index] != 'n')
            {
                commaPos = data.find(',', index);
                temp = data.substr(index, commaPos - index);
                num = stoi(temp);
                TreeNode *newnode = new TreeNode(num);
                q.push(newnode);
                node->right = newnode;
                index = commaPos + 1;
            }
            else
                index += 2;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));