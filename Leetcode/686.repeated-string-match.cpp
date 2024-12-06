/*
 * @lc app=leetcode id=686 lang=cpp
 *
 * [686] Repeated String Match
 */

// @lc code=start
class Solution
{
public:
    long long hashrolling(long long dpower, char oldchar, char newchar, long long &d, long long &q, long long &oldhash)
    {
        long long newhash = (d * (oldhash - (oldchar - 'a') * dpower) + (newchar - 'a')) % q;
        if (newhash < 0)
            newhash += q;
        return newhash;
    }

    bool check(string &a, string &b, vector<long long> &power, long long &d, long long &q)
    {
        long long hb = 0, ha = 0, n = b.size();
        for (long long i = 0; i < n; i++)
        {
            hb = (hb + (b[i] - 'a') * power[i]) % q;
            ha = (ha + (a[i] - 'a') * power[i]) % q;
        }
        if (ha == hb)
            return true;
        for (long long i = n; i < a.size(); i++)
        {
            ha = hashrolling(power[0], a[i - n], a[i], d, q, ha);
            if (ha == hb)
                return true;
        }
        return false;
    }

    int repeatedStringMatch(string a, string b)
    {
        long long n = b.size(), d = 26, q = INT_MAX;
        int sum = 0;
        string newa = "";
        while (newa.size() < n)
        {
            newa = newa + a;
            sum++;
        }

        vector<long long> power(n, 1);
        for (long long i = n - 2; i >= 0; i--)
            power[i] = (power[i + 1] % q * d % q) % q;

        if (check(newa, b, power, d, q))
            return sum;
        newa = newa + a;
        sum++;
        if (check(newa, b, power, d, q))
            return sum;
        return -1;
    }
};
// @lc code=end
