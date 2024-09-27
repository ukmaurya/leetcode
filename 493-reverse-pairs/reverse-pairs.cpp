class Solution {
    int merge(int start  , int mid , int end , vector<int>&nums){
        vector<int> temp;
        int t = start ;
        int p = mid+1;
        int ans = 0;
        int j = mid+1;
        for(int i=start;i<=mid;i++){
            while(j<=end &&  (long long)2*nums[j]<nums[i]){
              //  ans++;
                j++;
            }
            ans+= j-(mid+1);
        }
        while(t<=mid && p<=end){
            if(nums[t]>nums[p]){
                temp.push_back(nums[p]);
                p++;
             }
            else{
                temp.push_back(nums[t]);
                t++;
            }
            
        }
        while(t<=mid){
            temp.push_back(nums[t]);
            t++;
        }
        while(p<=end){
             temp.push_back(nums[p]);
             p++;
        }
        for(int k=0;k<temp.size();k++){
            nums[k+start] = temp[k];
        }
        return ans;
        
    }
    int mergeSort(int i , int j , vector<int>&nums){
        if(i>=j){
            return 0;
        }
        int mid = (i+j)/2;
        int ans = 0;
        ans+=mergeSort(i,mid, nums);
        ans+=mergeSort(mid+1 , j , nums);
        ans+=merge(i,mid , j,nums);
        return ans;
        
    }
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(0,n-1,nums);
    }
};