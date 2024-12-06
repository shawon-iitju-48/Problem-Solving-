/*
 * @lc app=leetcode id=237 lang=cpp
 *
 * [237] Delete Node in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *temp = node, *pre = node;
        do
        {
            if (temp->next != NULL)
                temp->val = temp->next->val;
            else
                pre->next = NULL;
            pre = temp;
            temp = temp->next;
        } while (temp != NULL);
    }
};
// @lc code=end
