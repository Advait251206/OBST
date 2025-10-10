#include <stdio.h>
#define MAX 100
#define INF 999999.0
int main()
{
    int n=4;
    int keys[]={0,10,20,30,40};
    double p[]={0,0.1,0.2,0.4,0.3};
    double q[]={0.05,0.1,0.05,0.05,0.1};
    double e[MAX+1][MAX+1],w[MAX+1][MAX+1];
    for(int i=1;i<=n+1;i++)
    {
        e[i][i-1]=q[i-1];
        w[i][i-1]=q[i-1];
    }
    for(int l=1;l<=n;l++)
    {
        for(int i=1;i<=n-l+1;i++)
        {
            int j=i+l-1;
            e[i][j]=INF;
            w[i][j]=w[i][j-1]+p[j]+q[j];
            for(int r=i;r<=j;r++)
            {
                double t=e[i][r-1]+e[r+1][j]+w[i][j];
                if(t<e[i][j])
                {
                    e[i][j]=t;
                }
            }
        }
    }
    printf("Minimum expected cost = %.4lf\n",e[1][n]);
}