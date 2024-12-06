/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

// @lc code=start
class Solution
{
public:
    int maximumSwap(int num)
    {
        vector<int> digits;
        int n = num;
        while (n != 0)
        {
            digits.push_back(n % 10);
            n = n / 10;
        }
        vector<int> maxDig(digits.size(), 0);
        for (int i = 1; i < digits.size(); i++)
        {
            if (digits[i] > digits[maxDig[i - 1]])
                maxDig[i] = i;
            else
                maxDig[i] = maxDig[i - 1];
        }
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            if (digits[i] < digits[maxDig[i]])
            {
                swap(digits[i], digits[maxDig[i]]);
                break;
            }
        }

        int factor = 1, numm = 0;
        for (int i = 0; i < digits.size(); i++)
        {
            numm += (digits[i] * factor);
            factor *= 10;
        }

        return numm;
    }
};
// @lc code=end
