/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    unordered_map<int, Node *> mp;
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        Node *rootNode = new Node(node->val);
        mp[node->val] = rootNode;
        for (int i = 0; i < node->neighbors.size(); i++)
        {
            if (mp.find(node->neighbors[i]->val) == mp.end())
                rootNode->neighbors.push_back(cloneGraph(node->neighbors[i]));
            else
                rootNode->neighbors.push_back(mp[node->neighbors[i]->val]);
        }

        return rootNode;
    }
};
// @lc code=end
