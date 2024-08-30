class Solution {
public:
    int characterReplacement(string A, int k) {
        int maxi = INT_MIN;

        for (char c = 'A'; c <= 'Z'; c++) {

            int s = 0;
            int e = 0;

            int count = k;

            while (e < A.length()) {
                if (A[e] == c) {
                    e++;
                } else {
                    count--;
                    e++;
                }
                while (count < 0) {
                    if (A[s] != c) {
                        count++;
                        s++;
                    } else {
                        s++;
                    }
                }

                maxi = max(maxi, e - s );
            }
        }

        return maxi;
    }
};