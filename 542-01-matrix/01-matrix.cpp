class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, pair<int, int >>> q;
        vector<vector<int>> vis(n, vector<int>(m,0));
        vector<vector<int>> ans(n, vector<int>(m,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    ans[i][j]=0;
                    q.push({i,{j,0}});
                }
            }
        }
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second.first;
            int time = it.second.second;
            for(int k=0;k<4;k++){
                int row = r+dx[k];
                int col = c+dy[k];
                if(row>=0&&row<n&&col>=0&&col<m && !vis[row][col] && mat[row][col]==1){
                     vis[row][col]=1;
                    if(ans[row][col] >= time+1){
                        ans[row][col]= time+1;
                         q.push({row,{col,time+1}});
                      }
                }
            }
        }


        return ans;
    }
};