class Solution {
public:
    int findTheWinner(int n, int k) {
        // there are mainly three approaches to solve this question

        //--------approach 1 ------------//
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            v.push_back(i);
        }
        int index = 0;
        while (v.size() > 1) {
            index = index + k - 1;
            index = (index % v.size());
            v.erase(v.begin() + index);
        }

        return v[0];
    }
};