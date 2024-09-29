class Solution {
public:
    int jump(vector<int>& nums) {
        
      int n = nums.size();
      int maxi = 0;
      int curMaxi = 0;
      int count = 0;
      for(int i=0;i<n;i++){
          maxi = max(maxi, i+nums[i]);
          if(i==n-1){
              break;
          }
          if(i==curMaxi){
              count++;
              curMaxi = maxi;
          }
          
      }
        return count;

    }
};