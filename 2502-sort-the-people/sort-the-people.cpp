class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<int> copy = heights;
        sort(copy.rbegin(),copy.rend());

        for(int i=0; i<copy.size(); i++){
            for(int j=0; j<heights.size(); j++){
                if(copy[i]==heights[j]){
                  ans.push_back(names[j]);
                }
            }
        }

        return ans;
    }
};