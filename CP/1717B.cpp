#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define lli long long int
#define ull unsigned long long
#define PI 3.1415926535897932384626433832795
#define sp ' '
#define mem(a, value) memset(a, value, sizeof(a))
#define precision(a, b) cout << fixed << setprecision(a) << b << endl
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; j--)
#define input(a, n) incfor(0, n) cin >> a[i];
#define output(a, n) incfor(0, n) cout << a[i] << sp;

void solve()
{
    ll n, k, r, c, curr_row, curr_col;
    cin >> n >> k >> r >> c;
    queue<pair<ll, ll>> q;
    int ans[n + 5][n + 5];
    map<ll, ll> row, col;
    incfor(1, n + 1)
        row[i] = 1,
        col[i] = 1;
    mem(ans, 0);
    int cnt = 0;
    q.push(make_pair(r, c));
    while (row.size() != 0 and col.size() != 0)
    {
        if (q.size() != 0)
        {

            curr_row = q.front().first, curr_col = q.front().second;
            q.pop();
        }
        else
        {
            curr_row = row.begin()->first;
            curr_col = col.begin()->first;
        }
        ans[curr_row][curr_col] = 1;
        if (row.find(curr_row) != row.end())
        {
            cnt = 0;
            decfor(curr_col - 1, 0)
            {
                cnt++;
                if (cnt == k)
                {
                    cnt = 0;
                    ans[curr_row][i] = 1;
                    q.push(make_pair(curr_row, i));
                }
            }
            cnt = 0;
            incfor(curr_col + 1, n + 1)
            {
                cnt++;
                if (cnt == k)
                {
                    cnt = 0;
                    ans[curr_row][i] = 1;
                    q.push(make_pair(curr_row, i));
                }
            }
            row.erase(curr_row);
        }
        if (col.find(curr_col) != col.end())
        {
            cnt = 0;
            decfor(curr_row - 1, 0)
            {
                cnt++;
                if (cnt == k)
                {
                    cnt = 0;
                    ans[i][curr_col] = 1;
                    q.push(make_pair(i, curr_col));
                }
            }
            cnt = 0;
            incfor(curr_row + 1, n + 1)
            {
                cnt++;
                if (cnt == k)
                {
                    cnt = 0;
                    ans[i][curr_col] = 1;
                    q.push(make_pair(i, curr_col));
                }
            }
            col.erase(curr_col);
        }
    }
    incfor(1, n + 1)
    {
        nincfor(1, n + 1)
        {
            if(ans[i][j]==0)
            cout<<".";
            else cout<<"X";
        }
        cout << endl;
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
 *    author:  shawon
 **/