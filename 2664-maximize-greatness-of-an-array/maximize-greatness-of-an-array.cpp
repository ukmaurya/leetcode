class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
         map<int,int> mp;
        for(auto i : nums) 
            mp[i]+=1;
        int ans=0;
        vector<int> arr = nums;
        sort(arr.begin(),arr.end());
        for(int i=0;i<nums.size();i++){
            auto x = upper_bound(arr.begin(),arr.end(),nums[i]) - arr.begin();
            while(x<arr.size() && mp[arr[x]]==0) x+=1;
            if(x<nums.size() && mp[arr[x]] > 0 ){
                ans += 1;
                mp[arr[x]] -= 1;
            }
        }
        return ans;
    }
};