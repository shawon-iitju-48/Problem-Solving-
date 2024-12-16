#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
#define MOD 1000000007

void start() {
    long long n, m, q;
    scanf("%lld %lld %lld", &n, &m, &q);

    vector<long long> query(q), a(n), b(m);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    for (int i = 0; i < m; i++) scanf("%lld", &b[i]);
    for (int i = 0; i < q; i++) scanf("%lld", &query[i]);

    long long totalSum = 0;
    vector<long long> row(n, 0), col(m, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long long val = a[i] * b[j];
            totalSum += val;
            row[i] += val;
            col[j] += val;
        }
    }

    unordered_set<long long> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long long target = totalSum - row[i] - col[j] + a[i] * b[j];
            st.insert(target);
        }
    }

    // Use fast output using printf
    for (int i = 0; i < q; i++) {
        if (st.count(query[i])) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    start();
    return 0;
}
