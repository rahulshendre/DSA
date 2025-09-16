class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stack;
        for (int num : nums) {
            long curr = num;
            while (!stack.empty()) {
                long last = stack.back();
                long g = gcd(last, curr);
                if (g == 1) break;
                curr = lcm(last, curr, g);
                stack.pop_back();
            }
            stack.push_back(curr);
        }
        return stack;
    }
    
    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long lcm(long a, long b, long g) {
        return (a / g) * b;
    }
};