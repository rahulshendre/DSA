class Solution {
public:
    int mySqrt(int x) {
        //int a = sqrt(x);

        if(x == 0 || x == 1 ) return x;

        int left = 1;
        int right = x - 1;

        while(left <= right){
            int mid = left +(right - left) /2;

            if((long long) mid*mid < x ){
                left = mid + 1;
            }
            else if((long long)mid*mid > x){
                right = mid - 1;
            }
            else{
                return mid ;
            }
        }
        return right;
    }
};