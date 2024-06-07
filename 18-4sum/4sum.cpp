class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 4 loop laga ke bhi kr skte ho
        // pr bdiya approach rhegi two pointer

        if(nums.size()<4) return {};

        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < nums.size() - 2; j++) {

                if (j-1>=0 && j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int k = j + 1;
                int l = nums.size() - 1;

                while (k < l) {
                    long long sum = nums[i] + nums[j];
                    sum+= nums[k];
                    sum+= nums[l];

                    if (sum < target) {
                        k++;
                    } else if (sum > target) {
                        l--;
                    } else {
                        vector<int> temp({nums[i], nums[j], nums[k], nums[l]});

                        result.push_back(temp);
                        k++;
                        l--;
                        while (k-1>=0 && k < l && nums[k] == nums[k - 1])
                            k++;
                        while (l+1<nums.size() && k < l && nums[l] == nums[l + 1])
                            l--;

                    }
                }
            }
        }
        return result;
    }
};