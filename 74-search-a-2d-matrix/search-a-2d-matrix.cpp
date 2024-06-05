class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==1 && matrix[0].size()==1 && target==matrix[0][0]) return true;
        bool found = false;
        if(target<matrix[0][0]) return false;
        int row = 0;

        for(int i=0; i<matrix.size(); i++){
            if(target<=matrix[i][matrix[0].size()-1]){
                row = i;
                break;
            }
        }
cout<<row<<endl;
        int s =0;
        int e =matrix[0].size() -1;

        while(s<=e){
             int mid = s + (e-s)/2;
             if(target==matrix[row][mid]){
                return true;
             }
             else if(target<matrix[row][mid]){
                e= mid-1;
             }
             else{
                s=mid+1;
             }
        }
        return found;
    }
};