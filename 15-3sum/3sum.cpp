class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
//       set<vector<int>> ans; 
//         int n =nums.size();
//         for(int i=0;i<n;i++){
//             unordered_set<int>st ; // key 
//             for(int j=i+1;j<n;j++){
//                 int req = 0-(nums[i]+nums[j]);
//                 if(st.find(req) != st.end()){
//                     vector<int>temp;
//                     temp.push_back(nums[i]);
//                     temp.push_back(nums[j]);
//                     temp.push_back(req);
//                     sort(temp.begin() , temp.end());
//                     ans.insert(temp);
//                 }
//                 st.insert(nums[j]); // logn factor as , it ordered set
                
//             }
//         }
//         vector<vector<int>>res(ans.begin() , ans.end());
//         return res;
        
        
        // to remove hash set => we will use 2 ponters 
        // to avoid duplicate => we will use sorting 
        
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i]==nums[i-1]){ // avoiding duplicates for i 
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k){
              
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0){
                    ans.push_back({nums[i] , nums[j] , nums[k]});
                    j++;
                    while(j<k && nums[j]==nums[j-1]){ // avoiding suplicates in j 
                        j++;
                    }
                    k--;
                    while(j<k && nums[k]==nums[k+1]){ // avoiding suplicates in k 
                        k--;
                    }
                  
                }
                else if(sum<0){
                    j++;
                     while(j<k&&nums[j]==nums[j-1]){
                        j++;
                    }
                }
                else if(sum>0){
                        k--;
                      while(j<k&&nums[k]==nums[k+1]){
                        k--;
                      }
                
                }
            }
          }
         return ans;
    }
};