class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        // concept : 
        //    ( Pa - Pb)%k ==0  => Pa%k = Pb%k 
        unordered_map<int, int> mp;
        int n = nums.size(), ans = 0, presum = 0;
        mp[0] = 1;
    
        for (int i = 0; i < n; i++)
        {
            presum += nums[i];
            int rem = (presum % k);
            if(rem<0)
              rem = (rem+k)%k;
            ans += mp[rem];  // pair with all previous present sum
            mp[rem]++;
        }
        return ans;
    }
};