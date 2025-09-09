class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int arr[n];
        for(int i=0;i<n;i++)
        {
            arr[i]=0;
        }
        int jump=forget-delay;
        arr[0]=1;
        for(int i=0;i<n-1;i++)
        {
            if(arr)
            {
            for(int j=i+delay;j<n and j<i+delay+jump;j++)
            {
                arr[j]=(arr[j]+arr[i])%1000000007;
            }
            
            }
        }
        int ans=0;
        for(int i=n-1;i>=n-forget;i--)
        ans=(ans+arr[i])%1000000007;
        return ans;
    }
};