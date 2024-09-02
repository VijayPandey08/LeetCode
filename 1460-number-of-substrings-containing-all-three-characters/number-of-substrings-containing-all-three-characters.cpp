class Solution {
public:
    int numberOfSubstrings(string s) {

        int left = 0;
        int right = 0;

        int f1 = 0;
        int f2 = 0;
        int f3 = 0;

        int total = 0;

        while (right < s.length()) {
            if (s[right] == 'a') {
                f1++;
                right++;
            } else if (s[right] == 'b') {
                f2++;
                right++;
            } else {
                f3++;
                right++;
            }

            while (f1 > 0 && f2 > 0 && f3 > 0) {

                total+=s.length()-right + 1; // main logic

                if (s[left] == 'a') {
                    f1--;
                } else if (s[left] == 'b') {
                    f2--;
                } else {
                    f3--;
                }
                left++;
            }

        
        }
        return total;
    }
};
