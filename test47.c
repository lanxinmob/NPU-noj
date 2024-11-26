#include<stdio.h>

int detect10(int i)
{   int n=0,org = i; 
    while(i){
    n++;i/=10;     
    }
    int a[n+1],flag = 1;
    while(org){
    int t=0;a[t]=org%10;org/=10;t++;    
    }
    for (size_t i = 0; i <= n-i-1; i++)
    {  
        if (a[i]!=a[n-i-1])
        {flag=0;}   
    }
    if(flag){return 1;}
    else {return 0;}
}
void decimalTok(int n) {
    if (n > 1)
    decimalTok(n / 2);
    return n % 2;  
}
int detetk(int i,int k)
{   
    int n=0,org = decimalTok(i); 
    while(i){
    n++;i/=10;     
    }
    int a[n+1],flag = 1;
    while(org){
    int t=0;a[t]=org%k;org/=k;t++;    
    }
    for (size_t i = 0; i <= n-i-1; i++)
    {  
        if (a[i]!=a[n-i-1])
        {flag=0;}   
    }
    if(flag){return 1;}
    else {return 0;}
}
int main()
{   
    int n,k,result=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        if(detetk(i,k)==1&&detect10(i)==1)result+=i;
    }  
    printf("%d",result);
    return 0;
}
