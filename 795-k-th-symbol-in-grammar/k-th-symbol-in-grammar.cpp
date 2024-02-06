class Solution {
public:
// reccurssive approach....
    int solve(int n,int k){
        if(n==1 && k==1){    // base case jab ek hi row hogi aur uska pehla element chahiye hoga : (1st row ka 1st element is 0)
            return 0; // 1st row ka 1st element is zero
        }

        int length=pow(2,n-1); // kisi bhi row mein 2 ki power n-1 elements hi h.
        int mid = length/2; // har 'nth' row mein mid tak ke elements same h 'n-1' row ke..
        if(k<=mid){   // yeh cheez observation se hi smjh aaaegi
            return solve(n-1,k); // har 'nth' row mein mid tak ke elements same h 'n-1' row ke..
        }
        else{

        return !solve(n-1,k-mid); // aut mid ke aaage ke elements nikalne k lie k-mid element ka compliment lena pdega
        }
    }
    int kthGrammar(int n, int k) {
         return solve(n,k);

    }
};