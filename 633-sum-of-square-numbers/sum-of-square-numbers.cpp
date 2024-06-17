class Solution {
public:
    bool judgeSquareSum(int c) {
        // good implementation of two pointer
        long long a = 0;
        long long b = sqrt(c);
        // if we take the most extreme case then c would be a perfect square and
        // then a would be 0 in that case and b would be its sqaure root so in
        // conclusion we can say that a and b should be between 0 and the sqare
        // root of c

        // normal binary search type approach
        while (a <= b) {
            long long k = (a * a) + (b * b);
            if (k < c) {
                a++;
            } else if (k > c) {
                b--;
            } else {
                return true;
            }
        }

        return false;
    }
};