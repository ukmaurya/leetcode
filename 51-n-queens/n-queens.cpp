class Solution {
    bool issafe(vector<string>& temp, int n, int col, int row) {
        // Check column
        int r = row-1, c = col;
        while (r >= 0) {
            if (temp[r][c] == 'Q') {
                return false;
            }
            r--;
        }
        
        // Check upper-left diagonal
        r = row-1;
        c = col-1;
        while (r >= 0 && c >= 0) {
            if (temp[r][c] == 'Q') {
                return false;
            }
            r--;
            c--;
        }
        
        // Check upper-right diagonal
        r = row-1;
        c = col+1;
        while (r >= 0 && c < n) {
            if (temp[r][c] == 'Q') {
                return false;
            }
            r--;
            c++;
        }
        
        return true;
    }

    void solve(int r, int n, vector<string>& temp, vector<vector<string>>& ans) {
        if (r >= n) {
            ans.push_back(temp);  // If all rows have queens placed, add to solution
            return;
        }

        // Create the string for this row
      
        string s(n, '.');  // Initialize a row with '.'
        for (int i = 0; i < n; i++) {
            s[i] = 'Q';  // Place queen at position (r, i)
            temp.push_back(s);  // Push this row into the temp board
            if (issafe(temp, n, i, r)){
               
                solve(r + 1, n, temp, ans);  // Recurse to solve the next row
               
            }
             temp.pop_back();  // Backtrack: remove the last added row
             s[i] = '.';  // Reset the queen position for the next column check
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, n, temp, ans);
        return ans;
    }
};
