//子数组最大和
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int *arr=(int *)calloc(n,sizeof(int));
    int *dp=(int *)calloc(n,sizeof(int));
    for (int i = 0; i < n; i++)
    {scanf("%d",arr[i]);
     dp[i]=arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i]+dp[i-1]>dp[i])
        {
            dp[i]=dp[i]+dp[i+1];
        }  
    }int max=dp[0];
    for (int i = 0; i < n; i++)
    {
        if(dp[i]>max)max=dp[i];
    }
    printf("%d",max);
    return 0;
}