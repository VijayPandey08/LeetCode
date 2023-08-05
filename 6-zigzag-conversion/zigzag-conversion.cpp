class Solution {
public:
    string convert(string s, int n) {
        string ans="";
        vector<string> v(n);
        
        int i=0;
        while(i<s.length()){
            for( int j=0; j<n; j++){
                if(i==s.length()) break;
                v[j].push_back(s[i]);
                i++;
                
            }
            for( int j=n-2; j>=1; j--){
                if(i==s.length()) break;
                v[j].push_back(s[i]);
                i++;
            }
        }
        for(auto i: v){
            ans=ans+i;
        }
        return ans;
    }
};