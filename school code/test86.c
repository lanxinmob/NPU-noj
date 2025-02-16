//挑选【动态规划】
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int maxsum(int a,int b){
    return a>b?a:b;
}

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int  i = 0; i < n; i++)scanf("%d",&a[i]);
    int min=INT_MAX,max=INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i]<min)min=a[i];
        if (a[i]>max)max=a[i];
    }
    int range = max-min+1;
    long long *freq=(long long *)calloc(range,sizeof(long long));
    long long *dp=(long long *)calloc(range+1,sizeof(long long));
    long long Max=0;
    for (int i = 0; i < n; i++)freq[a[i]-min]++;
    dp[0]=0;
    dp[1]=min*freq[0];
    for (int i = 2; i <= range; i++)
    {
        dp[i] = maxsum(dp[i-1],dp[i-2]+i*freq[i-1]);
        Max=maxsum(Max,dp[i]);
    }
    printf("%lld",Max);
    free(freq);
    free(dp);
    return 0;
}