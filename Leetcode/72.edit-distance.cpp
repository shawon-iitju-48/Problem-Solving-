class Solution
{
public:
    int dfs(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if (j == word2.size() and i != word1.size())
            return word1.size() - i;

        if (i == word1.size())
            return word2.size() - j;

        if (dp[i][j] != -1)
            return dp[i][j];
        if (word1[i] == word2[j])
            return dfs(i + 1, j + 1, word1, word2, dp);
        else
        {
            int insertt = 0, replacee = 0, deletee = 0;
            insertt = 1 + dfs(i, j + 1, word1, word2, dp);
            replacee = 1 + dfs(i + 1, j + 1, word1, word2, dp);
            deletee = 1 + dfs(i + 1, j, word1, word2, dp);
            return dp[i][j] = min(min(insertt, replacee), deletee);
        }
    }
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return dfs(0, 0, word1, word2, dp);
    }
};