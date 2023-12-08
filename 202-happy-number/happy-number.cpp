class Solution
{
    public:
        bool isHappy(int n)
        {
            int count = 10;
            while (count)
            {
            int ans = 0;
                while (n > 0)
                {
                    int digi = n % 10;
                    ans += (digi *digi);
                    n = n / 10;
                }
                if (ans == 1) return true;
                n = ans;
                count--;
            }
            return false;
        }
};