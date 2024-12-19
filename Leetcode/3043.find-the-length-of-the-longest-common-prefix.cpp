/*
 * @lc app=leetcode id=3043 lang=cpp
 *
 * [3043] Find the Length of the Longest Common Prefix
 */

// @lc code=start
class Trie
{
public:
    struct TrieNode
    {
        bool one, two;
        TrieNode *child[10];

        TrieNode() : one(false), two(false), child{nullptr} {}
    };
    TrieNode *root, *crawl, *node;
    Trie() { root = new TrieNode(); }

    int mx = INT_MIN;
    void insert(string word, int flag)
    {
        crawl = root;
        for (int i = 0; i < word.size(); i++)
        {
            int ch = word[i] - '0';
            if (crawl->child[ch] == nullptr)
            {
                node = new TrieNode();
                crawl->child[ch] = node;
                crawl = node;
            }
            else
                crawl = crawl->child[ch];

            if (flag == 0)
                crawl->one = true;
            else
                crawl->two = true;

            if (crawl->one and crawl->two)
                mx = max(mx, i + 1);
        }
    }
};
class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        Trie trie;
        for(auto &num: arr1)
        trie.insert(to_string(num), 0);

        for(auto &num: arr2)
        trie.insert(to_string(num), 1);

        return trie.mx;
    }
};
// @lc code=end
