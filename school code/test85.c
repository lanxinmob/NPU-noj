//汤包【贪心】
#include<stdio.h>
#include<stdlib.h>

typedef struct 
    {
        int start;
        int time;
        int end;
        int order;
    }dish;
int compare(void const*a,void const*b)
{
    return ((dish*)a)->end - ((dish*)b)->end;
}
int main()
{
    int n;
    scanf("%d",&n);
    dish a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d",&a[i].start,&a[i].time);
        a[i].end = a[i].start + a[i].time;
        a[i].order = i+1;
    }
    qsort(a,n,sizeof(dish),compare);
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i].order);
    }
    return 0;
}