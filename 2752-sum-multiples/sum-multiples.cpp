class Solution {
public:
    int sumOfMultiples(int n) {

        int sum=0;
        vector<int> v;

        for(int i=1; i<=n; i++){
            if(i%3==0 || i%5==0 || i%7==0 ){
                  v.push_back(i);
            }
    
        }

          for(auto i:v){
            cout<<i<<" ";
        }
        for(auto i:v){
            sum+=i;
        }
        return sum;
    }
};