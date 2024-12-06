/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string s)
    {
        int start = 0, result = 0, sign = 1;

        // Trim leading whitespace
        while (start < s.size() && s[start] == ' ')
        {
            start++;
        }

        // Check for optional sign
        if (start < s.size() && (s[start] == '-' || s[start] == '+'))
        {
            sign = (s[start] == '-') ? -1 : 1;
            start++;
        }

        // Convert the number
        while (start < s.size() && isdigit(s[start]))
        {
            int digit = s[start] - '0';

            // Check for overflow
            if (result > (INT_MAX - digit) / 10)
            {
                return (sign == 1) ? INT_MAX : INT_MIN; // Overflow or underflow
            }

            result = result * 10 + digit;
            start++;
        }

        return result * sign; // Apply sign
    }
};
// @lc code=end
