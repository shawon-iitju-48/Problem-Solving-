#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007

void start()
{
    int n;
    cin >> n;

    vector<int> nums(n), vis(n, false), temp;
    stack<int> stk;
    map<int, vector<int>> mp;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        mp[nums[i]].push_back(i);
    }

    int start = 0;
    for (auto &it : mp)
    {
        for (auto &index : it.second)
        {
            if (!vis[index])
            {
                vis[index] = true;
                for (int i = start; i < index; i++)
                {
                    if (!vis[i])
                    {
                        vis[i] = true;
                        temp.push_back(nums[i] + 1);
                    }
                }
                stk.push(nums[index]);
                start = index + 1;
            }
        }
    }

    sort(begin(temp), end(temp));

    while (!stk.empty() && !temp.empty() && stk.top() > temp[0])
    {
        temp.push_back(stk.top() + 1);
        stk.pop();
    }
    sort(begin(temp), end(temp));

    vector<int> ans;
    while (!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    ans.insert(ans.end(), temp.begin(), temp.end());

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
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
 *    created: 06-Dec-2024 23:30:13
 **/