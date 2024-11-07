class Solution {
    bool poss(vector<int>&arr , int k , int m , int mid ){
        int n = arr.size();
        int count=0;
        int req =0;
        for(int i=0;i<n;i++){
            if(arr[i]<= mid){
                count++;
                if(count==k){
                    count=0;
                     req++;
                }
            }
            else{
                count=0;
            }
        }
        if(req >= m){
            return true;
        }
        return false;

    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi, bloomDay[i]);
        }
        int start = 0;
        int end = maxi;
        int ans =-1;
        while(start<= end){
            int mid = (start+end)/2;
            if(poss(bloomDay , k ,m ,mid)){
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