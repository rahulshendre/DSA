class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = n * (n+1) / 2;
        int divCount = n/m;
        int divSum = m * divCount * (divCount + 1)/2;
        return totalSum - 2 * divSum;
    }
};