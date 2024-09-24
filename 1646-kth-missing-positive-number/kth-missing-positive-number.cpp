class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n  = arr.size();
        int start = 0;
        int end = n-1;
        int ans =-1;
        while(start <= end){
            int mid = start-(start-end)/2;
            if((arr[mid]-(mid+1)) >= k){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }


        }
        cout<<ans<<endl;
        if(ans==-1){ // handling of edge cases 
             if(start == 0){ // no missing element 
                 return arr[n-1]+k;
             }
             else if(end==n-1){
                int req = arr[n-1]-n;
                return arr[n-1]+k-req;
             }
        }
        if(ans == 0){
             int miss = arr[0]-1;
             if(miss==0){
                return arr[n-1]+k;
             }
             else{
                return k;
             }
        }
        int prevMiss = arr[ans-1] - ans;
        int req = k-prevMiss;
        return arr[ans-1]+req;
    }
};