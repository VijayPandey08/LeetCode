class Solution {
public:
    void dfs(vector<vector<int>>& adj , int i, vector<bool> &visited) {
        if(visited[i]){
            return;
        }
        visited[i]=true;
        for(auto v: adj[i]){
            dfs(adj,v,visited);
        }
    }
    int findCircleNum(vector<vector<int>>& is) {
        int m = is.size();
        int n = is[0].size();
        int count = 0;
        vector<vector<int>> adj(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (is[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
      vector<bool> visited(m,false);
      for(int i=0; i<m; i++){
        if(visited[i]==false){
            dfs(adj, i , visited);
            count++;
        }
      }

        // for(auto i:is){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return count;
    }
};