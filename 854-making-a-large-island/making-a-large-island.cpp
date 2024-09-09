class DisjointSet{
    public: 
    vector<int> parent , size;
    
     DisjointSet(int n ){
        parent.resize(n+1);
        size.resize(n+1 , 1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
     }
     
    void unionSize(int u , int v){
        int ulp_u = ultiPar(u);
        int ulp_v = ultiPar(v);
        if(ulp_u != ulp_v){
            if(size[ulp_u] <= size[ulp_v]){
                 parent[ulp_u] = parent[ulp_v];
                 size[ulp_v] += size[ulp_u];
            }
            else{
                 parent[ulp_v] = parent[ulp_u];
                 size[ulp_u] += size[ulp_v];
            }
        }

    } 
    int ultiPar(int node){
        if(parent[node] == node){
             return node;
        }
        else{
            return parent[node] = ultiPar(parent[node]); // path compresion
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        // connecting the islands
        int dx[] = {0,1,0,-1};
        int dy[] ={1,0,-1,0};
       
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int node = j*n+i;
                    for(int k=0;k<4;k++){
                        int adjR = i+dx[k];
                        int adjC = j+dy[k];
                        if(adjR>=0&&adjR<n && adjC>=0 &&adjC<n && grid[adjR][adjC]==1){
                            int adjnode = adjC*n+adjR;
                            int x = ds.ultiPar(adjnode);
                            int y = ds.ultiPar(node);
                            if(x==y){
                                continue;
                            }
                            else{
                                ds.unionSize(x,y);
                            }
                        }
                    }
                }
            }
        }
        int maxi =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int s =0;
                if(grid[i][j]==0){
                    set<int> st;
                    for(int k=0;k<4;k++){
                        int adjR = i+dx[k];
                        int adjC = j+dy[k];
                        if(adjR>=0&&adjR<n && adjC>=0 &&adjC<n && grid[adjR][adjC]==1){
                            int adjnode = adjC*n+adjR;
                            int x = ds.ultiPar(adjnode);
                            st.insert(x);
                        }
                    }
                    for(auto it: st){
                        s += ds.size[it];
                    }
                    maxi = max(maxi , s+1);
                }
            }
        }
         for(int i=0;i<n*n;i++){ //for edge case when the grid have all ones 
          maxi = max(maxi , ds.size[i]);
       }
        
        return maxi ;
    }
};