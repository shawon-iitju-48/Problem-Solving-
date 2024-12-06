/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution
{
public:
    void floodfill(vector<vector<int>> &image, int i, int j, int color, int target)
    {
        image[i][j] = color;
        if (i - 1 >= 0 and image[i - 1][j] == target)
            floodfill(image, i - 1, j, color, target);
        if (i + 1 < image.size() and image[i + 1][j] == target)
            floodfill(image, i + 1, j, color, target);
        if (j - 1 >= 0 and image[i][j - 1] == target)
            floodfill(image, i, j - 1, color, target);
        if (j + 1 < image[0].size() and image[i][j + 1] == target)
            floodfill(image, i, j + 1, color, target);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int target = image[sr][sc];
        if (target == color)
            return image;
        floodfill(image, sr, sc, color, target);
        return image;
    }
};
// @lc code=end
