class Solution
{
    public:
        vector<int> plusOne(vector<int> &d)
        {
            
            vector<int> ans;
            int n = d.size();
            for (int i = n - 1; i >= 0; i--)
            {
                if ((d[i]) < 9)
                {
                    d[i] += 1;
                    return d;
                }
                else
                {
                    d[i] = 0;
                }
            }

d.push_back(1);
reverse(d.begin(),d.end());

            return d;
        }
};