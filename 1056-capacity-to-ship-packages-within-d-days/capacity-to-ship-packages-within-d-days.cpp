class Solution {
    bool check(vector<int>& weights, int mid, int days){
        int sum = 0;
        int daysNeeded = 1;
        for(int i = 0; i < weights.size(); i++){
            if(sum + weights[i] > mid){
                daysNeeded++;
                sum = weights[i];
            }
            else{
                sum+=weights[i];
            }
        }
        //daysNeeded should never cross the days
        return daysNeeded <= days; 
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //write a function which checks, capacity and does the calculation 
        int maxVal = *max_element(weights.begin(), weights.end());

        int total = 0;
        for(int i = 0; i < weights.size(); i++){
            total += weights[i];
        }
        int low = maxVal;
        int high = total;

        while(low <= high){
            int mid = (low + high) >> 1;
            if(check(weights, mid, days)){
                high = mid - 1;
            }
            else{
                low = mid +1;
            }
            
        }
        return low;

    }
};