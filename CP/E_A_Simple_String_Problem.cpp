#include <bits/stdc++.h>
using namespace std;

vector<long long> tree, lazy;
int treeSize;

// Propagate function to apply lazy updates
void propagate(int node, int nodeLeft, int nodeRight)
{
    if (lazy[node] != 0)
    {
        tree[node] += lazy[node];
        if (nodeLeft != nodeRight)
        {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
}

// Iterative update function
void updatePoint(int idx, long long val)
{
    int node = 0, nodeLeft = 0, nodeRight = treeSize - 1;

    // Traverse down to the leaf node
    while (nodeLeft != nodeRight)
    {
        propagate(node, nodeLeft, nodeRight); // Ensure any pending updates are applied
        int mid = (nodeLeft + nodeRight) / 2;

        if (idx <= mid)
        {
            node = 2 * node + 1;
            nodeRight = mid;
        }
        else
        {
            node = 2 * node + 2;
            nodeLeft = mid + 1;
        }
    }

    // Apply the update to the leaf node
    tree[node] += val;
    tree[node] = max(tree[node], 0LL); // Ensure non-negative values

    // Propagate updates upwards (update the parent nodes)
    while (node > 0)
    {
        node = (node - 1) / 2;
        propagate(node, nodeLeft, nodeRight);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

// Iterative range query function
long long queryRange(int queryLeft, int queryRight)
{
    int node = 0, nodeLeft = 0, nodeRight = treeSize - 1;
    long long result = 0;

    while (nodeLeft <= nodeRight)
    {
        propagate(node, nodeLeft, nodeRight); // Ensure any pending updates are applied

        if (queryRight < nodeLeft || queryLeft > nodeRight) // No overlap
        {
            return 0;
        }
        else if (queryLeft <= nodeLeft && queryRight >= nodeRight) // Total overlap
        {
            result += tree[node];
            break;
        }

        // Partial overlap, push child nodes to stack for further exploration
        int mid = (nodeLeft + nodeRight) / 2;
        if (queryRight <= mid)
        {
            node = 2 * node + 1;
            nodeRight = mid;
        }
        else if (queryLeft > mid)
        {
            node = 2 * node + 2;
            nodeLeft = mid + 1;
        }
        else
        {
            long long leftQuery = queryRange(queryLeft, mid);
            long long rightQuery = queryRange(mid + 1, queryRight);
            result += leftQuery + rightQuery;
            break;
        }
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<string, int>> lst;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        lst.push_back({s, i});
    }
    sort(lst.begin(), lst.end());
    int idx = 0;
    treeSize = n + 2;
    int mp[treeSize];
    for (int i = 0; i < lst.size(); i++)
        mp[lst[i].second] = idx++;

    tree.resize(4 * treeSize, 0);
    lazy.resize(4 * treeSize, 0);

    int q;
    cin >> q;
    while (q--)
    {
        string command;
        int x, y;
        cin >> command >> x >> y;
        if (command == "add")
        {
            int point = mp[x - 1];
            updatePoint(point, y);
        }
        else if (command == "delete")
        {
            int point = mp[x - 1];
            updatePoint(point, -y);
        }
        else if (command == "count")
        {
            int pointA = mp[x - 1], pointB = mp[y - 1];
            cout << queryRange(min(pointA, pointB), max(pointA, pointB)) << endl;
        }
    }

    return 0;
}
