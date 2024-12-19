/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Trie
{
public:
    struct TrieNode
    {
        bool wordFound;
        string word;
        TrieNode *child[26];

        TrieNode() : wordFound(false), word(""), child{nullptr} {}
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
        crawl->word = word;
    }
};
class Solution
{
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(int i, int j, vector<vector<char>> &board, vector<string> &ans, Trie::TrieNode *crawl)
    {
        char temp = board[i][j];
        board[i][j] = '$';

        if (crawl->wordFound)
        {
            ans.push_back(crawl->word);
            crawl->wordFound = false;
        }

        for (auto [x, y] : dir)
        {
            int newI = i + x, newJ = j + y;
            if (newI >= 0 and newJ >= 0 and newI < board.size() and newJ < board[0].size() and board[newI][newJ] != '$' and crawl->child[board[newI][newJ] - 'a'] != nullptr)
                dfs(newI, newJ, board, ans, crawl->child[board[newI][newJ] - 'a']);
        }

        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        Trie *trie = new Trie();

        for (auto &word : words)
            trie->insert(word);

        vector<string> ans;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                int ch = board[i][j] - 'a';
                if (trie->root->child[ch] != nullptr)
                    dfs(i, j, board, ans, trie->root->child[ch]);
            }
        }

        return ans;
    }
};
// @lc code=end
