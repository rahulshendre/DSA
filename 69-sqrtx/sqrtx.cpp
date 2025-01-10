class Solution {
public:
    int mySqrt(int x) {
        // int a = sqrt(x);

        if(x == 0 || x == 1){
            return x;
        }
        int left = 1, right = x, result =0;
        while(left <= right){
            long long mid = left +(right - left)/ 2;

            if(mid*mid <= x){
                result = mid;
                left = mid + 1;
            }
            else{
                right = mid -1;
            }
        }

        // if (x == 0){
        //     return x;
        // }
        // long long guess  = x;
        // while(guess* guess > x){
        //     guess = (guess + x / guess)/2;
        // }
        return  result;
    }
};