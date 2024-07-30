class Solution {

    bool solve(int idx , string s , int openCount , int closeCount,vector<vector<vector<int>>>&dp){
        int n = s.size();
        if(idx == n){
            if(openCount==closeCount){
                return true;
            }
            return false;
        }
        if(openCount<closeCount){
            return false;
        }
        if(dp[idx][openCount][closeCount]!=-1){
            return dp[idx][openCount][closeCount];
        }
        if(s[idx]=='('){
                return dp[idx][openCount][closeCount]=solve(idx+1 , s , openCount+1 , closeCount ,dp);
            }
            else if(s[idx]==')'){
                return dp[idx][openCount][closeCount]=solve(idx+1 , s , openCount , closeCount+1,dp);
            }
            else{
                bool temp1 = solve(idx+1 , s , openCount+1 , closeCount,dp);
                bool temp2 = solve(idx+1 , s , openCount , closeCount+1,dp);
                bool temp3 = solve(idx+1 , s , openCount , closeCount,dp);
                if(temp1||temp2||temp3){
                    return dp[idx][openCount][closeCount]=true;
                }
                return dp[idx][openCount][closeCount]=false;
            }
        
           return dp[idx][openCount][closeCount]=true;
    }
    
public:
    bool checkValidString(string s) {
        int n = s.size();
         int openCount=0;
          int closeCount=0;
          vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
         return solve(0,s ,openCount , closeCount,dp);
    }
};