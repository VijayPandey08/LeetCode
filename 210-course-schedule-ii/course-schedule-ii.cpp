class Solution {
public:
bool has_cycle;
void dfs(unordered_map<int,vector<int>> &adj, int i,vector<bool> &visited,vector<bool> &in_recursion, stack<int> &s ){
    visited[i]=true;
    in_recursion[i]=true;
    for(auto v:adj[i]){
        if(in_recursion[v]==true){
            has_cycle=true;
            return;
        }
        if(!visited[v]){
            dfs(adj,v,visited,in_recursion,s);
        }
    }
    in_recursion[i]=false;
    s.push(i);

}
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        // chalo bhaisahab isko solve krna h dfs se, 
        // pehle check krenge cycle toh nhi h, agar cycle h toh baat khtm khali vector return krwaenge
        // vrna topological order de denge

        unordered_map<int,vector<int>> adj;
        vector<bool> visited(numCourses,false);
        vector<bool> in_recursion(numCourses,false);
        stack<int> s;


        // making graph
        for(auto i: pre){
            int a = i[0];
            int b = i[1];
            // b------->a
            adj[b].push_back(a);
        }

        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                dfs(adj,i,visited,in_recursion,s);
            }
        }
        if(has_cycle){
            return {};
        }
vector<int> result;
        while(!s.empty()){
              result.push_back(s.top());
              s.pop();
        }
        return result;
    }
};