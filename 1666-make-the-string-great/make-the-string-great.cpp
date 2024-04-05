class Solution {
public:
    string makeGood(string s) {
        stack<char> t;
t.push(s[s.length()-1]);
        for(int i=s.length()-2; i>=0; i--){

            
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