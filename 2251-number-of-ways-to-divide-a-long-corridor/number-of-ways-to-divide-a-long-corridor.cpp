/*
class Solution {
    int mod = 1e9+7;
    int solve(int i, int j , string &corridor,int count , vector<int> &dp){
        int n = corridor.size();
        if (i>j) {
           return 1;
        }
        if(dp[i]!= -1){
            return dp[i];
        }
        int ans = 0;
        count = 0;  // To count 'S' characters
        for (int k = i; k <= j; k++) {
            if (corridor[k] == 'S') count++;
            if (count == 2) {
                ans = (ans + solve(k + 1, j, corridor,count, dp) % mod) % mod;
            }
            else if(count>2)
             return 0;
        }
        return dp[i]= ans%mod;
    }
public:
    int numberOfWays(string corridor) {
        int n = corridor.size();
          int count = 0;
        for (char c : corridor) {
            if (c == 'S') count++;
        }
        if (count < 2 || count % 2 != 0) return 0; // Edge case handling
        vector<int> dp(n, -1);
        return solve(0,n-1,corridor,0,dp);
    }
}; */

/*At First sight you may think like i will choose where to partion and use front partition DP and blah.. blah.. blah...

But hold on dear,
have you looked at constraints ?
it will cost you o(n^2) and n is about 1e5 , then how it will work ?

for front partition DP , your n should be about 1e3.
it will be solved by greedy */
class Solution {
public:

   
    int numberOfWays(string cr) {

        int n = cr.size();
        int md = 1e9 + 7; 
        int cnt = 0; 
        int temp = 1; 

        vector < int > arr;
        for(int i = 0 ; i < cr.size() ; i++){
            if(cr[i] == 'S') cnt++; 
            cnt %=2; 
            if(cnt == 0 && cr[i] == 'P') temp++; 
            else{
                arr.push_back(temp); 
                temp = 1; 
            }
        }

        long long ans = 1; 
        if(arr.size() <= 1 || cnt == 1) return 0; 
        for(int i = 1 ; i < arr.size() ; i++){
                ans= ( ans % md * arr[i] % md) % md; 
        }
        return ans; 


    }
};