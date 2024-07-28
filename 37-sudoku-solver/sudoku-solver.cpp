class Solution {
    bool isvalid(int r , int c , char num,vector<vector<char>>& board){
        int n = board.size();
        
        // validation submatrix 
        
        int boxr = r/3;
        int boxc = c/3;
        int startr = boxr*3;
        int startc = boxc*3;
        for(int i = startr;i<startr+3;i++){
            for(int j=startc;j<startc+3;j++){
                if(board[i][j]==num && i!=r && j!=c){
                    return false;
                }
            }
        }
        
        // validating col ;
       for(int i=0;i<n;i++){
           if(board[i][c]==num && i!=r){
               return false;
           }
       }
        // validating row
         for(int i=0;i<n;i++){
           if(board[r][i]==num && i!=c){
               return false;
           }
       }
        
        
        return true;
    }
     bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){ 
                    // try all possibilies
                    for(char num = '1';num<='9';num++){
                         if(isvalid(i,j,num,board)){
                            board[i][j]=num;
                            if(solve(board)==true)
                                return true;
                            else  
                               board[i][j]='.';
                        }
                    }
                    return false;
                    
                }
                
                
            }
        }
         return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
        return;
    }
};