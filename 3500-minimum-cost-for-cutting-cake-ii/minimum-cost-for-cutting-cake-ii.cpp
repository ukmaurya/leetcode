#define ll long long 
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
         sort(horizontalCut.begin() , horizontalCut.end() , greater<int>());
          sort(verticalCut.begin() , verticalCut.end() , greater<int>());
          int horPiece = 1;
          int verPiece = 1;
          int hptr = 0;
          int vptr = 0;
          ll total = 0;
          while(hptr<m-1 && vptr<n-1){
              if(horizontalCut[hptr]>verticalCut[vptr]){
                   total += verPiece*horizontalCut[hptr];
                   horPiece++;
                   hptr++;
              }
              else{
                     total += horPiece*verticalCut[vptr];
                     verPiece++;
                     vptr++;
              }
          }
         while(hptr<m-1){
             total += verPiece*horizontalCut[hptr];
             horPiece++;
             hptr++;
         }
         while( vptr<n-1){
            total += horPiece*verticalCut[vptr];
            verPiece++;
            vptr++;
         }
        return total;
    }
};