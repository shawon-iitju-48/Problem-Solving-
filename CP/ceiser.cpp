
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    string s;
    cin.ignore();
    getline(cin, s);
    int a;
    if (s.find(" the ") != std::string::npos || (s.find(" the") != std::string::npos && s[s.size()-1]=='e'))
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;
            a = s[i];
            if (a - n >= 97)
                s[i] = a - n;
            else
                s[i] = 122 - n + a - 97 + 1;
        }
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;
            a = s[i];
            if (a + n <= 122)
                s[i] = a + n;
            else
                s[i] = 97 + n + a - 122 - 1;
        }
    }
    cout << s << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
    return 0;
}
