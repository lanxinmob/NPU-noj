//动态规划
#include<stdio.h>

int path(int m,int n)
{   //对空间优化
    int dp[m];
    for (int i = 0; i < m; i++)
    {
        dp[i] = 1;
    }
    for (int j = 1; j < n; j++)
    {for(int i = 1; i < m; i++)
    {
        dp[i] += dp[i-1]; 
    }
    }
    return dp[m-1];
    /*int dp[m][n];
    for(int i=0;i<m;i++){
        dp[i][0] = 1;
    }
    for (int  i= 0; i < n; i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
    */
}
int main()
{
    int bx,by,px,py;
    scanf("%d%d%d%d",&bx,&by,&px,&py);
    int sum=path(bx,by);
    if (px<1||py<1||px>bx||py>by)
    {
    sum = path(bx,by);
    }else if ((px==1&&py==1)||(px==bx&&py==by)){
    sum = 0;
    }else {sum = path(bx,by)-path(px,py)*path(bx-px+1,by-py+1);
    }
    printf("%d",sum);   
    return 0;
}