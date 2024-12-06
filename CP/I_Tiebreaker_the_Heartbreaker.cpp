#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const long long LINF = 1e18;

void solve()
{
    string s;
    cin >> s;
    int teamX = 0, teamY = 0, cntX = 5, cntY = 5;
    for (int i = 0; i < s.size(); i++)
    {
        if (i % 2 == 0)
        {
            cntX--;
            if (s[i] == '1')
                teamX++;
        }
        else
        {
            cntY--;
            if (s[i] == '1')
                teamY++;
        }
    }
    if (s.size() % 2 == 0)
    {
        if (1 + teamX > teamY + cntY)
            cout << "1\n";
        else if (teamX + cntX - 1 < teamY)
            cout << "0\n";
        else
            cout << "-1\n";
    }
    else
    {
        if (1 + teamY > teamX + cntX)
            cout << "1\n";
        else if (teamY + cntY - 1 < teamX)
            cout << "0\n";
        else
            cout << "-1\n";
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
