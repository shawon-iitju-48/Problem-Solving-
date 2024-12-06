#include <bits/stdc++.h>
using namespace std;

bool check(long long target, vector<long long> &v, long long &x, long long &sum)
{
    if (target * x < sum)
        return false;
    return true;
}
void solve()
{
    long long n, x, temp, f = INT_MIN, l = 0, mid, sum, result;
    cin >> n >> x;
    vector<long long> v;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        f = max(f, temp);
        l = l + temp;
        v.push_back(temp);
    }
    sum = l;
    while (f <= l)
    {
        mid = f + (l - f) / 2;
        if (check(mid, v, x, sum))
        {
            result = mid;
            l = mid - 1;
        }
        else
            f = mid + 1;
    }
    cout << result << endl;
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
