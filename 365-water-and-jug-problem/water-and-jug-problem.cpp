class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        int gcd = __gcd(x,y);
        if(x+y<target)
          return false;
        if(target%gcd==0){
            return true;
        }
        return false;
    }
};