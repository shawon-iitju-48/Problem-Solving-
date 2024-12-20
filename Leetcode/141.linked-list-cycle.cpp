/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head)
    {
        if(head->next==NULL)
        return false;
        ListNode *slow = head, *fast = head->next->next;
        while (slow != fast and slow!=NULL and fast!=NULL and fast->next!=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (slow == fast)
            return true;
        else
            return false;
    }
};
// @lc code=end
