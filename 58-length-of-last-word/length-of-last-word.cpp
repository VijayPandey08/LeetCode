class Solution {
public:
    int lengthOfLastWord(string s) {
        int k = s.length();
        int ans=0;
        while(k--){
              if(s[k]==' ' && ans==0){
                continue;
              }
              else if(s[k]!= ' '){
                ans++;
              }
              else if(s[k]==' ' && ans>0){
                return ans;
              }
        }
        return ans;
    }
};