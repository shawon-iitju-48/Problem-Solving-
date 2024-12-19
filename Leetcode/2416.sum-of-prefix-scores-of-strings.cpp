/*
 * @lc app=leetcode id=2416 lang=cpp
 *
 * [2416] Sum of Prefix Scores of Strings
 */

// @lc code=start
class Trie
{
public:
    struct TrieNode
    {
        int cnt;
        TrieNode *child[26];

        TrieNode() : cnt(0), child{nullptr} {}
    };
    TrieNode *root, *crawl, *node;
    Trie() { root = new TrieNode(); }

    void insert(string word)
    {
        crawl = root;
        for (auto &w : word)
        {
            int ch = w - 'a';
            if (crawl->child[ch] == nullptr)
            {
                node = new TrieNode();
                crawl->child[ch] = node;
                crawl = node;
            }
            else
                crawl = crawl->child[ch];
            crawl->cnt++;
        }
    }

    int search(string word)
    {
        crawl = root;
        int sum = 0;
        for (auto &w : word)
        {
            int ch = w - 'a';
            crawl = crawl->child[ch];
            sum += crawl->cnt;
        }
        return sum;
    }
};
class Solution
{
public:
    vector<int> sumPrefixScores(vector<string> &words)
    {
        Trie trie;
        for(auto &word: words)
        trie.insert(word);

        vector<int>ans;
        for(auto &word: words)
        ans.push_back(trie.search(word));

        return ans;
    }
};
// @lc code=end
