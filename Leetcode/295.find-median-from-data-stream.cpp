/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder
{
public:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<>> minpq;
    double currmedian = 0;
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (num <= currmedian)
        {
            if (maxpq.size() > minpq.size())
            {
                minpq.push(maxpq.top());
                maxpq.pop();
                maxpq.push(num);
            }
            else
                maxpq.push(num);
        }
        else
        {
            if (maxpq.size() < minpq.size())
            {
                maxpq.push(minpq.top());
                minpq.pop();
                minpq.push(num);
            }
            else
                minpq.push(num);
        }

        if (minpq.size() == maxpq.size())
            currmedian = (minpq.top() + maxpq.top()) / 2.0;
        else
        {
            if (minpq.size() > maxpq.size())
                currmedian = minpq.top();
            else
                currmedian = maxpq.top();
        }
    }

    double findMedian()
    {
        return currmedian;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
