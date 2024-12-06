#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char s[10][10];
        int i, j;
        for (i = 0; i < 8; i++)
        {
            for (j = 0; j < 8; j++)
                cin >> s[i][j];
        }
        for (i = 1; i < 7; i++)
        {
            int flag = 0;
            for (j = 1; j < 7; j++)
            {
                if (s[i][j] == '#' && s[i - 1][j - 1] == '#' && s[i - 1][j + 1] == '#' && s[i + 1][j - 1] == '#' && s[i + 1][j + 1] == '#')
                {
                    flag = 1;
                    cout << i + 1 << ' ' << j + 1 << endl;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
    }
    return 0;
}