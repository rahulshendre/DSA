class Solution {
    bool check(vector<int>& piles, int h, int mid){
        int ans = 0;
        for(int i = 0; i < piles.size(); i++){
            ans += (piles[i] / mid);
            if(piles[i] % mid != 0){
                ans++;
            } 
        }
        return ans <=h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxVal = *max_element(piles.begin(), piles.end());

        if (piles.size() == h)
            return maxVal;

        int low = 1, high = maxVal, ans = maxVal;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hrs = 0;

            for (int pile : piles)
                hrs += (pile + mid - 1) / mid;  

            if (hrs <= h) {         
                ans = mid;
                high = mid - 1;
            } else {                
                low = mid + 1;
            }
        }
        return ans;
    }
};