#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007

void start()
{
    int n;
    cin>>n;
    vector<int>nums(n), bnums(n);
    unordered_map<int, int>mp;
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
        mp[i+1]=1;
    }

    for(int i=0;i<n;i++)
    {
        if(mp.count(nums[i]))
        {
            bnums[i]=nums[i];
            mp.erase(nums[i]);
        }
        else
        {
            bnums[i]=mp.begin()->first;
            mp.erase(bnums[i]);
        }
    }

    for(int i=0;i<n;i++)
    cout<<bnums[i]<<' ';
    cout<<endl;


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
 *    created: 15-Dec-2024 21:00:02
**/