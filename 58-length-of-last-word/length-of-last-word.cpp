class Solution
{
    public:
        int lengthOfLastWord(string s)
        {
            int ans = 0;
            vector<char> v;

            for (int i = s.length() - 1; i >= 0; i--)
            { 
                // agar last mein space ho toh uss case mein aage bdh jaao continue krke
                if (s[i] == ' ' && ans == 0)
                {
                    continue;
                }
                // agar space nhi h, toh ans++ krdo
                if (s[i] != ' ')
                {
                    ans++;
                }
                //jesi pehla space mile  ans>0(mtlb last word ke bad) break kr do
               if (s[i] == ' ' && ans > 0)
                {
                    break;
                }
            }

            return ans;
        }
};