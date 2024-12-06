/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
class NumArray
{
public:
    vector<int> segtree;
    int n;

    int buildTree(int i, int left, int right, vector<int> &nums)
    {
        if (left == right)
            return segtree[i] = nums[left];

        int mid = left + (right - left) / 2;
        return segtree[i] = buildTree(2 * i + 1, left, mid, nums) + buildTree(2 * i + 2, mid + 1, right, nums);
    }

    void doUpdate(int index, int val, int i, int left, int right)
    {
        if (left == right)
            segtree[i] = val;
        else
        {
            int mid = left + (right - left) / 2;
            if (index <= mid)
                doUpdate(index, val, 2 * i + 1, left, mid);
            else
                doUpdate(index, val, 2 * i + 2, mid + 1, right);

            segtree[i] = segtree[2 * i + 1] + segtree[2 * i + 2];
        }
    }
    int query(int l, int r, int i, int left, int right)
    {
        if (right < l or left > r)
            return 0;

        if (l <= left and right <= r)
            return segtree[i];

        int mid = left + (right - left) / 2;
        return query(l, r, 2 * i + 1, left, mid) + query(l, r, 2 * i + 2, mid + 1, right);
    }
    NumArray(vector<int> &nums)
    {
        n = nums.size();
        segtree.resize(4 * n);
        buildTree(0, 0, n - 1, nums);
    }

    void update(int index, int val)
    {
        doUpdate(index, val, 0, 0, n - 1);
    }

    int sumRange(int left, int right)
    {
        return query(left, right, 0, 0, n - 1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end
