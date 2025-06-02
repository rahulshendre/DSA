class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // intialise with 1 
        vector<int> count(n,1);

        // left to right
        for(int i = 1; i < n; i++){
            if(ratings[i] > ratings[i-1]){
                count[i] = count[i-1] + 1;
            }
        }

        //right to left
        for(int i = n-2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                count[i] = max(count[i], count[i + 1 ] + 1);
            }
        }

        //total 
        return accumulate(count.begin(), count.end(), 0);
    }
};