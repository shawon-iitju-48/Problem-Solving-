/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 */

// @lc code=start
class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;
        else
        {
            int koyta = hand.size() / groupSize, cnt = 0;
            map<int, int> mp;
            for (int i = 0; i < hand.size(); i++)
                mp[hand[i]]++;
            int flag = 0;
            while (mp.size() != 0)
            {
                auto it = mp.begin();
                int pre = -1;
                cnt++;
                for (int i = 1; i <= groupSize && it != mp.end(); ++it, ++i)
                {
                    if (pre != -1 and abs(pre - it->first) != 1)
                    {
                        flag = 1;
                        break;
                    }
                    pre = it->first;
                    mp[it->first]--;
                    if (mp[it->first] == 0)
                        mp.erase(it);
                }
                if (flag == 1)
                    break;
            }
            if (flag == 1 or cnt != koyta)
                return false;
            else
                return true;
        }
    }
};
// @lc code=end
