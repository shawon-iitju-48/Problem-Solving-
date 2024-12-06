#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
   unsigned long long int a[n], i;
    for (i = 0; i < n; i++)
        cin >> a[i];
    int x, y;
    sort(a, a + n);
    for (i = 1; i < n; i++)
        a[i] += a[i - 1];
    while (q--)
    {
        cin >> x >> y;
        if (x > y)
        {
            int start = n - (x + 1), end = (n - x) + (y - 1);
           if (start < 0)
                cout << a[end] << endl;
            else
                cout << a[end] - a[start] << endl;
        }
        else
        {
            int start = n - (y + 1), end = (n - y) + (x - 1);
            if (start < 0)
                cout << a[end] << endl;
            else
                cout << a[end] - a[start] << endl;
        }
    }
    return 0;
}