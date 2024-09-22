class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        if(n!=m){
            return false;
        }
     /*   unordered_map<char , int> mps;
        unordered_map<char , int> mpt;
        for(int i=0;i<n;i++){
            mps[s[i]]++;
            mpt[t[i]]++;
        }
        for(int i=0;i<n;i++){ // considering the order among the characters 
            if(mps[s[i]] != mpt[t[i]]){
                return false;
            }
        }
        
        return true; */
        
        //above logic is failing on example s = "bbbaaaba"  t = "aaabbbba"
        
        // we will store the mapping amping the characters
        unordered_map<char , char> mps;
        unordered_map<char , char> mpt;
        for(int i=0;i<n;i++){
           if(mps.find(s[i])!=mps.end()){ // mapping of s characters to t characters
               if(mps[s[i]] != t[i]){
                   return false;
               }
           }
           else{
                mps[s[i]]=t[i];
            }
            if(mpt.find(t[i])!=mpt.end()){ // mapping of t characters to s characters 
                 if(mpt[t[i]] != s[i]){
                   return false;
               }
            }
            else{
                mpt[t[i]]=s[i];
            }
        }
        return true;
    }
};