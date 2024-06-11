class Solution {
    /* // mp1 stores frequency of elements
        // mp2 stores frequency of current frequencies of elements
        unordered_map<int,int> mp1 , mp2;

        int n = nums.size();
        int ans = 1;
        for(int i=0;i<n;i++) {
            if(mp1[nums[i]] != 0) {               // updating frequency of current frequencies
                mp2[mp1[nums[i]]]--;
                if(mp2[mp1[nums[i]]] == 0) mp2.erase(mp1[nums[i]]);
            }
            mp1[nums[i]]++;                  
            mp2[mp1[nums[i]]]++;

            // just go through some observations, it's easy to understand!
            if(mp2.size() == 2) {                       
                int maxi = 0 , mini = n;
                bool flg = 0;
                for(auto &it : mp2) {
                    maxi = max(maxi,it.first);
                    mini = min(mini,it.first);
                }
                if(maxi == mini+1 && mp2[maxi] == 1) flg = 1;
                if(mini == 1 && mp2[1] == 1) flg = 1;

                if(flg) ans = i+1;
            } else if(mp2.size() == 1) {
                auto it = mp2.begin();
                if(it->first == 1 || mp1.size() == 1) ans = i+1;
            }
        }
        return ans;
    */
    
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