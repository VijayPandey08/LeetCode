class Solution {
public:
bool check_bfs(vector<vector<int>>& adj, int curr_node, vector<int> &color, int curr_color){
    queue<int> q;
    q.push(curr_node);
    color[curr_node]=curr_color;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto v:adj[node]){
            if(color[v]==color[node]) return false;
            else if(color[v]==-1){
                color[v]=1-color[node];
                q.push(v);
            }
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V,-1);

        for(int i=0; i<V; i++){
            if(color[i]==-1){
                if(check_bfs(adj,i,color,1)==false){
                    return false;
                }
            }
        }
return true;
        
    }
};