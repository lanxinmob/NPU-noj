#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

struct flight{
    char name[100];
    int x,y;
};

double solve(int x1,int y1,int x2,int y2){
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}
int main(){
    int n,min=9999999;
    scanf("%d",&n);
    struct flight a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d",a[i].name,a[i].x,a[i].y);
    }
    char flight1[1000];
    char flight2[1000];
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {   int distance = solve(a[i].x,a[i].y,a[j].x,a[j].y);
            if (distance<min)
            {
                min = distance;
                snprintf(flight1,sizeof(flight1),"%s",a[i].name);
                snprintf(flight2,sizeof(flight2),"%s",a[j].name);
            } 
        }
    }
    printf("%s-%s %.4lf\n",flight1,flight2,min); 
    return 0;
}