class Solution {
public:
    bool isPalindrome(string s) {
        string temp1="";
        string temp2="";
        string temp="";
        for(int i=0; i<s.length(); i++){
            if(s[i]>=97 && s[i]<=122){
                temp1.push_back(s[i]);
            }
            if(s[i]>=48 && s[i]<=57){
                temp1.push_back(s[i]);
            }
             if(s[i]>=65  && s[i]<=90  ){
                temp1.push_back(s[i]+32);
            }
        
        }
        // cout<<temp1<<endl;
        // for(int i=0; i<temp1.size(); i++){
        //     temp2[i]=temp1[i];
        // }
        temp2=temp1;
        // cout<<temp2<<endl;

        reverse(temp1.begin(),temp1.end());
        cout<<temp1<<endl;
        if(temp1==temp2){
         return true;
        }
            
    return false;
    }
};