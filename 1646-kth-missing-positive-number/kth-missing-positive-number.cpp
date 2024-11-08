class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n  = arr.size();
        int start = 0;
        int end = n-1;
        int ans =-1;
        while(start <= end){
            int mid = start-(start-end)/2;
            if((arr[mid]-(mid+1)) < k){
                ans = mid; // just greater or equal
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        if(ans==-1){
            return k;
        }
        int rem = k-(arr[ans]-(ans+1));
       
        return arr[ans]+rem;


        

    }
};