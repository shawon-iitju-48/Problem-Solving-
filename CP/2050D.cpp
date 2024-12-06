#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007

void start()
{
    string s;
    cin >> s;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        int mx = s[i] - '0', index = i;
        for (int j = i + 1; j < i + 10 and j < s.size(); j++)
        {
            int x = s[j] - '0';
            x = x - j + i;
            if (x > mx)
            {
                mx = x;
                index = j;
            }
        }
        ans += to_string(mx);

        for (int j = index; j > i; j--)
            s[j] = s[j - 1];
    }
    cout << ans << endl;
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
 *    created: 05-Dec-2024 22:20:47
 **/