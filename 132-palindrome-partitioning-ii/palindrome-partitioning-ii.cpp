class Solution {
   
    private:
    void isPalindrome(string &s,vector<vector<bool>>&palin  ){
     /*   while(i<j){
            if(s[i]!=s[j]) 
               return false;

            i++;
            j--;

        }
        return true; */   // using this will give time complexity of o(n^3) overall 
        // to reduce to o(n^2) we have to precompute the palindrome )
        // we will store the every substring is palindrime or not 
        
         int n = s.size();
        
         // odd len palindrome
         for(int i=0;i<n;i++){
            palin[i][i]=true;
            for(int j=i-1,k=i+1 ; j>=0 && k<n ; j--,k++){
                if(s[j]==s[k]){
                    palin[j][k]=true;
                }
                else break;
            }
         }
         // even len palindrome
         for(int i=0;i<n;i++){
            palin[i][i]=true;
            for(int j=i,k=i+1 ; j>=0 && k<n ; j--,k++){
                if(s[j]==s[k]){
                    palin[j][k]=true;
                }
                else break;
            }
         }

        return ;
    }
public:
    int minCut(string s){
         
         int n = s.size();
         vector<vector<bool>>palin(n+1,vector<bool>(n+1,false));
          isPalindrome(s,palin);
         vector<int>dp(n+1,0);
         for(int i=n-1;i>=0;i--){
            int ans =INT_MAX;
            for(int k=i;k<n;k++){
              if(palin[i][k]==true){
                int  temp = 1+dp[k+1]; 
                 ans= min(ans, temp);
             }
             dp[i]=ans;
             
           }  
            
         }
              

       return dp[0]-1;
    }
};