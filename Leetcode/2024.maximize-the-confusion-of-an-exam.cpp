/*
 * @lc app=leetcode id=2024 lang=cpp
 *
 * [2024] Maximize the Confusion of an Exam
 */

// @lc code=start
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int j = 0, mx = 0, t = 0, f = 0;

        for (int i = 0; i < answerKey.size(); i++)
        {
            if (answerKey[i] == 'T')
                t++;
            else
                f++;
            if (min(t, f) > k)
            {
                if (answerKey[j] == 'T')
                    t--;
                else
                    f--;
                j++;
            }
            mx = max(mx, i - j + 1);
        }
        return mx;
    }
};
// @lc code=end
