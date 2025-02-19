class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int k  = nums.size();
        vector<pair<int,int>> arr; // pair each element with its list no 
        for(int i=0;i<k;i++){
            for(int j = 0;j<nums[i].size();j++){
                arr.push_back({nums[i][j],i});
            }
        }
        sort(arr.begin() , arr.end());
        // now apply the tje 2 pointer approach 
        int ans = INT_MAX;
        vector<int> res(2);
        int i=0;
        int j = 0;
        int n = arr.size();
        unordered_map<int, int > mp; 
        while(j<n){
              mp[arr[j].second]++;
              if(mp.size()<k){
                 j++;
              }
              else if(mp.size()==k){
                 while(mp.size()==k){
                    if(arr[j].first-arr[i].first< ans){
                         ans = arr[j].first-arr[i].first;
                        res[0]=arr[i].first;
                        res[1]=arr[j].first;
                    }
                    mp[arr[i].second]--;
                    if(mp[arr[i].second]==0){
                        mp.erase(arr[i].second);
                    }
                     i++;
                 }
                 j++;
              }
        }
     
        return res;
    }
};