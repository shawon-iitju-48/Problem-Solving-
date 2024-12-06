/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {


        unordered_map<ListNode*,int>mp;
        ListNode *tempA=headA, *tempB=headB;
        while(tempA!=NULL)
        {
            mp[tempA]++;
            tempA=tempA->next;
        }
        while(tempB!=NULL)
        {
            if(mp[tempB]==1)
            return tempB;
            tempB=tempB->next;
        }
        return NULL;
        
    }
};
// @lc code=end

