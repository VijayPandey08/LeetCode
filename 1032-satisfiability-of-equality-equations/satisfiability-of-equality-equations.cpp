class Solution {
public:
vector<int> parent;
vector<int> rank;
int find(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=find(parent[x]);
}

void Union(int x, int y){
    int x_parent = find(x);
    int y_parent = find(y);
    if(rank[x_parent]<rank[y_parent]){
        parent[x_parent]=y_parent;
    }
    else if(rank[y_parent]<rank[x_parent]){
parent[y_parent]=x_parent;
    }
    else{
        parent[y_parent]=x_parent;
        rank[x_parent]++;
    }
}
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26,0);
        for(int i=0; i<26; i++){
            parent[i]=i;
        }
        rank.resize(26,0);

        for(auto i:equations){
            if(i[1]== '='){
                Union(i[0]-'a', i[3]-'a');
            }
        }
        for(auto i:equations){
            if(i[1]== '!'){
                int x = find(i[0]-'a');
                int y = find(i[3]-'a');
                if(x==y) return false;
            }
        }
        return true;

    }
};