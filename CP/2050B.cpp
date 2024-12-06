#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007

void start()
{
    int n, x, sum = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(x);
        sum += x;
    }
    int d = sum / n;
    for (int target = d; target >= 0; target--)
    {
        int flag = 0;
        for (int i = 0; i < n - 2; i++)
        {
            if (v[i] == target)
                continue;
            if (v[i] > target)
            {
                x = v[i] - target;
                v[i + 2] += x;
                v[i] = target;
            }
            else
            {
                x = target - v[i];
                v[i + 2] -= x;
                v[i] = target;
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (v[i] != v[i - 1])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            cout << "yes" << endl;
            return;
        }
    }
    cout << "no" << endl;
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
 *    created: 05-Dec-2024 20:58:50
 **/