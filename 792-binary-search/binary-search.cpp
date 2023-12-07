class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans=-1;
        sort(nums.begin(),nums.end());
        int s=0;
        int e=nums.size()-1;
        int mid = s+((e-s)/2);
        while(s<=e){
            if(nums[mid]==target){
                ans = mid;
                break;
            }
            else if(nums[mid]>target){
                e--;
                mid = s+((e-s)/2);
                
            }
            else if(nums[mid]<target){
                s++;
                mid = s+((e-s)/2);
            }
        }
        return ans;
    }
};