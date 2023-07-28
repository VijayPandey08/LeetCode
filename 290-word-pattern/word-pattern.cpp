class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string check="";
        // s.push_back(' ');
        for(int i=0; i<s.length(); i++){
            if(s[i]==' '){
                v.push_back(check);
                check="";
            }
            else{
                check.push_back(s[i]);
            }
            // if(i==s.length-1){
            //     v.push_back(check);
            // }
        }
        v.push_back(check);
        map<char,string> m;
        map<string,char> p;
        if(pattern.length()!=v.size()) return false;
        for(int i=0; i<pattern.length(); i++){
           if(!(p[v[i]])){
              p[v[i]]=pattern[i];
           }
           else{
               if(p[v[i]]!=pattern[i]) return false;
           }
        }



        for(int i=0; i<pattern.length(); i++){
            if((m[pattern[i]])==""){
            m[pattern[i]]=v[i];
            }
            else{
                if(m[pattern[i]]!=v[i]) return false;
            }

        }
        return true;
    }
};