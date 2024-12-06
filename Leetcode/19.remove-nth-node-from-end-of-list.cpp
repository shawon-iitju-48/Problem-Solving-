/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt=0,target;
        ListNode *temp=head;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;
        }
        target=cnt-n;
        if(target==0)
        head=head->next;
        else
        {
            cnt=0;
            temp=head;
            while(temp!=NULL)
            {
                cnt++;
                if(cnt==target)
                {
                    temp->next=temp->next->next;
                    break;
                }
                temp=temp->next;
            }
        }
        return head;
    }
};
// @lc code=end

