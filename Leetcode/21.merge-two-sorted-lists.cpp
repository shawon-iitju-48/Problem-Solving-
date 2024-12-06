/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *new_list = NULL, *age = NULL, *head;
        while (list1 != NULL and list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                new_list = new ListNode(list1->val, NULL);
                if (age == NULL)
                    head = new_list;
                else
                    age->next = new_list;
                age = new_list;
                list1 = list1->next;
            }
            else
            {
                new_list = new ListNode(list2->val, NULL);
                if (age == NULL)
                    head = new_list;
                else
                    age->next = new_list;
                age = new_list;
                list2 = list2->next;
            }
        }
        while (list1 != NULL)
        {
            new_list = new ListNode(list1->val, NULL);
            if (age == NULL)
                head = new_list;
            else
                age->next = new_list;
            age = new_list;
            list1 = list1->next;
        }

        while (list2 != NULL)
        {
            new_list = new ListNode(list2->val, NULL);
            if (age == NULL)
                head = new_list;
            else
                age->next = new_list;
            age = new_list;
            list2 = list2->next;
        }
        return head;
    }
};
// @lc code=end
