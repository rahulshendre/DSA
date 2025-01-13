class Solution {
public:
    int minimumLength(string s) {
        if(s.size() < 3){
            return s.size();
        }


        unordered_map<int, int> mpp;

        for(char c : s){
            mpp[c]++;
        }
        int lenght =0;
        for(auto& i : mpp)
        {
            if(i.second < 3 ){
                lenght = lenght + i.second;
            }
            else if(i.second % 2 == 0){
                lenght = lenght + 2;
            }
            else{
                lenght = lenght + 1;
            }
        }
        return lenght;
    }
};