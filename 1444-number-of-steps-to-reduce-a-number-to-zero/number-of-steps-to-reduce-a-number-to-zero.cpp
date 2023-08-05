class Solution {
public:
    int numberOfSteps(int num) {
        int ans=0;
        while(num>1){
            if(num%2==0){
                num=num/2;
                ans++;
            }
            if(num%2!=0){
                num=num-1;
                ans++;
            }
        }
        return ans;
    }
};