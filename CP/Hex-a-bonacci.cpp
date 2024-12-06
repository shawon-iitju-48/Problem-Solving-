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
#define mkpr make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define xx first
#define yy second
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>

#define gcd(a, b) __gcd(a, b);
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; j--)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    ll n;
    ll aa[10005] = {0}, sum = 0;
    incfor(0, 6)
    {
        cin >> aa[i];
        aa[i]=aa[i]% 10000007;
        sum += aa[i];
    }

    cin >> n;
    incfor(6, n + 1)
    {
        if (i > 6)
        {
            // aa[i] = (aa[i - 1] + aa[i - 1] - aa[i - 7]);
            aa[i] = 0;
            ndecfor(i - 1, i - 7)
                aa[i] = aa[i] % 10000007 + aa[j] % 10000007;
            aa[i] = aa[i] % 10000007;
        }
        else
            aa[i] = sum;
    }
    
    cout << aa[n] << endl;
    // incfor(0,n+1)
    // cout<<aa[i]<<sp;
    // cout<<endl;
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
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/