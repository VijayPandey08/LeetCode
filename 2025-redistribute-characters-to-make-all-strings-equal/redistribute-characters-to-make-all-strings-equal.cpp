class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        map<int,int> m;
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words[i].length(); j++){
                m[words[i][j]-'a']++;
            }
        }
        for(auto i: m){
           if(i.second%n!=0){
               return false;
           }
        }
        return true;
    }
};