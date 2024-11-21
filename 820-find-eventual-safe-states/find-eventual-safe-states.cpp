class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
           int n = graph.size();
           vector<int > adj[n+1];
           vector<int> indegree(n,0);
           vector<int> vis(n,0);
           for(int i=0;i<n;i++){ // build the graph with reverse edges 
              for(auto it: graph[i]){
                 adj[it].push_back(i);
                 indegree[i]++;
              }
           }

           vector<int> ans;
           queue<int> q;
           for(int i=0;i<n;i++){
            if(indegree[i]==0){
                vis[i]=1;
                q.push(i);
            }
           }
           while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0 && !vis[it]){
                    vis[it]=1;
                    q.push(it);
                }

            }
           }
         
        sort(ans.begin(), ans.end());
        return ans;



    }
};