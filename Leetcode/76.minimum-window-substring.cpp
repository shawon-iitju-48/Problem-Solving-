class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> tmap(58, 0), smap(58, 0);
        for (auto &ch : t)
            tmap[(ch - 'A') % 65]++;
            
        int i = 0, mn = INT_MAX, n = t.size();
        string ans = "";
        for (int j = 0; j < s.size(); j++)
        {
            smap[(s[j] - 'A') % 65]++;
            if (j >= n - 1)
            {
                int flag = 0;
                for (int d = 0; d < 58; d++)
                {
                    if (smap[d] < tmap[d])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    while (true)
                    {
                        smap[(s[i] - 'A') % 65]--;
                        if (smap[(s[i] - 'A') % 65] >= tmap[(s[i] - 'A') % 65])
                            i++;
                        else
                        {
                            smap[(s[i] - 'A') % 65]++;
                            if (j - i + 1 < mn)
                            {
                                mn = j - i + 1;
                                ans = s.substr(i, j - i + 1);
                            }
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};