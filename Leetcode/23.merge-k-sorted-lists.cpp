/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *left, *right, *head, *curr;
        stack<ListNode *> stk;

        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL)
                stk.push(lists[i]);
            if (stk.size() == 2)
            {
                left = stk.top();
                stk.pop();
                right = stk.top();
                stk.pop();
                int flag = 0;

                while (left != NULL && right != NULL)
                {
                    if (left->val <= right->val)
                    {
                        if (flag == 0)
                        {
                            head = curr = left;
                            flag = 1;
                        }
                        else
                        {
                            curr->next = left;
                            curr = left;
                        }
                        left = left->next;
                    }
                    else
                    {
                        if (flag == 0)
                        {
                            head = curr = right;
                            flag = 1;
                        }
                        else
                        {
                            curr->next = right;
                            curr = right;
                        }
                        right = right->next;
                    }
                }
                while (left != NULL)
                {
                    curr->next = left;
                    curr = left;
                    left = left->next;
                }
                while (right != NULL)
                {
                    curr->next = right;
                    curr = right;
                    right = right->next;
                }
                stk.push(head);
            }
        }
        if (stk.size() == 0)
            return NULL;
        else
            return stk.top();
    }
};
// @lc code=end
