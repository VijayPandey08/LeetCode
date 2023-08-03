class Solution {
public:
    string reverseWords(string s) {
        string  ans="";
        vector<string> v;
        string temp="";


        for(int i=0; i<s.length(); i++){
            if(s[i]!=' '){
                temp.push_back(s[i]);
            }
            else{
                if(temp!=""){
                    v.push_back(temp);
                    temp="";
                }
            }
        }
                    if(temp!=""){
                    v.push_back(temp);
                    temp="";
                }

                reverse(v.begin(),v.end());
                ans = ans + v[0];
                for(int i=1; i<v.size(); i++){
                    ans+=" ";
                    ans+=v[i];
                }
                // for(auto i: v){
                //     cout<<i<<" ";
                // }
                return ans;
    }
};