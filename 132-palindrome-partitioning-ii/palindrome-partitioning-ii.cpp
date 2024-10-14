class Solution {
   
    private:
    void isPalindrome(string &s,vector<vector<bool>>&dp  ){
     /*   while(i<j){
            if(s[i]!=s[j]) 
               return false;

            i++;
            j--;

        }
        return true; */   // using this will give time complexity of o(n^3) overall 
        // to reduce to o(n^2) we have to precompute the palindrome )
        // we will store the every substring is palindrime or not 
        
        //  int n = s.size();
        //  for(int i =0;i<n;i++){ // intitialising 1 len palindrome
        //     palin[i][i]= true;
        //  }
        //  for(int i=0;i<n-1;i++){ // inititalising 2 len palindrome 
        //     if(s[i]==s[i+1])
        //      palin[i][i+1] = true;
           
        //  }
        //  for(int len =2;len<n;len++){
        //     for(int i=0,j=len;i<n,j<n;i++,j++){
        //         if(s[i]==s[j]){
        //             if(palin[i+1][j-1]==true){
        //                 palin[i][j] = true;
        //             }
        //         }
        //     }
        //  }
        //  for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<palin[i][j]<<" ";
        //     }
        //     cout<<endl;
        //  }

        // return ;
        int n = s.size();
        for(int gap=0;gap<n;gap++){
            for(int i=0,j=gap; j<n ;i++,j++){
                if(i==j ){
                    dp[i][j]= true;
                  
                }
                else if(j == i+1){
                    dp[i][j] = (s[i]==s[j])?true:false;
                  
                }
                else if(s[i]==s[j]){
                    if(dp[i+1][j-1]==true){
                        dp[i][j] = true;
                      
                    }
                    else{
                        dp[i][j]= false;
                    }
                }
                 
            }
        }
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