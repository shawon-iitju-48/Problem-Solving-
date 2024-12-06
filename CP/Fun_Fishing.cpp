#include <bits/stdc++.h>
using namespace std;

#define INF LLONG_MAX
#define MOD 1000000007LL

int m, n;

long long topLeft(int r, int c, int &netSize, vector<vector<int>> &grid)
{
    long long sum = 0;
    for (int i = r; i < r + netSize; i++, c--)
    {
        if (c < 0 or i >= m)
            return -1;
        sum += grid[i][c];
    }

    return sum;
}

long long topRight(int r, int c, int &netSize, vector<vector<int>> &grid)
{
    long long sum = 0;
    for (int i = r; i < r + netSize; i++, c++)
    {
        if (c >= n or i >= m)
            return -1;
        sum += grid[i][c];
    }

    return sum;
}

long long bottomLeft(int r, int c, int &netSize, vector<vector<int>> &grid)
{
    long long sum = 0;
    r = r + netSize - 1, c = c - netSize + 1;
    for (int i = r; i < r + netSize; i++, c++)
    {
        if (c >= n or i >= m)
            return -1;

        sum += grid[i][c];
    }

    return sum;
}

long long bottomRight(int r, int c, int &netSize, vector<vector<int>> &grid)
{
    long long sum = 0;
    r = r + netSize - 1, c = c + netSize - 1;
    for (int i = r; i < r + netSize; i++, c--)
    {
        if (c < 0 or i >= m)
            return -1;
        sum += grid[i][c];
    }

    return sum;
}

long long solve(int netSize, vector<vector<int>> &grid)
{
    int c = netSize - 1;
    unordered_map<int, unordered_map<int, vector<long long>>> mp;
    long long sum = 0, upto = (2 * netSize) - 2, mx = 0;
    int x = 0, flag = 0;

    for (int i = 0; i <= upto; i++)
    {
        for (int j = c - x; j <= c + x; j++)
            sum += grid[i][j];

        if (flag == 1)
            x--;
        else
        {
            x++;
            if (x == netSize)
            {
                flag = 1;
                x = x - 2;
            }
        }
    }

    mx = sum;
    long long presum;
    for (int i = 0; i + (2 * netSize - 2) < m; i++)
    {
        mp[i][c].push_back(topLeft(i, c, netSize, grid));
        mp[i][c].push_back(topRight(i, c, netSize, grid));
        mp[i][c].push_back(bottomLeft(i, c, netSize, grid));
        mp[i][c].push_back(bottomRight(i, c, netSize, grid));

        if (i > 0)
            sum += mp[i][c][2] + mp[i][c][3] - grid[i + (2 * netSize - 2)][c];

        presum = sum;
        mx = max(mx, sum);

        for (int j = c + 1; j + netSize <= n; j++)
        {
            mp[i][j].push_back(topLeft(i, j, netSize, grid));
            mp[i][j].push_back(topRight(i, j, netSize, grid));
            mp[i][j].push_back(bottomLeft(i, j, netSize, grid));
            mp[i][j].push_back(bottomRight(i, j, netSize, grid));

            sum -= mp[i][j - 1][0] - mp[i][j - 1][2] + grid[i + netSize - 1][j - netSize];
            sum += mp[i][j][1] + mp[i][j][3] - grid[i + netSize - 1][j + netSize - 1];
            mx = max(mx, sum);
        }
        sum = presum - mp[i][c][0] - mp[i][c][1] + grid[i][c];
    }
    return mx;
}

void start()
{
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    }
    int lr = (m + 1) / 2, lc = (n + 1) / 2;
    long long mx = 0;

    for (int i = 1; i <= lr && i <= lc; i++)
        mx = max(mx, solve(i, grid));

    cout << mx << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    for (int casenum = 1; casenum <= t; casenum++)
    {
        // cout << "Case #" << casenum << ": ";
        start();
    }

    return 0;
}

/**
 *    author:  Md. Bokhtiar Nadeem Shawon
 *    created: 28-Nov-2024 19:15:12
 **/
