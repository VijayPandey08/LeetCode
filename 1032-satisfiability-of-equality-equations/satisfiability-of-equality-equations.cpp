class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i], parent);
    }
    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);
        if (x_parent == y_parent)
            return;
        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }
        else if (rank[y_parent] > rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int V = equations.size();
        vector<int> parent(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        vector<int> rank(26, 0);
        for (auto i : equations) {
            if (i[1] == '=') {
                Union(i[0] - 'a', i[3] - 'a', parent, rank);
            }
        }
        for (string& i : equations) {
            if (i[1] == '!') {
                if (find(i[0] - 'a', parent) == find(i[3] - 'a', parent))
                    return false;
            }
        }
        return true;
    }
};