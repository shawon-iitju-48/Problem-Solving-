/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        int cnt = 0, group;
        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }
        group = cnt / k;
        cnt = 0;
        ListNode *prev = NULL, *curr = head, *next = NULL, *shuru = NULL, *aro = NULL;
        while (cnt != group)
        {
            int kcnt = 0;
            aro = shuru;
            shuru = curr;
            while (kcnt != k)
            {
                next = curr->next; // Store the next node
                curr->next = prev; // Reverse the current node's pointer
                prev = curr;       // Move pointers one position ahead
                curr = next;
                kcnt++;
            }
            shuru->next = curr;
            if (aro != NULL)
                aro->next = prev;

            if (cnt == 0)
                head = prev;
            cnt++;
        }
        return head;
    }
};
// @lc code=end
