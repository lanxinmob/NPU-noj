//危险的组合【DFS】
#include<stdio.h>

int n;
int num;
int a[30];

void dfs(int i,int flag){
    if(i==n)
    {   if(flag>=1)num++;
        return;
    }
    for (int j = 0; j < 2; j++)
    {
        a[i]=j;
        if (i>=2&&a[i]==a[i-1]&&a[i-1]==a[i-2]&&a[i]==1)
        {
            dfs(i+1,flag+1);
        }else dfs(i+1,flag);    
    }   
}
int main()
{
    while (1)
    { 
    num=0;   
    scanf("%d",&n);
    if(n<=0)break;
    dfs(0,0);
    printf("%d",num);
    } 
    return 0;
}