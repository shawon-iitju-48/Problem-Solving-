/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution
{
public:
    void dfs(int i, vector<bool> &visited, vector<vector<int>> &rooms)
    {
        visited[i] = true;
        for (auto &j; rooms[i])
        {
            if (!visited[j])
                dfs(j, visited, rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> visited(n, false);
        dfs(0, visited, rooms);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                return false;
        }
        return true;
    }
};
// @lc code=end
