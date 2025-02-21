class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        // extension of 3191 
        // int n = nums.size();
        // int flipCount = 0;
        // int ans = 0;
        // vector<bool> flip(n,false);
        // for(int i=0;i<n;i++){
        //      if(i>=k && flip[i-k]==true){
        //         flipCount--;
        //      }
        //      if(flipCount%2 == nums[i]){ // to toogle bit
        //           if(i+k>n){ // not possible 
        //             return -1;
        //           }
        //           flipCount++;
        //           ans++;
        //           flip[i] = true;
        //      }
        // }
        // return ans;



        // using the deque => space o(k)
        
        int n = nums.size();
        int flipCount = 0;
        int ans = 0;
        deque<int> dq;
        for(int i=0;i<n;i++){
             if(i>=k){
                 flipCount -= dq.front(); // 0 or 1 will be subtracted 
                  dq.pop_front();
             }
             if(flipCount%2 == nums[i]){ // to toogle bit
                  if(i+k>n){ // not possible 
                    return -1;
                  }
                  flipCount++;
                  ans++;
                  dq.push_back(1); // since we are flipping 
                 
             }
             else{
                 dq.push_back(0); // put 0 since we are not flipping 
             }
        }
        return ans;


    }
};