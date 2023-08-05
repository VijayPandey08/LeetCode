class Solution {
public:
    int countDigits(int num) {
        int ans=0;
        vector<int> v;
        int n=0;
        int temp=num;
        while(num>0){
             n=num%10;
             v.push_back(n);
             num=num/10;
        }
        for(auto i:v){
            if(temp%i==0){
                ans++;
            }
        }
        return ans;
    }
};