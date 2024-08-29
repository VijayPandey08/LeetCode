class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;  // isme store hoga obviously

// -------- pehle index ko alg se handle kr rhe h -------------//
        for (int i = 1; i < target[0]; i++) {
            ans.push_back("Push");
            ans.push_back("Pop");
        }
        ans.push_back("Push");


// ---------- baki cases ke lie for loop --------------------//

        for (int i = 1; i < target.size(); i++) {
            if (target[i] - target[i - 1] == 1) {
                ans.push_back("Push");
            } else {
                for (int j = 0; j < target[i] - target[i - 1] - 1; j++) {
                    ans.push_back("Push");
                    ans.push_back("Pop");
                }
                ans.push_back("Push");
            }
        }
        return ans;
    }
};