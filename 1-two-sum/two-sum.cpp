class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    vector<int> num=nums;
    int s = 0;
    int  e = nums.size() - 1;
    int a=INT_MIN;
    int b=INT_MIN;

    sort(nums.begin(),nums.end());

    while(s<e){
        if(nums[s]+nums[e]<target){
            s++;
        }
        else if(nums[s]+nums[e]>target){
            e--;
        }
    
        else {
            a=nums[s];
            b=nums[e];
            break;
        }
    }

    // if(a== INT_MIN && b==INT_MIN){
    //     return ans;
    // }

    for(int i=0; i<num.size(); i++){
        if(num[i]==a){
            ans.push_back(i);
            break;
        }
    }

    for(int i=num.size()-1 ; i>=0; i--){
        if(num[i]==b){
            ans.push_back(i);
            break;
        }
    }


    return ans;
    }
};