class Solution {
    vector<vector<bool>> dp;
    private:
    /* bool isValid(int start , int end , string s){
         while(start<end){
            if(s[start]!=s[end]){
                return false ;
            }
            start++;
            end--;
        }
        return true;
    } */
    bool isValid(int start ,int end ,string s){
        if(dp[start][end]==true){
            return true;
        }
        return false;
    }
    void solve(int i, int n , string s, vector<string >&temp , vector<vector<string>> &ans){
        if(i==n){
            ans.push_back(temp);
           return;
        }
        for(int par = i;par<n;par++){
            if(isValid(i,par,s)){
                 temp.push_back(s.substr(i,par-i+1));
                 solve(par+1,n,s,temp,ans);
                 temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        // if s len <=500 then we have to use DP
        // but mostly in returning string we use recursion only 
        int n = s.size();
        dp.resize(n,vector<bool>(n,false));
        // to get palindrome status in o(1) time 
        for(int i=0;i<n;i++){ // every one len string are palindrome
            dp[i][i] = true;
        }
        // check for 2 len palindrome 
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
            }
    
        }
        
        // filling the table row and col wise will gice wrong result see by example
     /*   for(int i=0;i<n;i++){ // starting of substring
            for(int j=0;j<n;j++){ // ending of substring
                if(j<=i){ 
                    continue;
                }
               else{
                    if(dp[i+1][j-1]==true){
                        if(s[i]==s[j]){
                            dp[i][j]=true;
                        }
                    }
                }
            }
        } */
      // fill diagonal wise
        for(int len = 3;len<=n;len++){ // for each len 3,4,5,....
            for(int i=0;i<=n-len;i++){ // start index
                int j = i+len-1;   //    end index
                if(dp[i+1][j-1]==true  && s[i]==s[j]){ 
                    dp[i][j]=true;
                }
            }
        }
        
       vector<vector<string>> ans;
       vector<string> temp;
       solve(0,s.size(),s,temp,ans);
       return ans; 
    }
};