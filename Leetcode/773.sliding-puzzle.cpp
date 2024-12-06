/*
 * @lc app=leetcode id=773 lang=cpp
 *
 * [773] Sliding Puzzle
 */

// @lc code=start
class Solution
{
public:
    vector<long long> power;
    Solution()
    {
        power.resize(6);
        power[0] = 1;
        for (int i = 1; i < 6; i++)
            power[i] = 31 * power[i - 1];
    }
    long long hashRolling(int posA, int posB, long long currHash, vector<int> &nums)
    {
        long long numAtPosA = nums[posA], numsAtPosB = nums[posB];

        long long tempHash = currHash - (numAtPosA * power[posA]) - (numsAtPosB * power[posB]);
        long long newHash = tempHash + (numAtPosA * power[posB]) + (numsAtPosB * power[posA]);
        return newHash;
    }

    int slidingPuzzle(vector<vector<int>> &board)
    {
        vector<int> nums;
        int currentPos = -1;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
            {
                nums.push_back(board[i][j]);
                if (board[i][j] == 0)
                    currentPos = nums.size() - 1;
            }

        long long Hash = nums[0], targetHash = 1;
        for (int i = 1; i < 6; i++)
            Hash += power[i] * (long long)nums[i];

        for (int i = 2; i <= 6; i++)
        {
            long long curr = i % 6;
            targetHash += power[i - 1] * curr;
        }

        vector<vector<int>> adj = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        unordered_set<long long> vis;

        queue<pair<int, pair<long long, pair<int, vector<int>>>>> q;
        q.push({0, {Hash, {currentPos, nums}}});
        vis.insert(Hash);

        while (!q.empty())
        {
            int step = q.front().first;
            long long currHash = q.front().second.first;
            vector<int> currNums = q.front().second.second.second;
            int currPos = q.front().second.second.first;

            q.pop();

            if (targetHash == currHash)
                return step;

            for (auto &neighbor : adj[currPos])
            {
                long long rollHash = hashRolling(currPos, neighbor, currHash, currNums);
                if (vis.find(rollHash) == vis.end())
                {
                    vis.insert(rollHash);
                    swap(currNums[currPos], currNums[neighbor]);
                    q.push({step + 1, {rollHash, {neighbor, currNums}}});
                    swap(currNums[currPos], currNums[neighbor]);
                }
            }
        }
        return -1;
    }
};
// @lc code=end
