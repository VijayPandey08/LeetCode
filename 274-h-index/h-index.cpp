class Solution
{
    public:
        int hIndex(vector<int> &c)
        {
            sort(c.begin(), c.end());
            int ans = 0;
            int k = 1;
            for (int i = c.size() - 1; i >= 0; i--)
            {
                if (c[i] >= k)
                {
                    ans++;
                k++;
                }
                else
                {
                    break;
                }
            }
            return ans;
        }
};