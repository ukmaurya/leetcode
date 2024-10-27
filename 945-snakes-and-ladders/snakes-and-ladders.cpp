class Solution {
   
public:
    int snakesAndLadders(vector<vector<int>>& board) {
       int n = board.size();
       vector<int>arr(n*n+1,-1);
       bool flag = true;
       int index= 1;
       for(int i=n-1;i>=0;i--){ // convert to 1 d array 
          if(flag){
              for(int j=0;j<n;j++){
                 arr[index++] = board[i][j];
              }
             
          }
          else{
             for(int j=n-1;j>=0;j--){
                 arr[index++] = board[i][j];
              }
             
          }
           flag = !flag;
       }
       // dfs will fails due to cycle may be present

       queue<pair<int,int>> q;
       vector<int> vis(n*n+1,0);
       vis[1]=1;
       q.push({0,1});
       while(!q.empty()){
        auto it = q.front();
        int node = it.second;
        
        int dist = it.first;
        q.pop();
        if(node>n*n)
          continue;
        if(node==n*n)
          return dist;
        for(int i=1;i<=6;i++){
            int nextNode = node + i;
            if (nextNode <= n * n ) {
                if (arr[nextNode] != -1) {
                    nextNode = arr[nextNode];
                }
                if (!vis[nextNode]) {
                    vis[nextNode] = 1;
                    q.push({dist + 1, nextNode});
                }
            }
        }


       }
       
      return -1;


    

    }
};