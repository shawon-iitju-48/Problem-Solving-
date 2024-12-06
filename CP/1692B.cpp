#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a[100], unique[100], i, b[10010] = {0}, x = 0;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            b[a[i]]++;
            if (b[a[i]] == 1)
                unique[x++] = a[i];
        }
        int sum = 0;
        for (i = 0; i < x; i++)
        {
            sum += b[unique[i]];
        }
        int temp = sum - x;
        if (temp % 2 == 0)
            cout << x << endl;
        else
            cout << x - 1 << endl;
    }
    return 0;
}