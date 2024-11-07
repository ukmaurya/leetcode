class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int > mp;
        mp[0]=1;
        int sum=0;
        int j = 0;
        int ans =0;
        while(j<n){
             sum+= nums[j];
             int req = sum-k;
             if(mp.find(req) != mp.end()){
                ans += mp[req];
             }
             mp[sum]++;
             j++;
        }
        return ans;
    }
};