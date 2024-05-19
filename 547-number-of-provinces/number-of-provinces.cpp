class Solution {
public:
int n;

void dfs(unordered_map<int,vector<int>> &adj, int i, vector<bool> &visited){
    visited[i]=true;
    for(auto v:adj[i]){
        if(!visited[v]){
            dfs(adj,v,visited);
        }
    }
}

void bfs(unordered_map<int,vector<int>> &adj, int i, vector<bool> &visited){
    visited[i]=true;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int u =q.front();
        q.pop();
        for(auto v:adj[u]){
            if(!visited[v]){
                bfs(adj,v,visited);
            }
        }
    }
}
void bfs_1(vector<vector<int>>& isConnected, int i, vector<bool> &visited){
    visited[i]=true;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int u =q.front();
        q.pop();
        for(int v=0; v<n; v++){
            if(!visited[v] && isConnected[i][v]==1){
                bfs_1(isConnected,v,visited);
            }
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
         n=isConnected.size();
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
                // dfs(adj,i,visited);
                // bfs(adj,i,visited);
                bfs_1(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
};