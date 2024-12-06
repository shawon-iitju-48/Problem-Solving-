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
    ll dig, n, temp, start, end, Sheldon, Leonard, Penny, Rajesh, Howard;
    cin >> dig;
    temp = (dig - 1) / 5;
    n = log2(temp + 1);
    end = pow(2, n);
    start = (end - 1) * 5 + 1;
    Leonard = start + end;
    Penny = start + 2 * end;
    Rajesh = start + 3 * end;
    Howard = start + 4 * end;

    if (dig >= start and dig <= (start + end - 1))
        cout << "Sheldon\n";
    else if (dig >= Leonard and dig <= (Leonard + end - 1))
        cout << "Leonard\n";
    else if (dig >= Penny and dig <= (Penny + end - 1))
        cout << "Penny\n";
    else if (dig >= Rajesh and dig <= (Rajesh + end - 1))
        cout << "Rajesh\n";
    else if (dig >= Howard and dig <= (Howard + end - 1))
        cout << "Howard\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
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