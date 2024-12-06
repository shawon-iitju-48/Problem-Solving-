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
    ll x1, p1, x2, p2, temp1 = 0, temp2 = 0, cnt1 = 0, cnt2 = 0, sum1, sum2;
    cin >> x1 >> p1 >> x2 >> p2;
    temp1 = x1, temp2 = x2;
    stack<int> s1, s2;
    while (temp1 != 0)
    {
        s1.push(temp1 % 10);
        temp1 = temp1 / 10;
        cnt1++;
    }
    while (temp2 != 0)
    {
        s2.push(temp2 % 10);
        temp2 = temp2 / 10;
        cnt2++;
    }
    sum1 = cnt1 + p1;
    sum2 = cnt2 + p2;
    if (sum1 > sum2)
        cout << ">\n";
    else if (sum1 < sum2)
        cout << "<\n";
    else
    {
        int flag = 0, a[100], b[100], in1 = 0, in2 = 0;
        incfor(0, cnt1)
        {
            a[in1++] = s1.top();
            s1.pop();
        }
        incfor(0, cnt2)
        {
            b[in2++] = s2.top();
            s2.pop();
        }
        incfor(0, min(cnt1, cnt2))
        {
            if (a[i] > b[i])
            {
                flag = 1;
                cout << ">\n";
                break;
            }
            else if (a[i] < b[i])
            {
                flag = 1;
                cout << "<\n";
                break;
            }
        }
        if (flag == 0)
        {
            incfor(min(cnt1, cnt2), max(cnt1, cnt2))
            {
                if (cnt1 > cnt2)
                {
                    if (a[i] > 0)
                    {
                        flag = 1;
                        cout << ">\n";
                    }
                }
                else
                {
                    if (b[i] > 0)
                    {
                        flag = 1;
                        cout << "<\n";
                    }
                }
                if (flag == 1)
                    break;
            }
            if (flag == 0)
                cout << "=\n";
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
        // cout<<"Case "<<t<<": ";
        solve();
    }
    return 0;
}
/**
 *    author:  shawon
 **/