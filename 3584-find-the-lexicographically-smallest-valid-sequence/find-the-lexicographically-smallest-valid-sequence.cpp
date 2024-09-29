class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        
        int n = word1.size();
        int m = word2.size();
        vector<int>suff(n+1,0); // at index i it will tell largest suffix of word2 that can be made by from index i in word1
        
        int i=n-1;
        int j=m-1;
        int match=0;
        while(i>=0&&j>=0){
            if(word1[i]==word2[j]){
                match++;
                suff[i]=match;
                i--;
                j--;
                
            }
            else{
                suff[i]=match;
                i--;
            }
        }
        while(i>=0){
            suff[i]=match;
            i--;
        }
        
        // if char match then put in vec else see weather it it is possible to get second string then change else not
        
        i=0;
        j=0;
        vector<int> ans;
        int operations=1;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                i++;
                j++;
            }
            else{
                if(operations==1 && suff[i+1] >= m-1-j){ // remaining string can be constructed then change 
                    operations=0;
                    ans.push_back(i);
                    cout<<i<<" ";
                    i++;
                    j++;
                }
                else{
                    i++;
                }
                
            }
        }
        if(ans.size()==m)
         return ans;
        return {};
        
    }
};