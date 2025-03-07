// class Solution {

//     bool isPrime(int number){
//         if(number < 2) return false;
//         for(int i = 2; i <= sqrt(number); i++){
//             if(number % 2 == 0) return false;
//         }
//         return true;
//     }
// public:
//     vector<int> closestPrimes(int left, int right) {
//         vector<int> prime;
//         // vector<int> diff;

//         for(int i = left; i <= right; i++){
//             if(isPrime(i)){
//                 prime.push_back(i);
//             }
//         }
//         // return prime;
//         if(prime.size() < 2){
//             return {-1,-1};
//         }
//         if(prime.size() == 2){
//             return prime;
//         }
//         int size = prime.size();
//         vector<int> diff(size-1);
//         int difference = INT_MAX,idx=-1;
//         for(int i = 0; i <diff.size(); i++){
//             diff[i]=prime[i+1]-prime[i];
//             if(difference>diff[i]){
//                 difference=diff[i];
//                 idx=i;
//             }
//         }
        
//         return diff;

//     }
// };


class Solution {
    // Helper function to check if a number is prime
    bool isPrime(int number) {
        if (number < 2) return false;
        for (int i = 2; i <= sqrt(number); i++) {
            if (number % i == 0) return false;
        }
        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;

        // Collect all prime numbers in the range [left, right]
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                prime.push_back(i);
            }
        }

        // If less than 2 primes, return [-1, -1]
        if (prime.size() < 2) {
            return {-1, -1};
        }

        // Find the closest pair
        int minDifference = INT_MAX, idx = -1;
        for (int i = 0; i < prime.size() - 1; i++) {
            int diff = prime[i + 1] - prime[i];
            if (diff < minDifference) {
                minDifference = diff;
                idx = i;
            }
        }

        // Return the closest pair of primes
        return {prime[idx], prime[idx + 1]};
    }
};
