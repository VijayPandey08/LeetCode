class Solution {
public:
void print(stack<char> st){
     while(st.size()>0){
     char c=st.top();
     st.pop();
     cout<<c<<" ";
     }
     cout<<endl;


}
    string removeStars(string s) {
       string ans="";
       stack<char> st;
       for(int i=0; i<s.length(); i++){
           if( s[i]=='*'){
               st.pop();
           }
           else{
               st.push(s[i]);
           }
        //    print(st);
       }  
       int n=st.size();
       for(int i=0; i<n; i++){
           char c=st.top();
           st.pop();
           ans.push_back(c);
       }
       reverse(ans.begin(),ans.end());

   
       return ans;
    }
};