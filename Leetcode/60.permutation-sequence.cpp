/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution
{
public:
    int factorial(int n)
    {
        if (n == 1)
            return 1;
        return n * factorial(n - 1);
    }
    string getPermutation(int n, int k)
    {
        string s = "";
        int fact = factorial(n);
        vector<int> v;
        for (int i = 1; i <= n; i++)
            v.push_back(i);
        while (n > 1)
        {
            int m = fact / n;
            double result = static_cast<double>(k) / m;
            int ceilResult = static_cast<int>(ceil(result));
            if (ceilResult == 0)
                ceilResult = v.size();
            s = s + to_string(v[ceilResult - 1]);
            fact = m;
            k = k % m;
            n--;
            v.erase(v.begin() + ceilResult - 1);
        }
        s = s + to_string(v[0]);
        return s;
    }
};
// @lc code=end
