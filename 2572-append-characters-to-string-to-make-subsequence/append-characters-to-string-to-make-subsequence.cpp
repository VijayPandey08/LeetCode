class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;
        int n = t.size();
        while(i<s.size() && j<t.size()){
            if(t[j]==s[i]){
                j++;
                i++;
                n--;
            cout<<n<<" ";
            }
            else if(t[j]!=s[i]){
                i++;
            }
        }
        return n;
    }
};