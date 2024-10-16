
class DisjointSet {
    vector<int> size, parent;
public:
    DisjointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

   void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        DisjointSet ds(26);
        int n = equations.size();
        for(int i=0;i<n;i++){
             string temp = equations[i];
             if(temp[1]== '='){
                 ds.unionBySize(temp[0]-'a' , temp[3]-'a');
             }
        }
        for(int i=0;i<n;i++){
             string temp = equations[i];
             if(temp[1] == '!'){
                 int par1 = ds.findUPar(temp[0]-'a');
                 int par2 = ds.findUPar(temp[3]-'a');
                 if(par1==par2){
                    return false;
                 }
             }
        }
        return true;
    }
};