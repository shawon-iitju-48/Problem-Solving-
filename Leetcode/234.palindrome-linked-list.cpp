/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head, *fast = head, *pre = NULL, *temp;
        
        while (fast->next != NULL and fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = slow->next;

        while (slow != NULL)
        {
            temp = slow;
            slow = slow->next;
            temp->next = pre;
            pre = temp;
        }
        temp = head;
        while (pre != NULL)
        {
            if (temp->val != pre->val)
                return false;
            temp = temp->next;
            pre = pre->next;
        }
        return true;
    }
};
// @lc code=end
