class Solution
{
public:
    int secondMinimum(int n, vector<vector<int>> &edges, int time, int change)
    {
        vector<vector<int>> adj(n + 1);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;

        q.push({0, 1, 0});
        vector<int> res(n + 1, 1e8), secres(n + 1, 1e8);
        res[1] = 0;

        while (!q.empty())
        {
            int timeElapsed = q.top()[0], node = q.top()[1], stop = q.top()[2];
            q.pop();

            if ((timeElapsed / change) % 2 == 1)
                timeElapsed += (change - (timeElapsed % change));

            for (auto &neighbor : adj[node])
            {
                int newtime = timeElapsed + time;
                if (newtime < res[neighbor])
                {
                    q.push({newtime, neighbor, stop + time});
                    secres[neighbor] = res[neighbor];
                    res[neighbor] = newtime;
                }
                else if (newtime > res[neighbor] && newtime < secres[neighbor])
                {
                    q.push({newtime, neighbor, stop + time});
                    secres[neighbor] = newtime;
                }
            }
        }
        return secres[n];
    }
};
