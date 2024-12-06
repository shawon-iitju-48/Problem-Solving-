/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        int cnt = 0, koto;
        ListNode *temp = head, *last;
        while (temp != 0)
        {
            cnt++;
            if (temp->next == NULL)
                last = temp;
            temp = temp->next;
        }
        if (cnt == 0 or k == 0)
            return NULL;
        koto = k % cnt;
        if (koto == 0)
            return head;
        koto = cnt - koto;
        cnt = 0;
        temp = head;
        while (true)
        {
            cnt++;
            if (cnt == koto)
                break;
            temp = temp->next;
        }
        last->next = head;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};
// @lc code=end
