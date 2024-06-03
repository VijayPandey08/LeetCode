class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        vector<int> current;
        current = intervals[0];
        for(auto i:current){
            cout<<i<< " ";
        }


        for(int i=1; i<intervals.size(); i++){
            if(current[1]>=intervals[i][0]){
                current[0] = min({current[0],intervals[i][0]});
                current[1] = max({current[1],intervals[i][1]});
            }
            else{
                result.push_back(current);
                current = intervals[i];
            }
        }
        result.push_back(current);
        return result;
    }
};