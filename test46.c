//完美矩阵
#include<stdio.h>

int arr[300][300]={0};

int isPerfect(int a,int b,int c,int d)
{   
    int flag = 1,n=0,m=0;
    for (size_t i = a; i <= c; i++)
    {
         if(arr[i][b]!=1||arr[i][d]!=1)flag = 0;
    }
    for (size_t i = b; i <= d; i++)
    {
         if (arr[a][i]!=1||arr[c][i]!=1)flag = 0;
    }
    for (size_t i = a+1; i < c; i++){
         for (size_t j = b+1; j < d; j++){
              if (arr[i][j]==0)n++;
              if (arr[i][j]==1)m++;
         }
         
    }
    if ((n-m)*(n-m) > 1)flag = 0;
    if(flag){return 1;}
    else {return 0;}
}

int main()
{
    int n,m,result=0;
    scanf("%d%d",&n,&m);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
             scanf("%d",&arr[i][j]); 
        }
    }
    
    for (size_t upedge = 0; upedge < n; upedge++){
        for (size_t leftedge = 0; leftedge < m; leftedge++){
            for (size_t width = 1; ( width+upedge < n)&&( width+leftedge<m); width++){
                 result+=isPerfect(upedge,leftedge,upedge+width,leftedge+width);
       }
      }  
    }
    printf("%d",result);
    
    return 0;
}