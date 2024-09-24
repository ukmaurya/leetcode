class Solution {
    bool possible(int mid , vector<int>&weights ,int day){
      /*  int n= weights.size();
         int sum = 0;
          int count = 1;
         for(int i=0;i<n;i++){
               sum+=weights[i];
               if(sum>mid){
                    count++;
                    sum=weights[i];
               }
         }
         if(count<=day)
            return true;
         return false;   */
        cout<<mid<<" " <<day <<endl;
        int count = 1;
        int wt = 0;
        int n = weights.size();
        for(int i=0;i<n;i++){
            if(weights[i]>mid){
                return false;
            }
            if(wt+weights[i]<=mid){
                wt = wt+weights[i];
                
            }
            else{
                wt = weights[i];
                count++;
            }
        }
    
        if(count <= day){
            return true;
        }
     return false; 
        
    }
       
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int start =0;
        int end = 0;
        for(int i=0;i<n;i++){
            end += weights[i];
        }
        int ans =-1;
        while(start<=end){
            int mid = start-(start-end)/2;
            if(possible(mid , weights , days)){  //in the order given by weights. so donot think of subsets 
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
};