class Solution {
    int atmost(vector<int>&nums , int k){
        int n = nums.size();
        int ans =0;
        unordered_map<int, int > mp;
        int i=0;
        int j=0;
        while(j<n){
            mp[nums[j]]++;
            if(mp.size()<=k){
                ans += (j-i+1);
                j++;
            }
            else{
                while(mp.size()>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]]==0){
                        mp.erase(nums[i]);
                    }
                    i++;
                    if(mp.size()<=k){
                        ans += (j-i+1);
                    }
                }
                j++;
            }
            
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atmost(nums,k)-atmost(nums,k-1);
    }
};