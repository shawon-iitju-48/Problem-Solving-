/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 */

// @lc code=start
class Twitter
{
public:
    unordered_map<int, unordered_map<int, int>> mp;
    vector<pair<int, int>> tweet;

    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        tweet.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> ans;
        int cnt = 0;
        for (int i = tweet.size() - 1; i >= 0; i--)
        {
            if (mp[userId].find(tweet[i].first) != mp[userId].end() or userId == tweet[i].first)
            {
                cnt++;
                ans.push_back(tweet[i].second);
            }
            if (cnt == 10)
                break;
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        mp[followerId][followeeId] = 1;
    }

    void unfollow(int followerId, int followeeId)
    {

        mp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
