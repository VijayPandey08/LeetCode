class Solution {
public:
    int largestAltitude(vector<int>& gain) {
     int ans=0;

     int n = gain.size()+1;
     vector<int> alt;
     alt.push_back(0);
     alt.push_back(gain[0]);

     for(int i=2; i<n; i++){
         alt.push_back(alt[i-1]+gain[i-1]);
     }   
     for(int i=0; i<n; i++){
         cout<<alt[i]<<endl;
     }   
     int maxi=INT_MIN;
     for(int i=0; i<n; i++){
         maxi=max(maxi,alt[i]);
     }

     return maxi;
    }
};