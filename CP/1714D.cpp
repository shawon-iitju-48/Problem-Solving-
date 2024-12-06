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
#define output(n) incfor(0, n) cout << a[i] << sp;
#define input(n) incfor(0, n) cin >> a[i];

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    string t, test;
    cin >> t;
    vector<pair<int, pair<int, string>>> v;
    vector<pii> vt;
    int n;
    cin >> n;
    incfor(0, n)
    {
        cin >> test;
        v.push_back(make_pair(test.length(), make_pair(i + 1, test)));
    }
    sort(v.begin(), v.end());
    int tar = v.size() - 1, a[v.size() + 5], color[t.length()] = {0};
    vector<pair<int, pair<int, int>>> nai;
    memset(a, -1, sizeof(a));
    size_t found;
    while (tar >= 0)
    {
        int ff = 0;
        incfor(0, t.length())
        {
            if (color[i] == 0)
            {
                ff = 1;
                break;
            }
        }
        if (ff == 0)
            break;
        string str1 = v[tar].second.second;
        found = t.find(str1, a[tar] + 1);
        // cout<<"hh"<<a[tar]<<endl;
        if (found != string::npos)
        {
            // cout<<found<<sp<<str1.length()<<endl;
            int flagg = 0;
            a[tar] = found;
            for (int i = found; i < found + str1.length(); i++)
            {
                if (color[i] == 0)
                {
                    color[i] = 1;
                    flagg = 1;
                }
            }
            if (flagg == 1)
            {
                vt.push_back(make_pair(v[tar].second.first, found + 1));
                nai.push_back(make_pair(str1.length() + found, make_pair(v[tar].second.first, found + 1)));
            }
        }
        else
            tar--;
    }
    int flag = 0;
    incfor(0, t.length())
    {
        if (color[i] == 0)
        {
            cout << -1 << endl;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        vector<pair<int, int>> res;
        sort(nai.begin(), nai.end());
        // res.push_back(make_pair(nai[0].second.first, nai[0].second.second));
        int finish = nai[0].first;
        int mygod = 0;
        incfor(1, nai.size())
        {
            // cout<<finish<<endl;
            // cout << nai[i].first << sp << nai[i].second.second << endl;
            if (nai[i].second.second >= finish or i == (nai.size() - 1))
            {
                // res.push_back(make_pair(nai[i].second.first, nai[i].second.second));
                finish = nai[i].first;
                mygod++;
            }
            else
            {
                res.push_back(make_pair(nai[i].second.first, nai[i].second.second));
                 nai.erase(nai.begin() + i);
            }
        }
        // cout << res.size() << endl;
        // cout << nai.size() << endl;
        int khanki=0;
        // incfor(0, nai.size())
        //         cout
        //     << nai[i].second.second << sp << nai[i].first << endl;
        incfor(1,nai.size())
        {
            if(nai[i].second.second-nai[i-1].first>1)
            {
                khanki++;
            }
        }
        cout<<nai.size()+khanki<<endl;
        incfor(0, nai.size())
                cout
            << nai[i].second.first << sp << nai[i].second.second << endl;
            incfor(0,khanki)
              cout
            << res[i].first << sp << res[i].second << endl;


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
        // cout<<"Case "<<t<<": ";
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/