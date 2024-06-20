class Solution {
public:

bool isPossible(int mid_force, vector<int> &position, int m){
    int prev = position[0];
    int count=1;

    for(int i=1; i<position.size(); i++){
        int curr = position[i];

          if(curr-prev>=mid_force){
            count++;
            prev=curr;
          }

          if(count==m) break;
    }

    return count==m;


}


    int maxDistance(vector<int>& position, int m) {
        int result=0;
        int n = position.size();
        sort(position.begin(),position.end());

        int min_force = 1;
        int max_force = position[n-1] - position[0];

        while(min_force<=max_force){
            int mid_force = min_force + (max_force - min_force)/2;

            if(isPossible(mid_force, position, m)){
                result = mid_force;
                min_force=mid_force+1;
            }
            else{
                max_force = mid_force-1;
            }
        }

        return result;
    }
};