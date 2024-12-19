/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie
{
public:
    struct TrieNode
    {
        bool wordFound;
        TrieNode *child[26];

        TrieNode() : wordFound(false), child{nullptr} {}
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
        }
        crawl->wordFound = true;
    }

    bool search(string word)
    {
        crawl = root;
        for (auto &w : word)
        {
            int ch = w - 'a';
            if (crawl->child[ch] == nullptr)
                return false;

            crawl = crawl->child[ch];
        }
        return crawl->wordFound;
    }

    bool startsWith(string prefix)
    {
        crawl = root;
        for (auto &p : prefix)
        {
            int ch = p - 'a';
            if (crawl->child[ch] == nullptr)
                return false;

            crawl = crawl->child[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
