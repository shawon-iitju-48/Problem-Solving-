/*
 * @lc app=leetcode id=2381 lang=cpp
 *
 * [2381] Shifting Letters II
 */

// @lc code=start
class Solution
{
public:
    int buildTree(int i, int left, int right, vector<int> &nums, vector<int> &segtree)
    {
        if (left == right)
            return segtree[i] = nums[left];

        int mid = left + (right - left) / 2;

        return segtree[i] = (buildTree(2 * i + 1, left, mid, nums, segtree) + buildTree(2 * i + 2, mid + 1, right, nums, segtree)) % 26;
    }
    void updateRange(int a, int b, int val, int i, int left, int right, vector<int> &segtree, vector<int> &lazytree)
    {
        if (lazytree[i] != 0)
        {
            segtree[i] = (segtree[i] + (right - left + 1) * lazytree[i]) % 26;
            if (left != right)
            {
                lazytree[2 * i + 1] += lazytree[i];
                lazytree[2 * i + 2] += lazytree[i];
            }
            lazytree[i] = 0;
        }

        if (b < left or right < a)
            return;

        if (a <= left and right <= b)
        {
            segtree[i] = (segtree[i] + (right - left + 1) * val) % 26;
            if (left != right)
            {
                lazytree[2 * i + 1] += val;
                lazytree[2 * i + 2] += val;
            }
            return;
        }

        int mid = left + (right - left) / 2;
        updateRange(a, b, val, 2 * i + 1, left, mid, segtree, lazytree);
        updateRange(a, b, val, 2 * i + 2, mid + 1, right, segtree, lazytree);
        segtree[i] = (segtree[2 * i + 1] + segtree[2 * i + 2]) % 26;
    }
    void generateResult(int i, int left, int right, vector<int> &segtree, vector<int> &lazytree, string &ans)
    {
        if (lazytree[i] != 0)
        {
            segtree[i] = (segtree[i] + (right - left + 1) * lazytree[i]) % 26;
            if (left != right)
            {
                lazytree[2 * i + 1] += lazytree[i];
                lazytree[2 * i + 2] += lazytree[i];
            }
            lazytree[i] = 0;
        }

        if (left == right)
        {
            if (segtree[i] < 0)
                segtree[i] += 26;

            char ch = segtree[i] + 'a';
            ans += ch;
            return;
        }
        int mid = left + (right - left) / 2;
        generateResult(2 * i + 1, left, mid, segtree, lazytree, ans);
        generateResult(2 * i + 2, mid + 1, right, segtree, lazytree, ans);
    }
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.size();
        vector<int> segtree(4 * n), lazytree(4 * n, 0), nums;

        for (int i = 0; i < s.size(); i++)
            nums.push_back(s[i] - 'a');

        buildTree(0, 0, n - 1, nums, segtree);

        for (auto &q : shifts)
        {
            if (q[2] == 0)
                updateRange(q[0], q[1], -1, 0, 0, n - 1, segtree, lazytree);
            else
                updateRange(q[0], q[1], 1, 0, 0, n - 1, segtree, lazytree);
        }

        string ans = "";
        generateResult(0, 0, n - 1, segtree, lazytree, ans);
        return ans;
    }
};
// @lc code=end
