class Solution {
public:
    int countOperations(int num1, int num2) {
        //num 1 and num2 
        //if num1 is greater than the difference b/w 1 and 2 becomes 1 
        //if num2 is greter the the difference becomes num2;
        // right when one of the num becomes 0, we stop 
        long long ops = 0;
        if(num1 == 0 && num2 == 0){
            return 0;
        }
        if (num1 == num2)
             return 1;
        while(num1 != 0 && num2 != 0){
            if(num1 > num2){
                num1 = num1 - num2;
                ops += 1;
            }
            else {
                num2 = num2 - num1;
                ops +=1 ;
            }
        }
        return ops;
        
    }
};