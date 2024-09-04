class Solution {
    bool solve(int node , vector<int>adj[] , int col, vector<int> &colour , vector<bool>&vis){
        vis[node] = true;
        colour[node] = col;
        for(auto it: adj[node]){
            if(colour[it]==col){
                return false;
            }
            else if(!vis[it]){
                if(solve(it,adj,1-col,colour,vis)==false)
                    return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
                adj[graph[i][j]].push_back(i);
            }
        }
       
       vector<int> colour(n,-1);
       vector<bool> vis(n, false);
       int ans = true;
       for(int i=0;i<n;i++){
           if(!vis[i])
             ans = ans && solve(i, adj, 1,colour , vis  );
       }
        return ans;
        
    }
};