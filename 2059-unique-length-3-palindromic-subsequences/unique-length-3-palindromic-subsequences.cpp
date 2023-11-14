class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans=0;
        unordered_map<char,int> m1;

        for(int i=0; i<s.length(); i++){
            m1[s[i]]++;
        }
        for(auto i:m1){
            if(i.second>1){
                int l=0;
                int j=s.length()-1;
                unordered_map<char,int> m2;
                while(l<j){
                    if(s[l]!=i.first){
                        l++;
                    }
                    if(s[j]!=i.first){
                        j--;
                    }
                    if(s[l]==i.first && s[j]==i.first){
                        for(int k=l+1; k<j; k++ ){
                        m2[s[k]]++;
                        }
                        ans+=m2.size();
                        break;
        
                    }
                }
            }
        }


        return ans;
    }
};