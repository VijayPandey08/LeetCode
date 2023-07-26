class Solution {
public:
    bool isHappy(int n) {
      int count =0;
      while(n>9){
          int ans = 0;
         while(n>0){
             int dig = n%10;
             ans += (dig*dig);
             n = n/10;
         }
         n =ans;
      }  
      if(n==1|| n==7) return true;
      return false;
    }
};