#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int i, int j, vector<int> &row, vector<int> &col, vector<string> &grid)
{
    row[i]++;
    col[j]++;

    for (auto dir : directions)
    {
        int newI = i + dir.first;
        int newJ = j + dir.second;
        if (newI >= 0 and newI < grid.size() and newJ >= 0 and newJ < grid[0].size() and grid[newI][newJ] == 'X')
        {
            grid[newI][newJ] = '.';
            dfs(newI, newJ, row, col, grid);
        }
    }
}
string vtos(const vector<int> &vec)
{
    string result = "";

    for (int num : vec)
        result += to_string(num);

    size_t start = result.find_first_not_of('0');
    if (start != string::npos)
        result = result.substr(start);
    else
        result = "0";

    size_t end = result.find_last_not_of('0');
    if (end != string::npos)
        result = result.substr(0, end + 1);

    return result;
}
int main()
{
    unordered_set<string> st;
    vector<string> grid;
    string gridLine;
    while (true)
    {
        getline(cin, gridLine);
        if (gridLine.empty())
            break;
        grid.push_back(gridLine);
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            if (grid[i][j] == 'X')
            {
                grid[i][j] = '.';
                vector<int> row(grid.size(), 0), col(grid[0].size(), 0);
                dfs(i, j, row, col, grid);

                string rowStr = vtos(row), colStr = vtos(col);
                string rowRev = rowStr, colRev = colStr;

                reverse(rowRev.begin(), rowRev.end());
                reverse(colRev.begin(), colRev.end());
                string key1 = rowRev + "," + colRev, key2 = colStr + "," + rowRev, key3 = colRev + "," + rowStr, key = rowStr + "," + colStr;
                if (st.find(key1) == st.end() and st.find(key2) == st.end() and st.find(key3) == st.end())
                    st.insert(key);
            }
        }
    }
    cout << st.size() << endl;
    return 0;
}
