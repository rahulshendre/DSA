class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        long long ans = LLONG_MIN;
        for (int r = 0; r < k; ++r) {
            long long cur = 0;
            int last = r + ((n - 1 - r) / k) * k;
            for (int i = last; i >= r; i -= k) {
                cur += energy[i];
                ans = max(ans, cur);
            }
        }
        return (int)ans;
    }
};