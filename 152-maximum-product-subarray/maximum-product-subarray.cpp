
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // approach 1 : '0' act as divider so we will use prefix and suffix logic
        double  pre = 1;
        double suff =1;
        double  n = nums.size();
         double  ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(pre==0){ //
                pre=1;
            }
            if(suff==0){
                suff=1;
            }
            pre = pre*nums[i];
            suff = suff*nums[n-i-1];
            ans = max(ans , max(pre, suff));
        }
        return ans;
    }
};