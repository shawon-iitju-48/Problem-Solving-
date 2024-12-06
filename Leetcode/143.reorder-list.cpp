/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode *head)
    {
        ListNode *temp = head;
        vector<ListNode *> v;
        while (temp != 0)
        {
            v.push_back(temp);
            temp = temp->next;
        }
        int i = 0, j = v.size() - 1;
        while (j > 0)
        {
            v[i]->next = v[j];
            v[j]->next = v[i + 1];
            if (v[j] == v[j]->next)
            {
                v[j]->next = NULL;
                break;
            }
            if (v[i + 1] == v[j - 1])
            {
                v[i + 1]->next = NULL;
                break;
            }
            j--;
            i++;
        }
    }
};
// @lc code=end
