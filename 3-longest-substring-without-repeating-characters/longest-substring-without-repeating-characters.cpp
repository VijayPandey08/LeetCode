#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        if (s.length() == 1) return 1;

        int maxi = 0;
        int left = 0;  // Start of the current window
        unordered_map<char, int> m;  // Stores the last index of each character

        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];

            // If character is already in the map, move the left pointer to the right of the same character last found
            if (m.find(c) != m.end()) {
                left = max(left, m[c] + 1);
            }

            // Update the last index of the character
            m[c] = right;

            // Update the maximum length
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};
