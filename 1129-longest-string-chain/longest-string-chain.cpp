class Solution {
    private: 
    bool static comp(string &s1 , string &s2){
        if(s1.size() < s2.size())
            return true;
        return false;    
    }
    bool isValid(string &s1 , string &s2){
        int n = s1.size();
        int m = s2.size();
        if(m-n != 1 ) return false;
       // if(m<n) return false;

        int ptr1 = 0;
        int ptr2 = 0;
        int count=0;
        while(ptr1<n && ptr2<m){
            if(s1[ptr1]==s2[ptr2]){
                ptr1++;
                ptr2++;
            }
            else {
                ptr2++;
                count++;
                if(count>=2){
                    return false;
                }
            }
        }
       // if(count==1)  / fails on abc , abcc
          return true;
     //  return false;
    }
    int solve(int i , int last , vector<string>&words ,vector<vector<int>> &dp ){
        int n = words.size();
        if(i>=n)
           return 0;
        if(dp[i][last+1]!=-1) return dp[i][last+1];  // shifting the index 
        // take it
        int take = 0;
        if(last ==-1 || isValid(words[last] , words[i]) )
           take = 1+solve(i+1 , i , words ,dp); 
        int ntake = solve(i+1 , last ,words,dp);

        return dp[i][last+1] = max(take , ntake);     


    }
   
public:
    int longestStrChain(vector<string>& words) {
          // requires sorting since smaller length word may comes after words ... see example 2 
          sort(words.begin() , words.end(), comp); // sorting based on their size 
       /*   // using memoization 
            int size = words.size();
          vector<vector<int>> dp(size,vector<int>(size,-1));
           return solve(0,-1,words ,dp); */
        
          int n = words.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
          for(int i=n-1;i>=0;i--){
              for(int last = i-1;last>=-1;last--){
                  int take = 0;
                  if(last==-1 || isValid(words[last] , words[i])){
                      take = 1+dp[i+1][i+1];
                  }
                  int ntake = dp[i+1][last+1];
                  dp[i][last+1] = max(take ,ntake);
              }
          }
        return dp[0][-1+1];
    }
};