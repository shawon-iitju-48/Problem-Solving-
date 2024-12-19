/*
 * @lc app=leetcode id=3093 lang=cpp
 *
 * [3093] Longest Common Suffix Queries
 */

// @lc code=start
class Trie
{
public:
    struct TrieNode
    {
        bool wordFound;
        int index;
        TrieNode *child[26];

        TrieNode() : wordFound(false), index(INT_MAX), child{nullptr} {}
    };
    TrieNode *root, *crawl, *node;
    Trie() { root = new TrieNode(); }

    void insert(string word, int in)
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
        crawl->index = min(crawl->index, in);
    }

    int startsWith(string prefix)
    {
        crawl = root;
        for (auto &p : prefix)
        {
            int ch = p - 'a';
            if (crawl->child[ch] == nullptr)
                return crawl->index;

            crawl = crawl->child[ch];
        }
        return crawl->index;
    }
};
class Solution
{
public:
    int dfs(Trie::TrieNode *crawl)
    {
        int minHeight = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            if (crawl->child[i] != nullptr)
            {
                int h = 1 + dfs(crawl->child[i]);
                if (h <= minHeight)
                {
                    if (!crawl->wordFound)
                    {
                        if (h == minHeight)
                            crawl->index = min(crawl->index, crawl->child[i]->index);
                        else
                            crawl->index = crawl->child[i]->index;
                    }
                    minHeight = h;
                }
            }
        }

        return minHeight == INT_MAX or crawl->wordFound ? 0 : minHeight;
    }
    vector<int> stringIndices(vector<string> &wordsContainer, vector<string> &wordsQuery)
    {
        Trie *trie = new Trie();
        for (int i = 0; i < wordsContainer.size(); i++)
        {
            reverse(begin(wordsContainer[i]), end(wordsContainer[i]));
            trie->insert(wordsContainer[i], i);
        }

        dfs(trie->root);
        vector<int> ans;
        for (auto &word : wordsQuery)
        {
            reverse(begin(word), end(word));
            ans.push_back(trie->startsWith(word));
        }
        return ans;
    }
};
// @lc code=end
