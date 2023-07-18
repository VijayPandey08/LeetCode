class Solution
{
    public:
        bool isSubsequence(string s, string t)
        {
            
            int a = 0;
            int b = t.length();
            int temp = 0;
            int count = 0 ; 
            for (int i = 0; i < s.length(); i++)
            {
                for (int j = temp; j < t.length(); j++)
                {
                    if (s[i] == t[j])
                    {
                        count++;
                        temp = j+1;
                        break;
                    }
                }
            }
            if(count==s.length()){
                return true;
            }
            return false;
        }
};