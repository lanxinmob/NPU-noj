//倒水【DFS】
#include<stdio.h>
#include<limits.h>
int n,m,d;
int dp[1000][1000];

void op1(int *a,int *b){
    *a=0;
}
void op2(int *a,int *b){
    *b=0;
}
void op3(int *a,int *b){
    *a=n;
}
void op4(int *a,int *b){
    *b=m;
}
void op5(int *a,int *b){
    int tmp=*a;
    if(*b>0&&*a<n){
    *a=((*a+*b)<n)?*a+*b:n;
    *b=(*b-(*a-tmp)>0)?*b-(*a-tmp):0;
    }
}void op6(int *a,int *b){
    int tmp=*b;
    if(*a>0&&*b<m){
    *b=((*b+*a)<m)?*a+*b:m;
    *a=(*a-(*b-tmp)>0)?*a-(*b-tmp):0;
    }
}
void (*operate[6])(int*,int*)={op1,op2,op3,op4,op5,op6};
void dfs(int a,int b,int sum){
    if(a==d||b==d)
    {dp[a][b]=sum;
    return;
    } 
    for (int c = 0; c < 6; c++)
    {  int new_a=a,new_b=b;
       operate[c](&new_a,&new_b);
       if(dp[new_a][new_b]==-1||dp[new_a][new_b]>sum+1)//此处以及下面的标注处都需要关注的是通过条件约束高效搜索
       {dp[new_a][new_b]=sum+1;                        //或者说减少无效、重复计算不然计算量会特别臃肿
        dfs(new_a,new_b,sum+1);} 
    }
}
int main(){
    scanf("%d %d %d",&n,&m,&d);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = -1;  
        }
    }
    dfs(n,m,0);
    int min = INT_MAX;
    for (int j = 0; j <= n; j++)
    {   for (int b = 0; b <=m ; b++){
        if(dp[j][b]!=-1&&(j==d||b==d)){//见上
        min = (dp[j][b]<min)?dp[j][b]:min;}
        }
    }printf("%d\n",min);
    return 0;
}

















