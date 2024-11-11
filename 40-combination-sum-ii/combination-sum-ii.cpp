class Solution {
    void solve(int idx, vector<int>&candidates ,vector<int>&temp, vector<vector<int>>&ans , int target){
        
        int n = candidates.size();
        if(target==0){
             ans.push_back(temp);
             return;   
            }
       
        if(idx>=n){
            // if(candidates[idx]==target){
            //     temp.push_back(candidates[idx]);
            //     ans.push_back(temp);
            //     temp.pop_back();
                
            // }
            return ;
        }
        
        // we will apply starting of subsequences 
        for(int i=idx;i<n;i++){
            if(i>idx && candidates[i]==candidates[i-1])
               continue;
            if(candidates[i]<=target){
                temp.push_back(candidates[i]);
                solve(i+1 , candidates,temp , ans,target - candidates[i]);
                temp.pop_back(); // backtracking
            }
            // we will now donot take the starting of subsequence same as previous 
        //    while( i<n-1 && candidates[i+1]==candidates[i]){
        //        i++;
        //    }
             
            
        }
        
        
        
        
        
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        // instead of using the pick and not pick logic on every element , we will follow pick subsequences logic , ie for 1st element of a subsequence what can be the possible elements 
        
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin() , candidates.end());
        solve(0,candidates ,temp,ans, target );
        return ans;
        
        
        
        
    }
};