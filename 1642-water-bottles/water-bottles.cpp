class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = numBottles;
        int n = numBottles;
        int m = numExchange;
        while((n/m)!=0){
             int rem = n/m;
             int left = n%m;
             count+=rem;
             n=rem+left;
        }

    
        return count;
    }
};