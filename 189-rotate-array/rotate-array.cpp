class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        int n=nums.size();
        for(int i=0; i<nums.size(); i++){
            temp[(i+k)%nums.size()]=nums[i]; // like a logic u should remember this
        }
    //     int j=0;
    //     for(int i=n-k%n;i<n;i++){
    //        temp[j]= nums[i];
    //         j++;
    //     }
    //     for(int i=0;i<n-k%n;i++){
    //         temp[j]=nums[i];
    //         j++;
    //     }
    //    for(int i=0;i<n;i++){
    //        nums[i]=temp[i];
    //    }
    nums=temp;
    }
};