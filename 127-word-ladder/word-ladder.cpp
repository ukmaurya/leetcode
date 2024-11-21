class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         int n = wordList.size();
         unordered_map<string ,int > mp;
         for(int i=0;i<n;i++){
            mp[wordList[i]]=1;
         }
         queue<pair<int, string>> q;
         if(mp.find(beginWord)!= mp.end()){
                mp.erase(beginWord);
           }
         q.push({1, beginWord});
         while(!q.empty()){
              auto it = q.front();
              q.pop();
              string str = it.second;
              int steps = it.first;
              if(str==endWord)
                return steps;
              int len = str.size();
              for(int i=0;i<len;i++){
                 
                  for(char ch ='a';ch<='z';ch++){
                      string temp = str;
                      if(ch==temp[i])
                       continue;
                      temp[i] = ch;
                       if(mp.find(temp)!= mp.end()){
                          mp.erase(temp);
                          q.push({steps+1 , temp});
                       }

                  }
 
              }
         }
         return 0;
    }
};