class Solution
{
    public:
        int lengthOfLastWord(string s)
        {
           int ans = 0;
            vector<char> v;
            cout<<v.size();
            
            // if(s.length()==1 && s[0]!=' ') return 1;
            // if(s.length()==2 && s[1]==' ') return 1;
            for (int i = s.length() - 1; i >= 0; i--)
            {
                if (s[i] == ' ' && v.size() == 0)
                {
                    continue;
                }
                if (s[i] != ' ')
                {
                    v.push_back(s[i]);
                }
                if (s[i] == ' ' && v.size() >0)
                {
                    break;
                }
            }

            return v.size();
        }
};