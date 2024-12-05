//完美矩阵
//第一次尝试后超时，用二维前缀和优化
#include<stdio.h>

int arr[300][300]={0};
int preFixsum[300][300]={0};
//计算前缀
void computepreFixsum(int n,int m)
{
    for (int i = 0; i < n; i++)
    {    for (int j = 0; j < m; j++)
        { preFixsum[i][j]=arr[i][j];    
          if(i>0)preFixsum[i][j] += preFixsum[i-1][j];    
          if(j>0)preFixsum[i][j] += preFixsum[i][j-1];
          if(i>0&&j>0)preFixsum[i][j] -= preFixsum[i-1][j-1];
        }
    }
}
int getones(int a,int b, int c,int d)
{
     return preFixsum[c][d] - (a>0?preFixsum[a-1][d]:0) - (b>0?preFixsum[c][b-1]:0)
     + (a>0&&b>0?preFixsum[a-1][b-1]:0);
}
int isPerfect(int a,int b,int c,int d)
{   
    int flag = 1,n=0,m=0;
    for (int i = a; i <= c; i++)
    {
         if(arr[i][b]!=1||arr[i][d]!=1)return 0;
    }
    for (int i = b; i <= d; i++)
    {
         if (arr[a][i]!=1||arr[c][i]!=1)return 0;
    }
   /*for (int i = a+1; i < c; i++){
         for (int j = b+1; j < d; j++){
              if (arr[i][j]==0)n++;
              if (arr[i][j]==1)m++;
         }     
    }
    if ((n-m)*(n-m) > 1)flag = 0;*/
    int ones = getones(a+1,b+1,c-1,d-1);
    int totalcells = (c-a-1)*(d-b-1);
    int zeros = totalcells - ones;
    if(ones - zeros>1||zeros - ones>1)return 0;
    return 1;
}

int main()
{
    int n,m,result=0;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
             scanf("%d",&arr[i][j]); 
        }
    }
    computepreFixsum(n,m);
     //遍历所有可能矩阵
    for (int upedge = 0; upedge < n; upedge++){
        for (int leftedge = 0; leftedge < m; leftedge++){
            for (int width = 1; ( width+upedge < n)&&( width+leftedge<m); width++){
                 result+=isPerfect(upedge,leftedge,upedge+width,leftedge+width);
       }
      }  
    }
    printf("%d",result);
    
    return 0;
}