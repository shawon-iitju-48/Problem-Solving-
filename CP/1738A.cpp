#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define lli long long int
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#define sp ' '
#define precision(a, b) cout << fixed << setprecision(a) << b << endl
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; j--)
#define input(a, n) incfor(0, n) cin >> a[i];
#define output(a, n) incfor(0, n) cout << a[i] << sp;

void solve()
{
    ll n;
    cin >> n;
    ll a[n], b[n];
    input(a, n);
    input(b, n);
    vector<pair<ll, ll>> v1, v2;
    incfor(0, n)
    {
        if (a[i] == 0)
            v1.push_back(make_pair(b[i], a[i]));
        else
            v2.push_back(make_pair(b[i], a[i]));
    }
    sort(v1.rbegin(), v1.rend());
    sort(v2.rbegin(), v2.rend());
    ll sum = 0;
    if (v1.size() > v2.size())
    {
        if (v1.size() != 0)
            sum = v1[v1.size() - 1].first;
        for (int i = 0; i < v2.size(); i++)
        {
            if (i != v1.size() - 1)
                sum += (2 * v1[i].first);
            sum += (2 * v2[i].first);
        }
        for (int i = v2.size(); i < v1.size() - 1; i++)
            sum += v1[i].first;
    }
    else
    {
        int flag = 0;
        if (v1.size() == v2.size() and v1[v1.size() - 1].first > v2[v2.size() - 1].first)
            sum = v2[v2.size() - 1].first, flag = 1;
        else if (v1.size() == v2.size() and v1[v1.size() - 1].first < v2[v2.size() - 1].first)
            sum = v1[v1.size() - 1].first, flag = 2;
        else if (v2.size() != 0)
            sum = v2[v2.size() - 1].first;
        for (int i = 0; i < v1.size(); i++)
        {
            if (flag == 0 or flag == 1)
            {
                if (i != v2.size() - 1)
                    sum += (2 * v2[i].first);
                sum += (2 * v1[i].first);
            }
            else
            {
                sum += (2 * v2[i].first);
                if (i != v1.size() - 1)
                    sum += (2 * v1[i].first);
            }
        }
        for (int i = v1.size(); i < v2.size() - 1; i++)
            sum += v2[i].first;
    }
    cout << sum << endl;
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
        // cout<<"Case "<<t<<": ";
        solve();
    }
    return 0;
}
/**
 *    author:  shawon
 **/