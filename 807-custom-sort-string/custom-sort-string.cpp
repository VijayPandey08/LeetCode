class Solution {
public:
    string customSortString(string order, string s) {
       string temp;
       string ans;
    //    reverse(s.begin(),s.end());
       for(int i=0; i<order.length(); i++){
           for(int j=0; j<s.length(); j++){
               if(order[i]==s[j]){
                   ans.push_back(s[j]);
                   s[j]='$';
               }
           }
       } 
       cout<<s<<endl;
       
       
           for(int i=0; i<s.length(); i++){
               if(s[i]!='$'){
                   ans.push_back(s[i]);
               }
           }
           return ans;
       
       
    }
};