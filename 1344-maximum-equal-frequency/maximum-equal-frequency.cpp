class Solution {
   
    
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp,freq ; // mp store the frequency of every element 
        // freq will store the freq of each freq ie how many elements have same frequency 
        
        int ans =1;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) != mp.end()){ // earlier present in map ie this element appeared in array atleast once 
                freq[mp[nums[i]]]--; // since freq of nums[i] will change 
                if(freq[mp[nums[i]]]==0)
                    freq.erase(mp[nums[i]]);
                
            }
            mp[nums[i]]++;
            freq[mp[nums[i]]]++;
            
            // two case can leads to ans when mp2 size == 1 or 2
            if(freq.size()==1){
                if(mp.size()==1){ // only one elements 
                    ans = max(ans , i+1);
                }
                else if(mp.size()>1){ // more than one elem
                    auto it = freq.begin();
                    if(it->first==1) // every elements are accuring only once 
                        ans= max(ans,i+1);
                   
                }
                
                
            }
            else if(freq.size()==2){
                
                int maxi = INT_MIN;
                int mini = INT_MAX;
                for(auto it : freq){
                    maxi = max(maxi , it.first);
                    mini = min(mini , it.first);
                }
                // 2 cases     1) aaabbbcccc  2) ccaab 
                if(maxi == mini+1 && freq[maxi]==1)
                    ans = max(ans, i+1);
                if(mini==1 && freq[mini]==1)    
                    ans = max(ans , i+1);
                
            }
        }
        return ans;
        
    }
};