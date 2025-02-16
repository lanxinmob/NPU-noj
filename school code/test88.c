//打字机
#include<stdio.h>
#include<string.h>

int main(){
    char str[1000];
    scanf("%s",str);
    int n = strlen(str);
    for (int  i = 0; i < n; i++)
    {   if (str[i]=='m'||str[i]=='w')
        {
            printf("0\n");
            return 0;}
    }
    long long dp[1000];
    dp[0]=1;
    dp[1]=1;
    for (int i = 1; i < n; i++)
    {
        dp[1+i] = dp[i];
        if ((str[i]=='n'&&str[i-1]=='n')||(str[i]=='u'&&str[i-1]=='u'))
        {
            dp[i+1]+=dp[i-1];
        }
    }
    printf("%lld",dp[n]);
    return 0;
}