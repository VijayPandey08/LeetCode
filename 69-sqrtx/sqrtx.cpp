class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0; 
        int s =1;
        int e =x;

        int ans=0;
       
        while(s<=e){
           long long mid = s + (e-s)/2;

           if((mid*mid)==x){
                return mid;
           }
           else if((mid*mid)<x){
            s=mid+1;
            ans=mid;
           }
           else{
            e=mid-1;
           }
        }
        return ans;
    }
};