class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        // int gcd = __gcd(x,y);
        // if(x+y<target)
        //   return false;
        // if(target%gcd==0){
        //     return true;
        // }
        // return false;

        // BFS method , just like multiplcation to get to a number 
    //    if(x+y < target){
    //     return false;
    //    }
    //     int maxi = x+y;
    //     int poss[] = {-x,+x,-y,+y}; // various possibilities
    //     vector<bool> vis(maxi, false);// to avoid redundant calulation
    //     queue<int> q;
    //     q.push(0);
    //     vis[0]=true;
    //     while(!q.empty()){
    //         int node = q.front();
    //         q.pop();
    //         if(node==target)
    //           return true;
    //         for(int k=0;k<4;k++){
    //             int newNode = node+poss[k];
    //             if(newNode<0 || newNode > x+y ||vis[newNode]==true){
    //                continue;
    //             }
    //             vis[newNode] = true;
    //             q.push(newNode);
    //         }  
    //     }
    //    return false;

         //dfs
          int total = x + y;
        vector<int>vis(total+1, 0);
        return dfs(total, x, y, 0, target, vis);
    }
    bool dfs(int total, int jug1, int jug2, int jug, int target, vector<int>&vis)
    {
        if(jug>total || jug<0 || vis[jug]==1)
            return false;
        vis[jug]=1;
        if(jug == target)
            return true;
        bool a = dfs(total, jug1, jug2, jug+jug1, target, vis);
        bool b = dfs(total, jug1, jug2, jug-jug1, target, vis);
        bool c = dfs(total, jug1, jug2, jug+jug2, target, vis);
        bool d = dfs(total, jug1, jug2, jug-jug2, target, vis);
        vis[jug]=0;
        return a||b||c||d;
    }
};