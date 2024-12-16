#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007

void start()
{
    long long k, l1, r1, l2, r2, n = 1, sum = 0, upper = 1, lower = 1;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    while (1)
    {
        lower = (l2 + n - 1) / n;
        lower = max(l1, lower);

        upper = r2 / n;
        if (upper < l1)
            break;
        upper = min(r1, upper);
        if (upper >= lower)
            sum += upper - lower + 1;

        n = n * k;
    }
    cout << sum << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    for (int casenum = 1; casenum <= t; casenum++)
    {
        // cout << "Case #" << casenum << ": ";
        start();
    }

    return 0;
}

/**
 *    author:  Md. Bokhtiar Nadeem Shawon
 *    created: 15-Dec-2024 21:23:48
 **/