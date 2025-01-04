#include<stdio.h>
#include<math.h>
int main(){
    double a,b;
    scanf("%lf %lf",&a,&b);
    double result = sqrt(b/a);
    printf("%.4lf",result);
    return 0;
}