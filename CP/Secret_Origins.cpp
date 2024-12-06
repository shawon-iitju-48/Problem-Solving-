#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,unroll-loops")
#define ll long long
#define lli long long int
#define ld long double
#define ull unsigned long long
#define ulli unsigned long long int
#define PI 3.1415926535897932384626433832795

#define sp ' '
#define pb push_back
#define ppb pop_back
#define mkpr make_pair
#define pii pair<int, int>
#define pll pair<ll, ll>
#define xx first
#define yy second
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>

#define gcd(a, b) __gcd(a, b);
#define precision(a, b) cout << fixed << setprecision(a) << b << endl
#define incfor(a, b) for (int i = a; i < b; i++)
#define decfor(a, b) for (int i = a; i > b; i--)
#define nincfor(a, b) for (int j = a; j < b; j++)
#define ndecfor(a, b) for (int j = a; j > b; j--)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve()
{
    ll n, trailing = 0;
    cin >> n;
    string binary = bitset<64>(n).to_string();
    binary.erase(0, binary.find_first_not_of('0'));

    ll length = binary.length(), one = __builtin_popcountll(n), zero = length - one;
    decfor(length - 1, -1)
    {
        if (binary[i] == '1')
            break;
        else
            trailing++;
    }
    if (trailing == zero)
    {
        binary.resize(length + 1);
        binary[0] = '1';
        zero++;
        int baro = 1;
        while (zero--)
            binary[baro++] = '0';
        while (one--)
            binary[baro++] = '1';
        bitset<64> bits(binary);
        ll dec = bits.to_ulong();
        cout << dec << endl;
    }
    else
    {
        int koytazero = 0, koytaone = 0;
        decfor(length - 1, -1)
        {
            if (binary[i] == '1' and binary[i - 1] == '0')
            {
                swap(binary[i], binary[i - 1]);
                i++;
                while (koytazero--)
                    binary[i++] = '0';
                while (koytaone--)
                    binary[i++] = '1';
                break;
            }
            if (binary[i] == '1')
                koytaone++;
            else if (binary[i] == '0')
                koytazero++;
        }
        bitset<64> bits(binary);
        ll dec = bits.to_ulong();
        cout << dec << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        cout << "Case " << t << ": ";
        solve();
    }
    return 0;
}
/**
 *    author:  lifelessnoob
 **/