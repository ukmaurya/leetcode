class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flipCount = 0;
        int ans = 0;
        vector<bool> flip(n,false);
        for(int i=0;i<n;i++){
             if(i>=3 && flip[i-3]==true){
                flipCount--;
             }
             if(flipCount%2 == nums[i]){ // to toogle bit
                  if(i+3>n){ // not possible 
                    return -1;
                  }
                  flipCount++;
                  ans++;
                  flip[i] = true;
             }
        }
        return ans;
    }
};