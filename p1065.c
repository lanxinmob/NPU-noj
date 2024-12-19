#include<stdio.h>

struct work
{
    int no[21];
    int time[21];
}element[21];

int main()
{   
    int n=0,m=0,cnt=0,order[500]={0},over[21]={0},finish[21]={0},mac[21][100001]={0};
    scanf("%d %d",&m,&n);
    for (int i = 1; i <= n*m; i++)
    {    scanf("%d",&order[i]);}
    for (int i = 1; i <= n; i++)
     for (int j = 1; j <= m; j++) scanf("%d",&element[i].no[j]);
    for (int i = 1; i <= n; i++)
     for (int j = 1; j <= m; j++) scanf("%d",&element[i].time[j]);
    for (int i = 1; i <= n*m; i++)
    {   over[order[i]]++;
        for (int j = finish[order[i]]+1;; j++)
        {
            if (!mac[element[order[i]].no[over[order[i]]]][j])cnt++;
            else cnt=0;
            if (cnt == element[order[i]].time[over[order[i]]])
            {
                for(int k=j-cnt+1;k<=j;k++)mac[element[order[i]].no[over[order[i]]]][k]=1;
                cnt=0;
                finish[order[i]]=j;
                break;
            }  
        }
    }int ans = finish[1];
    for (int i = 2; i <= n; i++)
    {
        if (finish[i]>ans)
        {
           ans = finish[i]; 
        }     
    }
    printf("%d",ans);
    return 0;
}