#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, t, b, i;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        int temp = abs(a - b), mn = min(a, b);
        if (temp >= mn)
        {
            if (a <= b)
            {
                for (i = 1; i <= a; i++)
                    cout << '0';
                for (i = 1; i <= b; i++)
                    cout << '1';
                cout << endl;
            }
            else
            {
                for (i = 1; i <= b; i++)
                    cout << '1';
                for (i = 1; i <= a; i++)
                    cout << '0';
                cout << endl;
            }
        }
        else
        {
            if (a <= b)
            {
                for (i = 1; i <= a; i++)
                {
                    cout << "01";
                    b--;
                }
                for (i = 1; i <= b; i++)
                    cout << '1';
                cout << endl;
            }
            else
            {
                for (i = 1; i <= b; i++)
                {
                    cout << "10";
                    a--;
                }
                for (i = 1; i <= a; i++)
                    cout << '0';
                cout << endl;
            }
        }
    }
    return 0;
}