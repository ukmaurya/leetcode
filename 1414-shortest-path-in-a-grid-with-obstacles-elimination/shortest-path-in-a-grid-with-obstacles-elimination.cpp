class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue< vector<int>, vector<vector<int>> ,greater<vector<int>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,0,0,0}); // stops , row, col , dist
        // note : here stops should be given priority than len , else make 3d dist
        int dx[]={0,1,0,-1};
        int dy[]={1,0,-1,0};
        while(!pq.empty()){
             vector<int>temp = pq.top();
             pq.pop();
             if(temp[0]>k){
                continue;
             }
             for(int q=0;q<4;q++){
                int row = temp[1]+dx[q];
                int col = temp[2]+dy[q];
                int distance = temp[3];
                if(row>=0 && row<n && col>=0 && col<m){
                    if(dist[row][col] > distance+1 ){
                        dist[row][col] = distance+1;
                        int stops = temp[0];
                        if(grid[row][col]==1)
                          stops++;
                        pq.push({stops , row ,col ,dist[row][col]});  
                     }
                }            
             }

        }

        if(dist[n-1][m-1]==1e9){
            return -1;
        }
        return dist[n-1][m-1];


    }
};