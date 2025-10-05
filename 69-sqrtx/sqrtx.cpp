#include <cmath>

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1){
            return x;
        }

        int start = 1;
        int end = x;
        int mid = -1;

        while(start <= end){
            mid = start + ( end - start) / 2;
            if((long long)mid*mid > x) {
                end = mid -1;
            }
            else if((long long )mid*mid < x){
                start = mid + 1;
            }
            else{
                return mid;
            }
        }
        return end;
    }
};