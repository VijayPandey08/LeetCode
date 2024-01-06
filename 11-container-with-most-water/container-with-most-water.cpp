class Solution {
public:
    int maxArea(vector<int>& h) {
        int ans=0;
        int maxi=INT_MIN;
        int s=0;
        int e=h.size()-1;
        while(s<e){
             int water=(e-s)*(min(h[s],h[e]));
             maxi=max(maxi,water);
             if(h[s]<h[e]){
                 s++;
             }
             else{
                 e--;
             }
        }
        return maxi;
        // jai bajrangbali
    }
};