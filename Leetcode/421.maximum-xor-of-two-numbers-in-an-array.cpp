/*
 * @lc app=leetcode id=421 lang=cpp
 *
 * [421] Maximum XOR of Two Numbers in an Array
 */

// @lc code=start
class Trie
{
public:
    struct TrieNode
    {
        TrieNode *child[2];
        TrieNode() : child{nullptr} {}
    };
    TrieNode *root, *crawl, *node;
    Trie() { root = new TrieNode(); }

    void insert(bitset<32> &binary)
    {
        crawl = root;
        for (int i = 31; i >= 0; i--)
        {
            if (crawl->child[binary[i]] == nullptr)
            {
                node = new TrieNode();
                crawl->child[binary[i]] = node;
                crawl = node;
            }
            else
                crawl = crawl->child[binary[i]];
        }
    }
};
class Solution
{
public:
    int solve(bitset<32> &binary, Trie::TrieNode *crawl)
    {
        unsigned int sum = 0, power = 1 << 31;

        for (int i = 31; i >= 0; i--)
        {
            if (crawl->child[1 - binary[i]] != nullptr)
            {
                crawl = crawl->child[1 - binary[i]];
                sum += power;
            }
            else
                crawl = crawl->child[binary[i]];
            power >>= 1;
        }
        return sum;
    }
    int findMaximumXOR(vector<int> &nums)
    {
        Trie *trie = new Trie();
        for (auto &num : nums)
        {
            bitset<32> binary(num);
            trie->insert(binary);
        }
        int mx = 0;
        for (auto &num : nums)
        {
            bitset<32> binary(num);
            mx = max(mx, solve(binary, trie->root));
        }
        return mx;
    }
};
// @lc code=end
