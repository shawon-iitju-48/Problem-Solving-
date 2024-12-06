#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define lli long long int
#define ld long double
#define ull unsigned long long
#define ulli unsigned long long int
#define PI 3.1415926535897932384626433832795

#define sp ' '
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>

#define gcd(a, b) __gcd(a, b);
#define precision(a, b) cout << fixed << setprecision(a) << b << endl
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; j--)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
string curr = "http://www.lightoj.com/";
void solve()
{
    string s = "abcd", url;
    stack<string> back, forward;
    while (s != "QUIT")
    {
        cin >> s;
        if (s == "VISIT")
        {
            cin >> url;
            cout << url << endl;
            back.push(curr);
            curr = url;
            while (!forward.empty())
                forward.pop();
        }
        else if (s == "BACK")
        {
            if (back.empty())
                cout << "Ignored" << endl;
            else
            {
                cout << back.top() << endl;
                forward.push(curr);
                curr = back.top();
                back.pop();
            }
        }
        else if (s == "FORWARD")
        {
            if (forward.empty())
                cout << "Ignored" << endl;
            else
            {
                cout << forward.top() << endl;
                back.push(curr);
                curr = forward.top();
                forward.pop();
            }
        }
        else if (s == "QUIT")
        {
            while (!forward.empty())
                forward.pop();
            while (!back.empty())
                back.pop();
            curr = "http://www.lightoj.com/";
        }
    }
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
        cout << "Case " << t << ":\n";
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/