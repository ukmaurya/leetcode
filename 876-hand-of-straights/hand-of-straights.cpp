class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize != 0)
         return false;
        unordered_map<int, int > mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        priority_queue<int, vector<int> , greater<int>> pq;
        for(auto it: mp){
            pq.push(it.first);
        }
        while(!pq.empty()){
             int ele = pq.top();
             
             for(int i=0;i<groupSize;i++){
                if(mp.find(i+ele)==mp.end())
                  return false;
                else{
                      mp[i+ele]--;
                      if(mp[i+ele]==0)
                      {
                            pq.pop();
                            mp.erase(i+ele);  
                      }
                  }  

             }

        }
        return true;
    }
};