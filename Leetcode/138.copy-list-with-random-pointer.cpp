/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mp;
        Node *temp = head, *head2 = NULL, *new_node = NULL, *pre = NULL;

        while (temp != NULL)
        {
            pre = new_node;
            new_node = new Node(temp->val);
            if (temp == head)
                head2 = new_node;
            else
                pre->next = new_node;
            mp[temp] = new_node;
            temp = temp->next;
        }
        temp = head;
        pre = head2;
        while (temp != NULL)
        {
            pre->random = mp[temp->random];
            pre = pre->next;
            temp = temp->next;
        }
        return head2;
    }
};
// @lc code=end
