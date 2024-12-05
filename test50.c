//欧拉筛
#include<stdio.h>
#define N 10000000

int vis[N] ={0};
void Euler_sieve(int n)
{   for (int i = 0; i <= n; i++)
    {   vis[i] = i;  
    }
    int i,j;
    for (int i = 2; i <= n; i++)
    {   if (vis[i]==i){
        for ( j = i*2; j<=n ; j+=i)
        {    if (vis[j]==j)vis[j]=i;}
    }
    }
}
int main()
{   
    int n,result=0;
    scanf("%d",&n);
    Euler_sieve(n);
    for (int i = 2; i <= n; i++)
    {
        if(vis[i]==i)result++;
    }
    printf("%d",result);
    return 0;
}
