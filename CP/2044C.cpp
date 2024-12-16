#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007

void start()
{
    int m, a, b,c, obo=0, sum=0;
    cin>>m>>a>>b>>c;
    sum+=min(m, a);
    obo=m-min(m, a);

    sum+=min(m, b);
    obo+=m-min(m, b);

    sum+=min(obo, c);
    cout<<sum<<endl;
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
 *    created: 15-Dec-2024 20:46:15
**/