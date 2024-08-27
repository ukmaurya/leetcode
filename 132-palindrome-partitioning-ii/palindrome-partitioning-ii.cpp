class Solution {
    private:
    bool isPalindrome(string &s , int i, int j ){
        while(i<j){
            if(s[i]!=s[j]) 
               return false;

            i++;
            j--;

        }
        return true;

    }
public:
    int minCut(string s){
         
         int n = s.size();

         vector<int>dp(n+1,0);
         for(int i=n-1;i>=0;i--){
            int ans =INT_MAX;
            for(int k=i;k<n;k++){
              if(isPalindrome(s,i,k)){
                int  temp = 1+dp[k+1]; 
                 ans= min(ans, temp);
             }
             dp[i]=ans;
             
           }  
            
         }
              

       return dp[0]-1;
    }
};