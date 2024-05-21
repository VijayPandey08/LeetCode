class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent == y_parent)
            return;
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    void dfs(int u, vector<int> &visited,unordered_map<int, vector<int>> &adj){
        visited[u]=true;
        // s.insert[u];
        for(auto v:adj[u]){
            if(!visited[v]){
                dfs(v,visited,adj);
            }
        }

    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // ek baar dfs ho jaae bdiya bdiya;
        unordered_map<int, vector<int>> adj;
        
        for(int i=0; i<connections.size(); i++){
                 int a = connections[i][0];
                 int b = connections[i][1];
                 adj[b].push_back(a);
                 adj[a].push_back(b);
        }
        int m = connections.size();
        if(connections.size()<n-1) return -1;
        vector<int> visited(n,false);
        set<int> s;
        int count=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i,visited,adj);
            }
        }
        return count-1;




                // if(connections.size()<n-1) return -1;
        // parent.resize(n, 0);
        // for (int i = 0; i < n; i++) {
        //     parent[i] = i;
        // }
        // rank.resize(n, 0);
        //     for(auto v:connections){
        //         if(parent[v[0]]!=parent[v[1]]){
        //             Union(v[0],v[1]);
        //             n--;
        //         }
        //     }
        //     return n-1;
    }
};