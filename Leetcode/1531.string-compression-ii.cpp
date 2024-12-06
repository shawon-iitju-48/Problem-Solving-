class Solution
{
public:
    int digit(int n)
    {
        if (n <= 1)
            return 0;
        if (n < 10)
            return 1;
        if (n < 100)
            return 2;
        return 3;
    }

    

    int getLengthOfOptimalCompression(string s, int k)
    { 
    }
};
