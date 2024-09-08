class Solution {
    bool isValid(int r , int c , int n , int m){
        if(r>=0 && r<n && c>=0 && c<m){
            return true;
        }
        return false;
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
         int n = heights.size();
         int m = heights[0].size();
         priority_queue< pair<int , pair<int , int >> ,vector<pair<int , pair<int , int >>> , greater<pair<int , pair<int , int >>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        dist[0][0] = 0; // heights[0][0];
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        while(!pq.empty()){
            auto temp = pq.top();
            int row = temp.second.first;
            int col = temp.second.second;
            int effort = temp.first;
            pq.pop();
            for(int k = 0;k<4;k++){
                int r = row+dx[k];
                int c = col+dy[k];
                if(isValid(r,c,n,m)){
                    int newEffort = abs(heights[r][c] - heights[row][col]);
                    newEffort = max(newEffort , effort);
                    if(dist[r][c] > newEffort){ // note on >= will give TLE;
                        dist[r][c] = newEffort;
                        pq.push({dist[r][c] , {r,c}});
                    }
                }
            }
            
        }
        return dist[n-1][m-1];
    }
};