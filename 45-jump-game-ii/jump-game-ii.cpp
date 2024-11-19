class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curMaxi = 0;
        int maxi = 0;
        int jump = 0;
        for(int i=0;i<n;i++){
            curMaxi = max(curMaxi, i+nums[i]);
            if(i==n-1){
                break;
            }
            if(i==maxi){
               maxi = curMaxi ;
               jump++;
             }
        }
        return jump;
    }
};