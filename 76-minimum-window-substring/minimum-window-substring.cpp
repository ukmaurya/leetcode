class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        int n = s.size();
        int m = t.size();
        int index = -1;
        int ans = INT_MAX;
        unordered_map<char , int> mp;
        
        for(int i=0;i<m;i++){
            mp[t[i]]++;
           
        }
        int distCount = mp.size();
        int i = 0;
        int j = 0;
        while(j<n){
            if(mp.find(s[j]) != mp.end()){
                  mp[s[j]]--;
                  if(mp[s[j]]==0){
                    distCount--;
                  }
               }
           if(distCount==0){
                 while(distCount==0){
                     if( ans > j-i+1){
                          index = i;
                          ans = min(ans, j-i+1);
                      }
                    if(mp.find(s[i]) != mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1)
                            distCount++;
                     }
                   i++; 
                 }
               j++;
              }
            else if(distCount>0){
                j++;
            }
        }
        if(ans == INT_MAX){
            return "";
        }
        return s.substr(index , ans);
    }
};