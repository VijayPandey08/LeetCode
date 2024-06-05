class Solution {
public:
    int mySqrt(int x) {
        int s=0;
        int e=x;
        int ans=0;
    
//---------very standard but imp thing to note my friend-----------
        while(s<=e){
        long long mid = e-((e-s)/2);
            if((mid*mid)==x){
                return mid;   // agar perfect square mile toh vhi return kr jaao
            }
            else if((mid*mid)<x){
                s=mid+1;
                ans = mid;  /// agar perfect square na ho toh uske neeche vala rkh lo apne pas

            }
            else {
                e=mid-1;
            }
        }
        return ans;
    }
};