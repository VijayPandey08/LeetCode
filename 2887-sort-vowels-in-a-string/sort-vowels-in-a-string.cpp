class Solution {
public:
    string sortVowels(string s) {
        string ans = s;
        vector<char> v;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                v.push_back(s[i]);
            }
        }
        sort(v.begin(),v.end());
        int j=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                ans[i]=v[j];
                j++;
            }
        }
        return ans;
    }
};