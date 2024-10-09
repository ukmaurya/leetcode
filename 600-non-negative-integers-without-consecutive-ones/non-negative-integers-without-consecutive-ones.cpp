#define ll long long;
class Solution {
    
    int dp[30][2][2];
    int solve(int idx , string &nums , bool smaller , bool prevOne){
        int n = nums.size();
        if(idx==n){
            return 1;
        }
        if(dp[idx][smaller][prevOne]!=-1){
            return dp[idx][smaller][prevOne];
        }
        
        int limit = (smaller==true)?nums[idx]-'0':1;
        int ans = 0;
        for(int i=0;i<=limit;i++){
            if(i==1 && prevOne==true){
                continue;
            }
            bool newSmaller = smaller&&(i==limit);
            ans += solve(idx+1 , nums ,newSmaller, ((i==1)?true:false));
        }
        return dp[idx][smaller][prevOne]= ans;
        
        
    }
public:
    int findIntegers(int n) {
        
        
        
        // calculates the total number of binary numbers that can be formed with a given number of bits without consecutive 1s  so it is not solution of this question 
//         int bits = log2(n)+1;
//         vector<vector< long long >>dp(bits+1,vector< long long >(2,0));
//         dp[1][0]=1     ;     // ll endOne =1;
// 	    dp[1][1]=1      ;   //  ll endZero = 1;
//         int sum=2;
// 	    for(int i=2;i<=bits;i++){
	               
//                     dp[i][0]=  dp[i-1][0]+ dp[i-1][1];
// 	                dp[i][1]=  dp[i-1][0];
// 	                sum+=dp[i][0]+dp[i][1];
            
         
// 	     }
// 	     return sum;
        
        
        // using digit dp 
        
        string num ="";
        while(n){
            int digit = n%2;
            n=n/2;
            num.push_back(digit+'0');
        }
       
        reverse(num.begin() , num.end());
         //cout<<num<<endl;
        memset(dp,-1,sizeof(dp));
        return solve(0,num,true, false);
    }
};