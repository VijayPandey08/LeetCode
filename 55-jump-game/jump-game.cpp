class Solution
{
    public:
        bool canJump(vector<int> &nums)
        {
         int n =nums.size();
         vector<int> v;
        
        if(n==1) return true;
        
         for(int i=n-2; i>=0; i--){
             if(nums[i]==0){
                 v.push_back(i);
             }
             else{
                 while(v.size()>0 && v.back()<nums[i]+i){
                     v.pop_back();
                 }
             }
         }
        if(v.size()>0) return false;
        return true;

    


        }
};