//游乐园最长路线【DFS】
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,m;
int map[1000][1000]={0};
int used[1000]={0};
int MAX=0;

int max(int a,int b){
    return a>b?a:b;
}
void dfs(int s,int sum){
    MAX=max(MAX,sum);
    for (int i =1 ; i <=n ; i++)
    {
        if (!used[i]&&map[s][i])
        {
            used[i]=1;
            dfs(i,sum+map[s][i]);
            used[i]=0;
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    int a,b,c;
    memset(map,0,sizeof(map));
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);
        map[a][b]=c;
        map[b][a]=c;
    }
    for(int i=1;i<=n;i++){
        memset(used,0,sizeof(used));
        used[i]=1;
        dfs(i,0);
    }
    printf("%d\n",MAX);
    
    return 0;
}
/*special solution*/
/*int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int length[n+1][n+1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
        {    length[i][j] = 0;}
    }
    for (int i = 0; i < m; i++)
    {   int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        length[b][a] = c; 
        length[a][b] = c; 
    }
    int max = 0;
    for (int i = 1; i <= n ; i++)
    {   int maxs = length[i][1];
        for (int  j = 2; j <= n; j++)
        {
            maxs = (maxs>length[i][j])?maxs:length[i][j];                
        }
        for (int  j = 2; j <= n; j++)
        {
            if (maxs==length[i][j])
            {
                length[j][i] = 0;
            }     
        }
        max+=maxs;
    }
    printf("%d\n",max);
    return 0;
}*/