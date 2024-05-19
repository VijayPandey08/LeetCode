class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> adj;
        int count=0;
        vector<int> result;
        vector<int> indegree(numCourses,0);
        queue<int> q;
        vector<int> v;

        // making required graph
        for(auto i:pre){
            int a = i[0];
            int b = i[1];
            // b------->a
            adj[b].push_back(a);
            indegree[a]++;
        }

        for(int i=0; i<indegree.size(); i++){
            if(indegree[i]==0){
               q.push(i);
            }
        }

        while(!q.empty()){
            int u = q.front();
            count++;
            result.push_back(u);
            q.pop();
            for(auto v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        if(count==numCourses) return result;
        return v;

    }
};