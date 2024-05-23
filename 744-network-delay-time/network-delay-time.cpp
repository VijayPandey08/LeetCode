class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj; // ek graph khud se banaenge, weight bhi rakhna h isliye har integer ke samne vector lia h pair<int,int> ka..
        for(auto vec:times){
            int u =vec[0];
            int v =vec[1];
            int w =vec[2];
            adj[u].push_back({v,w});
            // adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});

        vector<int> result(n+1,INT_MAX);
        result[k]=0;

        vector<int> parent(n+1);
        for(int i=1; i<=n; i++){
            parent[i]=i;
        }

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto v:adj[node]){
                int adjnode = v.first;
                int wt = v.second;
                if(dis + wt<result[adjnode]){
                    result[adjnode] = dis +wt;
                    pq.push({dis+wt,adjnode});
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1; i<=n; i++){
            ans = max(ans,result[i]);
        }
        for(auto i:result){
            cout<<i<<" ";
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};