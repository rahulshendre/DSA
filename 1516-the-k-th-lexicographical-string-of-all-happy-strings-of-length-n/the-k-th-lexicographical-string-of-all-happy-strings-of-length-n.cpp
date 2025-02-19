
class Solution {
public:
    vector<string> ans;
    void backtrack( int n,string curr,vector<char> &v,int k)
    {
        if(ans.size()==k)
            return ;
        if(curr.size()==n)
        {
            ans.push_back(curr);
                return;
        }
        for(int i=0;i<3;i++)
        {
            if(curr.size()==0||curr[curr.size()-1]!=v[i])
            {
                curr+=v[i];
                backtrack(n,curr,v,k);
                curr.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) 
    {
        vector<char> v={'a','b','c'};
        backtrack(n,"",v,k);
        if(ans.size()==k)
            return ans.back();
        else
            return "";
        
        
    }
};