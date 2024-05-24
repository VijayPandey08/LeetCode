class Solution {
public:
int n,m;
typedef pair<int,pair<int,int>> P;
vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
bool isSafe(int x_, int y_){
    return (x_>=0 && y_>=0 && x_<n && y_<m); 
}
// yeh isliye banaya q ki, hume priority_queue mein {distance, {cell ke coordinates store krne h}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // yeh h second approach the great dijkstras..

        n = grid.size();
        m = grid[0].size();
        // baar baar n,m ka istemal pdega, bs n aur m mein confuse nahi hone ka

        if(n==0 || m==0 || grid[0][0]!=0) return -1; // basic check for formality
        // hume banana h priority_queue aur reult vector
        vector<vector<int>> result(n,vector<int>(m,INT_MAX));
        result[0][0]=0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int d = pq.top().first;
            pair<int,int> node = pq.top().second;
            int node_x = node.first;
            int node_y = node.second;
            pq.pop();
            
            for(auto dir:directions){
               int x_ = node_x + dir[0];
               int y_ = node_y + dir[1];
               int dis = 1;

               if(isSafe(x_,y_) && grid[x_][y_]==0 && d + dis < result[x_][y_] ){
                pq.push({d+dis,{x_,y_}});
                result[x_][y_] = d +dis;
                grid[x_][y_] = 1;
               }
            }
            

        }
        if(result[n-1][m-1]==INT_MAX) return -1;
        return result[n-1][m-1] +1;
        


    }
};