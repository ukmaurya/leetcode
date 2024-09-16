class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        int size = tasks.size();
     
        // calculation of frequency 
        unordered_map<char ,int>mp;
        for(int i=0;i<size;i++){
            mp[tasks[i]]++;
            
        }
        // since every time we want max freq => heap required 
        priority_queue<pair<int, char >> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});
            
        }
        
        // calculation of ans
        int ans = 0;
        while(!pq.empty()){
           vector<pair<int, char>> temp;
           ans++;    //placing the highest frequent node
          auto it = pq.top();
          pq.pop();
          if(it.first-1 > 0)
            temp.push_back({it.first-1 , it.second});
           int interval=0;
            for(int i=1;i<=n;i++){ // placing every place within cooling period
                if(!pq.empty()){
                     auto it = pq.top();
                     pq.pop();
                     if(it.first-1 > 0)
                       temp.push_back({it.first-1 , it.second});
                      interval++;
                  }
              
            }
             if(temp.empty()){ 
                ans+=interval;
            }
            else{
                 for(int i=0;i<temp.size();i++){
                   pq.push({temp[i].first , temp[i].second});
                 }
                ans+=(n);
            }
           
            
        }
        
        
        return ans;
    }
};