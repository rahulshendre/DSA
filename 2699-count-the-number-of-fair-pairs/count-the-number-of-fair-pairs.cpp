class Solution 
{
public:
    long long countFairPairs(vector<int>& v, int lower, int upper) 
    {
        // Step 1: Sort the array
        sort(v.begin(), v.end());
        long long ans = 0;

        // Step 2: Loop through each element
        for (int i = 0; i < v.size() - 1; i++) 
        {
            // Step 2.1: Find first index j such that v[i] + v[j] >= lower
            auto low = lower_bound(v.begin() + i + 1, v.end(), lower - v[i]);
        
            // Step 2.2: Find first index j such that v[i] + v[j] > upper
            auto up = upper_bound(v.begin() + i + 1, v.end(), upper - v[i]);
        
            // Step 2.3: Count valid pairs
            ans += up - low;
        }

        // Step 3: Return result
        return ans;
    }
};