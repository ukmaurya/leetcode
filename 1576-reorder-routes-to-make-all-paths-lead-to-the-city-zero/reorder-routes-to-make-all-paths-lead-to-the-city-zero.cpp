class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // approach 1 : making graph undirected , keep org edges in set 
        // approach 2 : by adding reverse edges with cost 1 and org edges with cost 0
         
         vector<int> adj[n];
         vector<unordered_set<int>> org(n);
         for( auto it: connections ){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            org[u].insert(v);
           }
          vector<int> parent(n,-1);
          int reversed = 0;
          queue<int> q;
          q.push(0);
          while(!q.empty()){
              int node = q.front();
              q.pop();
              for(auto it: adj[node]){
                if(it==parent[node])
                 continue;
                if(org[node].count(it) !=0){ // present in the orginal graph 
                    reversed++;
                }
                parent[it]=node;
                q.push(it);

              }
          }


        return reversed;

    }
};