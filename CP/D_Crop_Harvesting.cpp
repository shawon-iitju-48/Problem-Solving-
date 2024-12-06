#include <bits/stdc++.h>
using namespace std;

int miniTime, k;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void bfs(queue<pair<int, pair<int, int>>> &q, vector<vector<int>> &grid, int flag)
{
    int cnt = -1;
    while (!q.empty())
    {
        int step = q.front().first, r = q.front().second.first, c = q.front().second.second;
        cnt++;
        q.pop();

        if (grid[r][c] == -1)
            continue;

        grid[r][c] = -1;
        miniTime += (2 * step);

        if (flag == 1 and cnt == k)
        {
            while (!q.empty())
                q.pop();
            return;
        }

        // Explore neighbors
        for (auto dir : directions)
        {
            int newI = r + dir.first;
            int newJ = c + dir.second;
            if (newI >= 0 and newI < grid.size() and newJ >= 0 and newJ < grid[0].size() and grid[newI][newJ] == 0)
                q.push({step + 1, {newI, newJ}});
        }
    }
}

void solve()
{
    int m, n, r, c;
    cin >> m >> n >> k;
    vector<vector<int>> grid(m, vector<int>(n, 0)); // 0=crop, 1=godown, -1=cropCollected
    int harvester;
    cin >> harvester;
    vector<pair<int, int>> godown;
    for (int i = 0; i < harvester; i++)
    {
        cin >> r >> c;
        grid[r - 1][c - 1] = 1;
        godown.push_back({r - 1, c - 1});
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {godown[0].first, godown[0].second}});
    bfs(q, grid, 1);

    for (int i = 1; i < harvester; i++)
        q.push({0, {godown[i].first, godown[i].second}});

    bfs(q, grid, 0);
    cout << miniTime << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int caseNum = 1; caseNum <= t; caseNum++)
    {
        miniTime = 0;
        cout << "Case " << caseNum << ": ";
        solve();
    }
    return 0;
}
