class Solution {
    int solve(string beginWord, string endWord, unordered_map<string, int>& mp) {
        int n = beginWord.size();
        if (beginWord == endWord) {
            return 0;  // If we have reached the end word, no more transformations are needed
        }

        int ans = 1e5;  // Initialize to a large value
        string temp = beginWord;  // Temporary word for transformation

        // Try changing each character in the current word
        for (int i = 0; i < n; i++) {
            char originalChar = temp[i];  // Store the original character

            // Try replacing the character with every letter from 'a' to 'z'
            for (char it = 'a'; it <= 'z'; it++) {
                if (it == originalChar) continue;  // Skip if it's the same character

                temp[i] = it;  // Change the character

                // If the new word is in the word list
                if (mp.find(temp) != mp.end()) {
                    cout << temp << " ";  // Print the transformed word for debugging

                    // Remove the word to mark it as visited
                    mp.erase(temp);

                    // Recursively solve for the next transformation and add 1 step
                    int steps = 1 + solve(temp, endWord, mp);

                    // Restore the word back for the next iteration
                    mp[temp]++;  // Backtrack by adding the word back to the map

                    // Update the answer with the minimum steps found
                    ans = min(ans, steps);
                }
            }
            temp[i] = originalChar;  // Restore the original character for the next position
        }

        return ans;
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
              
       /*  unordered_map<string, int> mp;
        for (const string& word : wordList) {
            mp[word]++;
        }

        if (mp.find(endWord) == mp.end()) {
            return 0;  // If endWord is not in the word list, no transformation is possible
        }

        int ans = solve(beginWord, endWord, mp);  // Start DFS from the beginWord

        return (ans >=1e5) ? 0 : ans + 1;  // If no transformation found, return 0; otherwise, return ans + 1 */


       // we were using the dfs which was leading to tle => do by example 

        // it is wise dicision to apply BFS on shortet path 
        unordered_map<string, int> mp;
        for (const string& word : wordList) {
            mp[word]++;
        }

        if (mp.find(endWord) == mp.end()) {
            return 0;  // If endWord is not in the word list, no transformation is possible
        }
        queue<pair<string , int >> q; // string ,  steps
        q.push({beginWord,1});
        int ans = 0;
        mp.erase(beginWord);
        while(!q.empty()){
             auto it = q.front();
             q.pop();
             string temp = it.first;
             int step = it.second;
             if(temp==endWord){
                 return  step;
             }
             for(int i=0;i<temp.size();i++){
                char org = temp[i];
                for(char ch = 'a';ch<='z';ch++){
                if(ch==temp[i])
                   continue;
                  temp[i]=ch;
                  if(mp.find(temp)!=mp.end()){
                      mp.erase(temp); // we keep track of visited array in bfs
                      q.push({temp,step+1});
                  }
                  temp[i] = org;
                }
                
             }

        } 
       return ans;
    }
};