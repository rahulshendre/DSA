class Solution {
    private:
    int gcdBoth(int a, int b){

        if( a== 0) return b;
        if( b== 0) return a;

        while(a!=b){
            if(a>b){
                a = a-b;
            }
            else{
                b = b -a;
            }
        }
        return a;

    }
public:
    string gcdOfStrings(string str1, string str2) {
        

        if(str1+ str2 != str2 + str1) return "";

        int n = str1.size();
        int m = str2.size();

        int lenGcd = gcdBoth(n,m);
        return str1.substr(0, lenGcd);
    }
};