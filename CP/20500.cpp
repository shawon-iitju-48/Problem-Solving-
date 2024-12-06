#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007

void start()
{
    int n, m;
    cin>>n>>m;
    vector<string>v;
    string s;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        v.push_back(s);
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i].size();
        if(sum==m)
        {
            cout<<i+1<<endl;
            return;
        }
        else if(sum>m)
        {
            cout<<i<<endl;
            return;
        }
    }
    cout<<n<<endl;
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
 *    created: 05-Dec-2024 20:39:09
**/