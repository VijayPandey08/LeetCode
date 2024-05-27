class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int i) {
        if (parent[i] == i)
            return i;

        return parent[i] = find(parent[i]);
    }

    void Union(int u, int v) {
        int parent_u = find(u);
        int parent_v = find(v);
        if (rank[parent_u] > rank[parent_v]) {
            parent[parent_v] = parent_u;
        } else if (rank[parent_v] > rank[parent_u]) {
            parent[parent_u] = parent_v;
        } else {
            parent[parent_u] = parent_v;
            rank[parent_v]++;
        }
    }
    int kruskal(vector<vector<int>>& vec, int V) {
        parent.resize(V, 0);
        rank.resize(V, 0);

        for (int i = 0; i < V; i++) {
            parent[i] = i;
        }

        int sum = 0;

        
            for (auto vp : vec) {
                int u = vp[0];
                int v = vp[1];
                int w = vp[2];

                int parent_u = find(u);
                int parent_v = find(v);

                if (parent_u != parent_v) {
                    Union(u, v);
                    sum += w;
                }
            }
        
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> vec;
        int V = points.size();

        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int w = abs(x1 - x2) + abs(y1 - y2);

                vec.push_back({i, j, w});
            }
        }
        auto comprator = [](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];
        };
        sort(vec.begin(), vec.end(), comprator);
        return kruskal(vec, V);
    }
};