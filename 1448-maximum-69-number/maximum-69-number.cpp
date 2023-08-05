class Solution {
public:
    int maximum69Number (int num) {
        int ans=0;
        vector<int> v;
        while(num>0){
            int temp = num%10;
            v.push_back(temp);
            num=num/10;
        }
        reverse(v.begin(),v.end());

        for(int i=0; i<v.size(); i++){
            if(v[i]==6){
                v[i]=9;
                break;
            }
        }
        ans = v[0];
        for(int i=1; i<v.size(); i++){
            ans=(ans*10)+v[i];
        }
        return ans;
    }
};