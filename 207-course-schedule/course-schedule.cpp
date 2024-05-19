class Solution {
public:
bool dfs(unordered_map<int,vector<int>> &adj, int i, vector<bool> &visited, vector<bool> &in_recursion){
    visited[i]=true;
    in_recursion[i]=true;
    for(auto v:adj[i]){
        if(!visited[v] && dfs(adj,v,visited,in_recursion)){
            return true;
        }
        else if(in_recursion[v]==true) return true;
    }
    in_recursion[i]=false;
    return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        //------------DFS--------------
        unordered_map<int,vector<int>> adj;
        vector<bool> visited(numCourses,false);
        vector<bool> in_recursion(numCourses,false);

        // making graph....
        for(auto i:pre){
            int a =i[0];
            int b =i[1];
            // b-------->a
            adj[b].push_back(a);
        }

        for(int i=0; i<numCourses; i++){
            if(!visited[i] &&  dfs(adj,i,visited,in_recursion)){
                return false;
            }
        }
        return true;

    }
};