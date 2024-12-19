/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 */

// @lc code=start
class Trie
{
public:
    struct TrieNode
    {
        bool wordFound;
        TrieNode *child[26];

        TrieNode() : wordFound(false)
        {
            fill(begin(child), end(child), nullptr);
        }
    };

    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(const string &word)
    {
        TrieNode *crawl = root;
        for (char w : word)
        {
            int ch = w - 'a';
            if (crawl->child[ch] == nullptr)
            {
                crawl->child[ch] = new TrieNode();
            }
            crawl = crawl->child[ch];
        }
        crawl->wordFound = true;
    }

    string startsWith(const string &prefix)
    {
        TrieNode *crawl = root;
        string temp = "";
        for (char p : prefix)
        {

            int ch = p - 'a';
            if (crawl->child[ch] == nullptr || crawl->wordFound)
                return crawl->wordFound ? temp : prefix;
            crawl = crawl->child[ch];
            temp += p;
        }
        return prefix;
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie trie;
        for (const string &word : dictionary)
        {
            trie.insert(word);
        }

        string ans = "";
        stringstream ss(sentence);
        string word;
        while (ss >> word)
        {
            ans += trie.startsWith(word) + " ";
        }

        if (!ans.empty())
        {
            ans.pop_back(); // Remove the trailing space
        }
        return ans;
    }
};
// @lc code=end
