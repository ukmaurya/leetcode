class Solution {
public:
    int characterReplacement(string s, int k) {
         
        // extension of 1004. Max Consecutive Ones III
        // but here any character can be changed 
        
        int n = s.size();
        int maxFreq =0; // it helps in knowing how many operations are performed in current window
        int i=0;
        int j=0;
        int ans = 0;
        unordered_map<char , int > mp;
        while(j<n){
            mp[s[j]]++;
            maxFreq = max(maxFreq ,mp[s[j]] );
            if(maxFreq+k > j-i+1){ // less than k inversion 
                
                ans = max(ans , j-i+1);
                j++;
            }
            else if( maxFreq+k == j-i+1){ // exactly k inversion 
                ans = max(ans , j-i+1);
                j++;
            }
            else{ // more than k inversion 
                
                while(maxFreq+k < (j-i+1)){
                     mp[s[i]]--;
                    if(mp[s[i]]==0){
                        mp.erase(mp[s[i]]);
                    }
                    i++;
                }
                j++;
            }
            
        }
        
        return ans;
        
    }
};