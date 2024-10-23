class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
       
         int mod = 1e9+7;
        vector<pair<int,long long int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }

        priority_queue<pair<long long int,int>,vector<pair<long long int,int>> ,greater<pair<long long int,int>>> pq;
        pq.push({0,0});
        vector<long long int> time(n,LONG_MAX);// BE CAREFUL 
        vector<long long int> ways(n,0);
        time[0]=0;
        ways[0]=1;
        while(!pq.empty()){
              
              auto topp = pq.top();
              int node = topp.second;
              long long int wt = topp.first;
              pq.pop();
              for(auto it: adj[node]){
                int adjnode = it.first;
               long long int  adjwt = it.second;
                if(time[adjnode] > adjwt+wt){
                    time[adjnode] = adjwt+wt;
                    ways[adjnode] = ways[node]%mod;
                    pq.push({time[adjnode] , adjnode});
                }
                else if(time[adjnode]== adjwt+wt){
                      ways[adjnode ] = (ways[adjnode ]%mod+ways[node]%mod)%mod;
                }

              }

        }
        return ways[n-1]%mod;
        
    }
};