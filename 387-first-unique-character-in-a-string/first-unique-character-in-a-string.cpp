class Solution {
public:
    int firstUniqChar(string s) {
        queue<char> q;
        int freq[26]={0};
        for(int i=0; i<s.length(); i++){
           char firstchar=s[i];
           freq[s[i]-'a']++;
           q.push(firstchar);
        }
     while(!q.empty()){
         char frontChar=q.front();
         if(freq[frontChar-'a']>1){
             q.pop();
         }
         else{
             for(int i=0; i<s.length(); i++){
                 if(s[i]==frontChar){
                     return i;
                 }
             }
         }
     }
        return -1;
    }
};