// class Solution {
//     int solve(int idx ,int jump, bool downJump , int k,vector<vector<vector<int>>>&dp){
//         if(idx==k){
//             return 1;
//         }
//         else if(idx==k+1 && downJump==false){
//             return 1;
//         }
//         else if(idx>k){
//             return 0;
//         }
//         if(dp[idx][downJump][jump]!=-1){
//             return dp[idx][downJump][jump];
//         }
//         int down = 0;
//         if(downJump==false && idx>=0){
//             down = solve(idx-1, jump , true , k,dp);
//         }
//         int up = 0;
//         int value = idx+pow(2,jump);
//         up= solve(value, jump+1 , false , k,dp);
//         return dp[idx][downJump][jump] = down+up;
        
        
        
        
//     }
// public:
//     int waysToReachStair(int k) {
//         if(k==0)
//             return 2;
//         else if(k==1)
//            return 4;
//         else if(k==2)
//               return 4;
        
//         bool downJump= false;
//         int jump = 0;
//         vector<vector<vector<int>>>dp(50 , vector<vector<int>>(2, vector<int>(50,-1)));
//          return solve(1,jump,downJump,k,dp);
//     }
// };

// above was giving memory limit excedded 

class Solution {
public:
    long long fun(int stair,int curr,int jump,int k){
        if(stair>k+1)return 0;
        long long ans = 0;
        if(stair==k)ans++;
        if(curr==1){
            ans+=fun(stair - 1,0,jump,k);
        }
        ans+=fun(stair + pow(2,jump),1,jump + 1,k);
        return ans;
    }
//     jump and back parameter will not exceed 40 as max value of k is 10^9( 2^40 >>> 10^9)
// stat will have two value. (0-when backstep is not allowed, 1-when backstep is allowed)
// So we can use a memo of the form dp[50][50][2].
    long long dp[50][50][2];
    long long dp_fun(int stair,int curr,int jump,int back,int k){
        if(stair>k+1)
            return 0;
        if(dp[jump][back][curr]!=-1)
            return dp[jump][back][curr];
        long long ans=0;
        if(stair==k)
            ans++;
        if(curr==1){
            ans+=dp_fun(stair - 1,0,jump,back+1,k);
        }
        ans+=dp_fun(stair + pow(2,jump),1,jump + 1,back,k);
        return dp[jump][back][curr] = ans;
    }
    int waysToReachStair(int k) {
        // return fun(1,1,0,k);
        memset(dp,-1,sizeof(dp));
        return dp_fun(1,1,0,0,k);
    }
};