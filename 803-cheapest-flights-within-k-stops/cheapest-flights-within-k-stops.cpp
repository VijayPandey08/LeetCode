class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        

        // ⚡⚡ mai price ko distance bolunga to 
        // \U0001f972 thoda dekh lena

        // ye graph ke liye
        // adj list bna rha 
        vector<pair<int,int>> adj[n]; 
        
        // simple esme node and distance ko push kr rha
        for(auto &it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        // distance array 
        // bole to price ki array
        vector<int> dis(n); 
        for(int i=0;i<n;i++){
            dis[i]=1e9;
        }

        // dekho source pe rehne ki distake to zero hogi
        // yani paisa zero
        // yani tum jnha ho, vha pe jane ka cost to zero hoga n
        dis[src]=0; 
        queue<pair<int,pair<int,int>>> pq;

        // ek doubt aa skta tha...
        // ki ham PQ se kyu n gye
        // dekho pq me main attr
        // distance ko rakhte to
        // ek game hota, minimum distance uper aata
        // but hme to minimum  number of stops
        // ki need thi n
        // esiliye nhi kiya
        // ab ye sochoge ki abhi bhai kyu n mai
        // key attr stops ko hi bna du..
        // lekin socho kya fayda 
        // uska matlab to har level wale hi uper honge
        // jo ki queue bhi kar dega 

        // agr tumhare dimak me koi aur reason aa rha hai to
        // jarur comment karna ❤️❤️ ? 


        // ab game suru kar rhe
        pq.push({src,{0,0}}); 

        while(!pq.empty()){

            // ye to pta hi hoga
            // simple step hai
            int node=pq.front().first; 
            int step=pq.front().second.first;
            int d=pq.front().second.second;
            pq.pop();

            for(auto &it:adj[node]){
                int newnode=it.first;
                int newd=it.second; 

                // main ye samjhna hai
                // dekho que me 
                // 2 condition hai
                // minimum cost and atmost k flight 
                // baat samjhe ... 
                // esiliye 
                // do chij check krenge
                // arey dis pichchale se kam hai n
                // aur aur flight to k se kam lag rhi hai n
                if((newd+d<dis[newnode]) && step<=k){
                    dis[newnode]=newd+d;
                    pq.push({newnode,{step+1,newd+d}});
                }
            }
        }

        // ye case hai, jab visit hi nhi huaa
        // dst
        if(dis[dst]==1e9){
            return -1;
        }
        
        // esme ans store huaa hoga....
        return dis[dst];

    }
};