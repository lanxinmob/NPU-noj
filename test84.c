//绝对差【贪心】
#include<stdio.h>
#include<stdlib.h>

int compare(void const*a,void const*b){
    return *((long long*)a)-*((long long*)b);
}
int main()
{
    int n;
    scanf("%d",&n);
    long long num[n];
    for (int  i = 0; i < n; i++)
    {
     scanf("%lld",&num[i]);
    }
    qsort(num,n,sizeof(long long),compare);
    long long min = num[1]-num[0];
    for (int  i = 1; i < n; i++)
    {
        min = min<num[i+1]-num[i]?min:num[i+1]-num[i];
    }
    printf("%lld",min);
    return 0;
}