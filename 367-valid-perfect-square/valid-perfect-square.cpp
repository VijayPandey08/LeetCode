class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int s=0;
        int e=num;
        while(s<=e){
            long long mid = e - ((e-s)/2);
            if((mid*mid)==num){
                return true;
        
            }
            else if((mid*mid)<num){
                s=mid+1;
                
            }
            else{
                e=mid-1;
                
            }
        }
        return false;
    }
};