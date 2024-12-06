#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007

bool solve(int i, int sum, string &s, unordered_map<int, unordered_map<int, bool>> &mp)
{
    if (i >= s.size())
        return sum % 9 == 0;

    if (mp[i].count(sum))
        return mp[i][sum];

    int x = s[i] - '0';

    if (solve(i + 1, sum + x, s, mp))
        return mp[i][sum] = true;

    if (x * x < 10 and solve(i + 1, sum + (x * x), s, mp))
        return mp[i][sum] = true;

    return mp[i][sum] = false;
}
void start()
{
    string s;
    cin >> s;
    unordered_map<int, unordered_map<int, bool>> mp;
    if (solve(0, 0, s, mp))
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for (int casenum = 1; casenum <= t; casenum++)
    {
        // cout << "Case #" << casenum << ": ";
        start();
    }

    return 0;
}

/**
 *    author:  Md. Bokhtiar Nadeem Shawon
 *    created: 05-Dec-2024 21:29:22
 **/