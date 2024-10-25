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
       if(x+y < target){
        return false;
       }
        int maxi = x+y;
        int poss[] = {-x,+x,-y,+y}; // various possibilities
        vector<bool> vis(maxi, false);// to avoid redundant calulation
        queue<int> q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(node==target)
              return true;
            for(int k=0;k<4;k++){
                int newNode = node+poss[k];
                if(newNode<0 || newNode > x+y ||vis[newNode]==true){
                   continue;
                }
                vis[newNode] = true;
                q.push(newNode);
            }  
        }
       return false;


    }
};