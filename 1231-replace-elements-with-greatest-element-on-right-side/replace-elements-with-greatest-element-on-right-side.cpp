class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans;
        ans.push_back(-1);
    
        for(int i=arr.size()-1; i>0; i--){
            ans.push_back(max(ans.back(),arr[i]));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


    // cout<<ans.back();
        // for(int i=0; i<arr.size()-1;i++){
        // int maxi=INT_MIN;
        //     for(int j=i+1; j<arr.size(); j++){
        //        int temp=arr[j];
        //        maxi=max(maxi,temp);
        //     }
        //     ans.push_back(maxi);
        // }
        // ans.push_back(-1);