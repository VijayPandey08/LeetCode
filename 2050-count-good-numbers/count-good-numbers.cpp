class Solution {
public:
int MOD;
    long long modPow(long long base, long long exp) {
        long long result = 1;
        while (exp > 0) {
            if (exp & 1)
                result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    };
    int countGoodNumbers(long long n) {
        MOD = 1e9 + 7;

        long long even = (n + 1) / 2; // Number of even positions
        long long odd = n / 2;        // Number of odd positions

        return (modPow(5, even) * modPow(4, odd)) % MOD;
    }
};