class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi , nums[i]);
        }
        int start = 1;
        int end = maxi;
        int ans  = -1;
        while(start <= end){
            int mid = start +(end -start)/2;
            int res = 0;
            for(int i=0;i<n;i++){
                res += ceil( (double)nums[i]/(double)mid ); //res+=(nums[i]/mid)+((nums[i]%mid)!=0);
            }
            if(res <= threshold){
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