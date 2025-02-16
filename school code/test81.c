#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int solve(int n,int m,int *bad){
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    for (int i = 0; i < m; i++)
    {
        dp[bad[i]]=-1;
    }
    dp[0]=1;
    if (dp[1]!=-1)dp[1]=1;
    else dp[1]=0;
    for (int i = 2; i <= n; i++)
    {
        if (dp[i]==-1)
        {
            dp[i]=0;
        }else{
            dp[i]=(dp[i-1]+dp[i-2])%1000000007;
        }
    }return dp[n];
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int *bad=(int*)malloc(m*sizeof(int));
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&bad[i]);
    }
    printf("%d\n",solve(n,m,bad));
    return 0;
}