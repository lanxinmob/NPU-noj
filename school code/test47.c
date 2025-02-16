//回文数之和
#include<stdio.h>

int detect10(int i)
{
    int original = i,reversed = 0;
    while(i > 0){
        reversed = reversed*10 + i%10;
        i/=10;
    }
    if(original == reversed){
        return 1;
    }
}
int decimalTok(int i,int k)
{   
    int t=1,result=0;
    while(i){
        result += i%k*t;  
        t*=10;
        i/=k;
    }
    return result;  
}
int detectk(int i,int k)
{
    int basek = decimalTok(i,k);
    return detect10(basek); 
}
int main()
{
    int n,k,result=0;
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i++)
    {   if(detect10(i)==1&&detectk(i,k)==1)
        result += i;
    }
    printf("%d\n",result);
    return 0;
}



/*第一版太繁琐 应该直接将数字反转来判断回文数
#include<stdio.h>

int detect10(int i)
{   int n=0,org = i; 
    while(i)
    {
     n++;
     i/=10;     
    }
    int a[n],t=0;
    while(org)
    {
     a[t++]=org%10;
     org/=10;   
    }
    for (int i = 0; i < n/2; i++)
    {  
        if (a[i]!=a[n-i-1])
        {return 0;}   
    }
    return 1;
}
int decimalTok(int n,int k) {
    if (n == 0)
    {return 0;}
    int result,t=1;
    while(n){ 
        result += n%k*t;
        n/=k;
        t*=10; 
    }
    return result;  
}
int detectk(int i,int k)
{   
    int n=0,org = decimalTok(i,k),orj = decimalTok(i,k); 
    while(org){
    n++;
    org/=10;     
    }
    int a[n],t=0;
    while(orj){
    a[t++]=orj%10;
    orj/=10;    
    }
    for (int i = 0; i < n/2; i++)
    {  
        if (a[i]!=a[n-i-1])
        {return 0;}   
    }
    return 1;
}
int main()
{   
    int n,k,result=0;
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        if(detectk(i,k)==1&&detect10(i)==1)result+=i;
    }  
    printf("%d\n",result);
    return 0;
}
*/