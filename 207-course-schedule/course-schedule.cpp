class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        int count=0;

        // making graph
        for (auto i : pre) {
            int a = i[0];
            int b = i[1];
            //   b------->a
            adj[b].push_back(a);
            indegree[a]++;
        }

        // for (int u = 0; u < numCourses; u++) {
        //     for (auto v : adj[u]) {
        //         indegree[v]++;
        //     }
        // }

        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            count++;
            q.pop();
            for (auto v : adj[node]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (count == numCourses)
            return true;
        return false;
    }
};