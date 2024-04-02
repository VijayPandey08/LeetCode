class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;


        for(int i=0; i<s.length(); i++){
            if(m.find(s[i])==m.end()){
                m[s[i]]=t[i];            
            }

            else{
                if(m[s[i]]==t[i]){
                    continue;
                }
                else{
                    return false;
                }
            }
        }
        for(auto i: m){
            for(auto j:m){
                if(i.first!=j.first && i.second==j.second) return false;
            }
        }
        return true;
    }
};