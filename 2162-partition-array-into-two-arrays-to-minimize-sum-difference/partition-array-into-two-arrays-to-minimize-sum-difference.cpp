class Solution {
public:
    // int solve(int index, int sum , vector<int>&nums , int total,int
    // count,vector<vector<vector<int>>>&dp , int offset){
    //     int n = nums.size();
    //     if(index==n){
    //         if(count !=n/2)
    //           return INT_MAX;
    //         return abs(total-2*sum);

    //     }
    //     if(dp[index][sum+offset][count] !=-1){
    //         return dp[index][sum+offset][count];
    //     }
    //   int include =  solve(index+1, sum+nums[index] , nums,total
    //   ,count+1,dp,offset ); int exclude =  solve(index+1 , sum ,
    //   nums,total,count ,dp,offset); return dp[index][sum+offset][count] =
    //   min(include , exclude);
    // }

    int minimumDifference(vector<int>& nums) {

        //  int total = 0;
        //  int offset =0;
        //  int n = nums.size();
        // for(int i=0;i<nums.size();i++){
        //     total +=nums[i];
        //     offset += min(0,nums[i]);
        //     // if(nums[i]<0){
        //     //     offset += nums[i];
        //     // }
        // }
        // offset = abs(offset);
        // vector<vector<vector<int>>>dp(n+1 ,
        // vector<vector<int>>(offset+total+1 , vector<int>(n/2+1,-1))); return
        // solve(0,0,nums,total,0,dp,offset);

        // above approach is giving TLE but how to apply DP by above logic

        // it will  be not advaisable to  solve by dp since it contain negative
        // numbers and we cannot make table for negative numbers but we can
        // solve it by maing all number positives

        // applying the meet in middle concept

          int n = nums.size();

           n = n/2;
          int total =0;
         for(int i=0;i<2*n;i++){
            total+=nums[i];
          }

         // step1 : generate all subset of left array(0 to n) and right.array(n/2+1 to 2*n)sepearately

         vector<vector<int>> left(n+1) , right(n+1);
          for(int mask=0;mask<(1<<n);mask++){ //storing the sum of each. subset of all size possible in 0 to n and n+1 to 2n seperately
               int size =0;
               int leftsum =0;
               int rightsum=0;
               for(int i=0;i<n;i++){
                   if(mask&(1<<i) ){
                       size++;
                       leftsum += nums[i];
                       rightsum += nums[i+n];
                   }
                }
                left[size].push_back(leftsum);
                right[size].push_back(rightsum);

          }

         
         // to apply binary search in right subset array just sort it
         for(int i=1;i<=n;i++){
            vector<int> &vec = right[i];
            sort(vec.begin() , vec.end());
        }


          int ans = min(abs(total-2*left[n][0]) ,abs(total-2*right[n][0]));// edge cases as 1) when all element is from left 2) when all element is from right

        //   s1 + s2 = total  => s2 = total-s1 => minimize
        //   s1-s2 => minimise 2*s1-total

        // for s1 we take some element from left and some from right


         for(int i=1;i<=n;i++){
               for(auto j : left[i]){
                 int reqSize = n-i; // since we want s1 to be size of n
                  int leftSum = j;
                  int req = total/2 - leftSum; // for minimising s1-s2;
                  auto it = lower_bound(right[reqSize].begin() ,
                  right[reqSize].end() ,req ); if(it !=
                  right[reqSize].end()){
                         int s1Sum = leftSum + (*it);
                         ans = min(ans , abs(total-2*s1Sum));
                   }
                    // Check the previous element in case it is closer
                 if(it != right[reqSize].begin()) {
                    --it;
                    int rightSum = *it;
                    ans = min(ans, abs(total - 2*(leftSum + rightSum)));
                }

               }

          }
           return ans;
        
    }
};