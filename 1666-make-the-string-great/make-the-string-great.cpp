class Solution {
public:
    string makeGood(string s) {
        stack<char> t;
        for(int i=s.length()-1; i>=0; i--){

            
            if(!t.empty() && (s[i]-'a'==t.top()-'A' || s[i]-'A'==t.top()-'a')){
                t.pop();
                continue;
            
            }
                t.push(s[i]);


        }
        string ans="";
        while(!t.empty()){
            char c = t.top();
            ans.push_back(c);
            t.pop();
        }
        
        return ans;
    }
};