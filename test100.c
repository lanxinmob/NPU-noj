#include<stdio.h>

int main(){
    int n,sign=1;
    double sum = 3.0;
    scanf("%d",&n);
    for (int i = 2; i <=(n-1)*2; i+=2)
    {
        sum+=4.0/(double)(i*(i+1)*(i+2))*sign;
        sign=-sign;
    }
    if (n>700)
    {
        sum=3.1415927;
    }

    printf("%.7lf",sum);
    return 0;
}