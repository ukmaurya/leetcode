class Solution {
    int timer =1;
    int maxi =-1;
    void dfs(int node ,vector<int> adj[] , vector<int>&inTime,vector<bool> &samePath ){
         inTime[node] = timer;
         samePath[node]= true;
         timer++;
         for(auto it: adj[node]){
               if(inTime[it] == 0){ // not visited
                   dfs(it , adj , inTime,samePath);
               }
               else if(inTime[it]<inTime[node] && samePath[it]==true){ // already visited 
                    maxi = max(maxi , inTime[node]-inTime[it]+1);
               }
         }
         samePath[node]= false;
         
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(edges[i]!= -1)
             {
                 adj[i].push_back(edges[i]);
             }
        }

        vector<int> inTime(n,0);
        vector<bool> samePath(n , false);
        for(int i=0;i<n;i++){
            if(inTime[i]==0){
                 timer =1; //reset the timer for new components
                 dfs(i, adj , inTime , samePath );
            }
        }
        return maxi;

    }
};