class Solution {
    int find(vector<vector<int>>& mat , int j){
        int ans = -1;
        int maxi = -1;
         for(int i=0;i<mat.size();i++){
            if(mat[i][j]> maxi){
                ans = i;
                maxi = max(maxi , mat[i][j]);
            }
         }
         return ans;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
             int n = mat.size();
             int m = mat[0].size();
             int start = 0;
             int end = m-1;
             int row =-1;
             int col =-1; 
             while(start<= end){
                int mid = (start+end)/2;
                int largeRow = -1;
                largeRow = find(mat , mid);
                int left = (mid==0)?-1:mat[largeRow][mid-1];
                int right = (mid==m-1)?-1:mat[largeRow][mid+1];
                if(mat[largeRow][mid]>left && mat[largeRow][mid]>right){
                    row = largeRow;
                    col = mid;
                    break;
                }
                else if(mat[largeRow][mid]<left){
                    end = mid-1;
                }
                else if(mat[largeRow][mid]<right){
                    start = mid+1;
                }

             }
          return {row, col};

    }
};