class Solution {
public:
// / this is calssical implementation of prims algorithm...... /////


    int prims_algo(vector<vector<pair<int,int>>> &adj, int V) {
        // Priority queue to store the minimum weight edge at top
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // Start with node 0 (with 0 distance)
        pq.push({0, 0});
        // To track nodes included in MST
        vector<bool> inMst(V, false);
        int sum = 0;

        while(!pq.empty()) {
            // Get the node with the smallest distance
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // If the node is already included in MST, continue
            if(inMst[node]) continue;
            // Include the node in MST and add its distance to the sum
            inMst[node] = true;
            sum += dis;

            // For all adjacent nodes, push them to the priority queue if not already in MST
            for(auto v : adj[node]) {
                int adj_node = v.first;
                int adj_dis = v.second;
                if(!inMst[adj_node]) {
                    pq.push({adj_dis, adj_node});
                }
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        vector<vector<pair<int,int>>> adj(V);

        // Construct the adjacency list
        for(int i = 0; i < points.size(); i++) {
            for(int j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];

                int d = abs(x1 - x2) + abs(y1 - y2);

                adj[i].push_back({j, d});
                adj[j].push_back({i, d});
            }
        }

        // Run Prim's algorithm to get the minimum spanning tree cost
        return prims_algo(adj, V);

    }
};