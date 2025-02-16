//三角形【贪心】
#include<stdio.h>
void order(int *a,int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (a[j]>a[j-1])
            {
                int tmp= a[j-1];
                a[j-1] = a[j];
                a[j]= tmp;
            }
               
        }
    }
}
void istriangle(int *a,int n){
    for (int i = 0; i < n-2; i++)
    {
        if (a[i]<a[i+1]+a[i+2])
        {
            printf("%d %d %d\n",a[i],a[i+1],a[i+2]);
            return;
        }      
    }
    printf("-1\n");
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    order(a,n);
    istriangle(a,n);
    return 0;
}