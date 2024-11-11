class Solution {
    void solve(int idx , vector<int>&nums , vector<int>&temp , vector<vector<int>>&ans ){
        int n = nums.size();
        if(idx>=n){
            ans.push_back(temp);
            return ;
        }
       
        // use starting of subset logic to avoid duplicates;
        for(int i = idx;i<n;i++){
            if(i>idx &&nums[i]==nums[i-1])
                continue;
            temp.push_back(nums[i]);
            solve(i+1 , nums , temp , ans);
            temp.pop_back();
           
            
        }
         ans.push_back(temp);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, nums , temp , ans);
        return ans;
        
    }
};