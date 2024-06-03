class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        //---------------- important as fuck ------------------//
        // keep note of this shit...
        // merging intervals...

        sort(intervals.begin(),intervals.end()); // sort first, cause u need to merge in ascending order

        vector<vector<int>> result; // result

        vector<int> current; //initial conditions
        current = intervals[0];

// current se compare krte hue chalenge, jha pr merge nhi ho paya, uss interval ko result mein store krke, next element ko current maan lenge
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

        // ek interval last mein chut hi jaaega, toh usko alg se handle krenge
        result.push_back(current);
        return result;
    }
};