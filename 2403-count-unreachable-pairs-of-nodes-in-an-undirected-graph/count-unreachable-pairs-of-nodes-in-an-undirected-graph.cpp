class Solution {
public:
vector<int> parent;
vector<int> rank;
int find(int i){
    if(parent[i]==i) return i;
    return parent[i]=find(parent[i]);
}
void Union(int x, int y){
    int x_parent = find(x);
    int y_parent = find(y);
    if(x_parent == y_parent) return;
    if(rank[x_parent]>rank[y_parent]){
        parent[y_parent]=x_parent;
    }
    else if(rank[y_parent]>rank[x_parent]){
        parent[x_parent]=y_parent;
    }
    else{
        parent[y_parent]=x_parent;
        rank[x_parent]++;
    }
}

    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans=0;
        long long remaining=0;
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        map<int,int> m;
        for(auto v:edges){
            Union(v[0],v[1]);
        }
        for(int i=0; i<n; i++){
            int x = find(parent[i]);
            m[x]++;
            cout<<parent[i]<<endl;
        }
        for(auto i:m){
            ans+=1ll*i.second*(n-i.second);
        }

        return ans/2;

    }
};