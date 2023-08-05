class Solution {
public:
    int minimumSum(int num) {
        vector<int> v;
        int n=0;
    
        for(int i=0; i<4; i++){
            n=num%10;
            v.push_back(n);
            num=num/10;
        }
        sort(v.begin(),v.end());

        int n1 = (v[3] + (10*v[0]));
        int n2 = (v[2] + (10*v[1]));
        cout<<n1<<" "<<n2;

        return (n1+n2);
    }
};