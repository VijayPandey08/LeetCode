class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // ---- brute force approach //-----
        // int n = arr.size();
        // int pairs = 0;
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         int a = 0;
        //         for (int k = i; k < j; k++) {
        //             a ^= arr[k];
        //         }

        //         int b = 0;

        //         for (int k = j; k < n; k++) {
        //             b ^= arr[k];
        //             if (a == b) {
        //                 pairs++;
        //             }
        //         }
        //     }
        // }
        // return pairs;

        //--- ab bdiya optimised approach dekhte h
        //--- isme use krenge XOR ki bdiya property,
        //--- key points used:  prefix xor,  similar to equal subarray sum

        int n = arr.size();
        vector<int> pre(n + 1, 0); // prefix XOR array
        int count = 0;

        // Compute the prefix XOR array
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] ^ arr[i];
        }

        // Iterate over all pairs (i, k)
        for (int i = 0; i < n; ++i) {
            for (int k = i + 1; k <= n; ++k) {
                if (pre[i] == pre[k]) {
                    count += k - i - 1;
                }
            }
        }
        
        return count;


    
    }
};