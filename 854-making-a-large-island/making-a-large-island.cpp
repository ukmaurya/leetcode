class disjointset {
public:
    vector<int> parent, size;
    disjointset(int n) {
        parent.resize(n + 1);
        size.resize(n + 1 ,1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }
    int ultiPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = ultiPar(parent[node]);
    }
    void unionSize(int u, int v) {
        int x = ultiPar(u);
        int y = ultiPar(v);
        if (x == y) {
            return;
        }
        if (size[x] <= size[y]) {
            parent[x] = y;
            size[y] += size[x];
        } else {
            parent[y] = x;
            size[x] += size[y];
        }
    }
};
class Solution {

private:
    void makeComponent(int row, int col, vector<vector<int>>& grid,
                       vector<vector<int>>& vis, disjointset& ds) {
        int n = grid.size();
        vis[row][col] = 1;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        for (int k = 0; k < 4; k++) {
            int r = row + dx[k];
            int c = col + dy[k];
            if (r >= 0 && r < n && c >= 0 && c < n && vis[r][c] == 0 &&
                grid[r][c] == 1) {
                int parent = col * n + row;
                int child = c * n + r;
                int p1 = ds.ultiPar(parent);
                int p2 = ds.ultiPar(child);
                if (p1 != p2) {
                    ds.unionSize(parent, child);
                }
                makeComponent(r, c, grid, vis, ds);
            }
        }
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointset ds(n * n);
        vector<vector<int>> vis(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    makeComponent(i, j, grid, vis, ds);
                }
            }
        }

        int ans = 0;
        int countZero = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                 unordered_set<int> st;
                if (grid[i][j] == 0) { // try changing it
                     countZero++;
                    int dx[] = {0, 1, 0, -1};
                    int dy[] = {1, 0, -1, 0};

                    for (int k = 0; k < 4; k++) {
                        int row = i + dx[k];
                        int col = j + dy[k];
                        if (row >= 0 && row < n && col >= 0 && col < n && grid[row][col]==1) {
                            int node = n * col + row;
                            int parent = ds.ultiPar(node);
                            st.insert(parent);
                        }
                    }
                    int compoSize = 0;
                    for (auto it : st) {
                        compoSize += ds.size[it];
                        cout<<compoSize<<" ";
                    }
                
                    ans = max(ans, 1+compoSize);
                }
            }
        }
        if(countZero==0){ // no zero in grid
            return n*n;
        }
        else if(countZero == n*n){
            return 1;
    }
        return ans;
    }
};