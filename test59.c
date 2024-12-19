#include<stdio.h>
#include<limits.h>
int atol( char*str){
    char*pstr = str;
    int sign=1;
    long long temp=0;
    if(*pstr=='+')pstr++;
    else if(*pstr=='-') sign=-sign,pstr++;
    while (*pstr)
    {
        if(*pstr==' ');
        else if('0'<=*pstr&&*pstr<='9'){
            temp = *pstr-'0'+temp*10;
            if((temp*sign)>=INT_MAX)return INT_MAX;
            else if((temp*sign)<=INT_MIN)return INT_MIN; 
        }
        else break;
        pstr++;
    }
    return temp*sign;
}
int main(){
    char str[1000]="";
    scanf("%[^\n]",str);
    printf("%d",atol(str));
    return 0;
}