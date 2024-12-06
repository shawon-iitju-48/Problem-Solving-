/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int front=0,back=height.size()-1,area=min(height[front],height[back])*back;
        while(front<back)
        {
            if(height[back]>=height[front])
            front++;
            else back--;
            int newarea=min(height[front],height[back])*(back-front);
            area=max(area,newarea);
        }
        return area;

    }
};
// @lc code=end
//lower height diye best ta pauwa shesh, tai lowerta theke agate hobe for front or pichate hobe for back.

