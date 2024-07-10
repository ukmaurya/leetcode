class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        vector<int> hash(256,0); // given that s consists of English letters, digits, symbols and spaces.
        int ans = 0;
        while(j<n){
            hash[s[j]]++; // since the size is 256 so no need of hash[s[j]-'a'];  
            if(hash[s[j]] == 1){
                ans = max(ans , j-i+1);
                j++;
            }
            else if(hash[s[j]]>1){ // duplicate elements
                while(hash[s[j]] != 1){
                    hash[s[i]]--;
                    i++;
                }
                           j++;
            }
            
        }
        return ans ;
    }
};