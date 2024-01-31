class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        // s.push(-1);
        vector<int> temp;
        map<int,int> m;
        vector<int> ans;
        temp=nums2;
        vector<int> v(nums2.size());
        reverse(temp.begin(),temp.end());
        for(int i=0; i<temp.size(); i++){
            // v.push_back(s.top());

            while(!s.empty() &&  temp[i]>s.top()){
              s.pop();     
        }
                    if(s.empty()){
                v.push_back(-1);
                m[temp[i]]=-1;
            }
        else{

        v.push_back(s.top());
        m[temp[i]]=s.top();
        }
        s.push(temp[i]);


        }
        for(auto i:nums1){
            ans.push_back(m[i]);
        }
return ans;

    }
};