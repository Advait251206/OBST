class Solution
{
    static int optimalSearchTree(int keys[],int freq[],int n)
    {
        int[][] dp=new int[n][n];
        int[] sumFreq=new int[n+1];
        for(int i=0;i<n;i++)
        {
            sumFreq[i+1]=sumFreq[i]+freq[i];
        }
        for(int length=1;length<=n;length++)
        {
            for(int i=0;i<=n-length;i++)
            {
                int j=i+length-1;
                dp[i][j]=Integer.MAX_VALUE;
                int sum=sumFreq[j+1]-sumFreq[i];
                for(int r=i;r<=j;r++)
                {
                    int cost=(r>i?dp[i][r-1]:0)+(r<j?dp[r+1][j]:0)+sum;
                    dp[i][j]=Math.min(dp[i][j],cost);
                }
            }
        }
        return dp[0][n-1];
    }
}