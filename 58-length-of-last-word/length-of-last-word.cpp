class Solution
{
    public:
        int lengthOfLastWord(string s)
        {
           int ans = 0;
            vector<char> v;
           
            for (int i = s.length() - 1; i >= 0; i--)
            {
                if (s[i] == ' ' && ans==0)
                {
                    continue;
                }
                if (s[i] != ' ')
                {
                    ans++;
                }
                if (s[i] == ' ' && ans >0)
                {
                    break;
                }
            }

            return ans;
        }
};