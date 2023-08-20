class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        // bool check = false;
        // vector<char> v;
        // vector<char> h;
        // for(int i=0;i<words.size();i++)
        // {
        //     char ch=words[i][0];
        //     v.push_back(ch);
        // }
        // for(int i=0;i<s.length();i++)
        // {
        //     h.push_back(s[i]);
        // }
        // if(v==h)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }
        
        int c=0;
        for(auto i:words){
            
            char ch=i[0];
            if(ch==s[c])
            {
                c+=1;
                continue;
            }
            else
            {
                return false;
            }
        }
        if(s.length()>words.size())
        {
            return false;
        }
        return true;
    }
};