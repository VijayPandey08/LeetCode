class Solution {
public:
    int countTriplets(vector<int>& arr) {
        // ---- brute force approach //-----
        int n = arr.size();
        int pairs = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = 0;
                for (int k = i; k < j; k++) {
                    a ^= arr[k];
                }

                int b = 0;

                for (int k = j; k < n; k++) {
                    b ^= arr[k];
                    if (a == b) {
                        pairs++;
                    }
                }
            }
        }
        return pairs;
    }
};