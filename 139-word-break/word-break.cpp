class Solution {
    bool solve(int idx,string &s , unordered_map<string , int>mp, vector<int>&dp){
        int n = s.size();
        if(idx==n)
            return true;
        
        if(dp[idx] !=-1){
            return dp[idx];
        }
        for(int i=idx;i<n;i++){
              string temp = s.substr(idx,i-idx+1);
            if(mp.find(temp)!=mp.end()){
              //  string str = s.substr(i+1,n-i+1); //substr takes n time complexity
                if(solve(i+1,s, mp,dp) == true){
                    return dp[i]=true;
                }
            }
        }
        return dp[idx]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         unordered_map<string , int > mp;  //   taking 2^n time  without dp
         for(auto it :wordDict){
             mp[it]++;
         }
        vector<int>dp(s.size(),-1);
        return solve(0,s , mp,dp); 
    }
};