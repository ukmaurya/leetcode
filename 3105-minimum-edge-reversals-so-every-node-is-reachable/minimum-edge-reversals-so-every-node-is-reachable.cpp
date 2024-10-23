class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
         
               vector<vector<int>> tree(n);
               vector<unordered_set<int>> orgGraph(n);
                
            for(auto it : edges){ // making the graph undirected for calculating reverse edge cost
                int u = it[0];
                int v = it[1];
                tree[u].push_back(v);
                tree[v].push_back(u);
                orgGraph[u].insert(v);
            }

         queue<int> q;
         q.push(0); // cansitering 0 as root node since in tree any node can act as root node 
         vector<int> depth(n , -1);
         depth[0]=0;
         vector<int> revEdge(n ,0);
         int totalReversed = 0;
         while(!q.empty()){
               int parent = q.front();
               q.pop();
               for(auto it : tree[parent]){
                 if(depth[it]==-1){    // not visited
                     depth[it] = depth[parent]+1;
                     if( orgGraph[parent].count(it) != 0 ){ // edge is present in orginal graph 
                             revEdge[it] = revEdge[parent]+1;
                        }
                     else{
                            revEdge[it] = revEdge[parent];
                            totalReversed++;
                     }
                   q.push(it);
                 }
               
               }
         }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
              ans[i] = totalReversed - (depth[i]-revEdge[i]) + revEdge[i];
        }
        return ans;
            
    }
};