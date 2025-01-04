#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[4]={10,5,2,1};
    int b[4];
    for (int i = 0; i < 4; i++)
    {
        b[i]=n/a[i];
        if(b[i]!=0){
            n%=a[i];
        }
    }
    for (int i = 3; i>=0; i++)
    {
        if(b[i]!=0){
            printf("%d=%d",a[i],b[i]);
        }
    }
    
    
    return 0;
}