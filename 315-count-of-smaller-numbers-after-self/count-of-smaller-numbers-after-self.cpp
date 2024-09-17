class Solution {
    
    private:
  /*  void merge(int start, int mid , int end , vector<pair<int,int>>&arr , vector<int>&ans, {
  vector<int>&ans){
        vector<pair<int,int>> temp;
        int i = start;
        int j= mid+1;
        while(i<=mid && j<=end){
            if(arr[i].first<=arr[j].first){
                   temp.push_back({arr[j].first , arr[j].second});
                   j++;
             }
            else{
                 ans[arr[i].second] += end-j+1;
                 temp.push_back({arr[i].first , arr[i].second});
                 i++;
            }
        }
        while(i<=mid){
             temp.push_back({arr[i].first , arr[i].second});
              i++;
        }
        while(j<=end){
             temp.push_back({arr[j].first , arr[j].second});
             j++;
        }
        for(int i=0;i<temp.size();i++){
            arr[i+start].first = temp[i].first;
            arr[i+start].second = temp[i].second;
            
        }
    } */
    
    // earlier function was correct but it was doing by sorting in decreasing order , now we will do by increasing order
    void merge(int start , int mid , int end , vector<pair<int,int>>&arr , vector<int>&ans ){
        
        vector<pair<int,int>> temp;
        int i = start;
        int j = mid+1;
        int numElemsRightArrayLessThanLeftArray = 0;
        while(i<=mid && j<=end){
            if(arr[i].first <= arr[j].first){
                ans[arr[i].second] += numElemsRightArrayLessThanLeftArray;
                temp.push_back({arr[i].first , arr[i].second});
                i++;
            }
            else{
                temp.push_back({arr[j].first , arr[j].second});
                numElemsRightArrayLessThanLeftArray++;
                j++;
            }
           
        }
        while(i<=mid){
              ans[arr[i].second] += numElemsRightArrayLessThanLeftArray;
              temp.push_back({arr[i].first , arr[i].second});
              i++;
        }
        while(j<=end){
             temp.push_back({arr[j].first , arr[j].second});
                j++;
        }
        
        for(int i=0;i<temp.size();i++){
            arr[i+start].first = temp[i].first;
            arr[i+start].second = temp[i].second;
            
        }
        
    }
        
    void mergeSort(int i, int j , vector<pair<int,int>> &arr , vector<int>&ans){
        if(i>=j)
            return;
        int mid = (i+j)/2;
        mergeSort(i,mid,arr,ans);
        mergeSort(mid+1,j,arr,ans);
        merge(i,mid,j,arr,ans);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
          int n = nums.size();
          vector<pair<int,int>> arr;
          for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
          }
          vector<int > ans(n,0);
          mergeSort(0,n-1,arr,ans);
          return ans;
    }
};