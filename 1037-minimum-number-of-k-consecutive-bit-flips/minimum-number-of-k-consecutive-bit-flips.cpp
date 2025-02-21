class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flipCount = 0;
        int ans = 0;
        vector<bool> flip(n,false);
        for(int i=0;i<n;i++){
             if(i>=k && flip[i-k]==true){
                flipCount--;
             }
             if(flipCount%2 == nums[i]){ // to toogle bit
                  if(i+k>n){ // not possible 
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