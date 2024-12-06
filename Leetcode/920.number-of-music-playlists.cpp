/*
 * @lc app=leetcode id=920 lang=cpp
 *
 * [920] Number of Music Playlists
 */

// @lc code=start
class Solution
{
public:
    long long dp[101][101], n, goal, k;
    const int MOD = 1e9 + 7;

    long long solve(long long cnt_song, long long unique_song)
    {
        if (cnt_song == goal)
            return (unique_song == n) ? 1 : 0;

        if (dp[cnt_song][unique_song] != -1)
            return dp[cnt_song][unique_song];

        long long play_unique = ((n - unique_song) * solve(cnt_song + 1, unique_song + 1)) % MOD;
        long long replay = (max(0LL, (unique_song - k)) * solve(cnt_song + 1, unique_song)) % MOD;

        return dp[cnt_song][unique_song] = (play_unique + replay) % MOD;
    }
    int numMusicPlaylists(int nn, int goall, int kk)
    {
        n = nn, goal = goall, k = kk;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};
// @lc code=end
