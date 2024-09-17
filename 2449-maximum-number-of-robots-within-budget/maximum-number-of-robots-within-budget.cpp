class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget){
        
         int n = chargeTimes.size();
         int i = 0;
         int j = 0;
         deque<int> dq; // stores the maximum of the windows 
         
         long long cost = 0;
         long long sum =0;
         int ans = 0;
         while(j<n){
             while(!dq.empty()&& dq.back()<chargeTimes[j]){
                 dq.pop_back();
             }
             dq.push_back(chargeTimes[j]);
             sum+=runningCosts[j];
             cost = dq.front()+(j-i+1)*sum;
            if(cost<=budget){ // increase the window size
                 ans = max(ans,j-i+1);
                 j++;
                 
             }
             else{ // slide the window 
                 if(dq.front()==chargeTimes[i]){
                     dq.pop_front();
                 }
                 sum -= runningCosts[i];
                 i++;
                 j++;
                 
             }
         }
        return ans;
    }
};