class Solution {
public:

void dfs(unordered_map<int,vector<int>> &adj, int i, vector<bool> &visited){
    visited[i]=true;
    for(auto v:adj[i]){
        if(!visited[v]){
            dfs(adj,v,visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        // let us first make a graph 
        unordered_map<int,vector<int>> adj;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;  //for storing ans
        vector<bool> visited(n,false);
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(adj,i,visited);
                count++;
            }
        }
        return count;
    }
};