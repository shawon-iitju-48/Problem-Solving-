/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

// @lc code=start
class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> ans;
    int si;
    KthLargest(int k, vector<int> &nums)
    {
        si = k;
        for (int i = 0; i < nums.size(); i++)
        {
            if (ans.size() < k)
                ans.push(nums[i]);
            else if (nums[i] > ans.top())
            {
                ans.pop();
                ans.push(nums[i]);
            }
        }
    }

    int add(int val)
    {
        if (ans.size() < si)
            ans.push(val);
        else if (val > ans.top())
        {
            ans.pop();
            ans.push(val);
        }
        return ans.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end
