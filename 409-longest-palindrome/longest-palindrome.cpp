class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(auto i:s){
            m[i]++;
        }
        int count=0;
        for(auto i: m){
            if(i.second>1  ){
                 count+=i.second/2;
            }
        }
        cout<<count;
        if(2*count == s.length()) return 2*count;
        if(2*count<s.length()) return 2*count + 1;
        return 2*count;
        // return count;
    }
};