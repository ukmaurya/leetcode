class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
         
         
             //O(n+m) time
         if(n==0)
             return;
          int index = nums1.size()-1;
          int first = m-1;
          int sec = n-1;
          while(first>=0 && sec>=0){
              if(nums1[first]>=nums2[sec]){
                  nums1[index]=nums1[first];
                  first--;
                  index--;
                  
              }
              else{
                  nums1[index]=nums2[sec];
                  index--;
                  sec--;
              }
          }
        while(sec>=0){
            nums1[index]= nums2[sec];
            index--;
            sec--;
        }
        return;
    }
};