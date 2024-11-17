class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
          int n = nums.size();
          int sum =0;
          int ans=0;
          unordered_map<int ,int > mp;
          mp[0]=1;
          for(int i=0;i<n;i++){
            sum += nums[i];
            int req = sum-goal;
            if(mp.find(req)!= mp.end()){
                ans += mp[req];
            }
            mp[sum]++;
          }
          return ans;
    }
};