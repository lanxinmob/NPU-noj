#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(char *str,int l){
    for (int i = 0; i < l/2 ; i++)
    {
        char tmp = str[i];
        str[i] = str[l/2-1-i];
        str[l/2-1-i] = tmp;
    }   
}
int compare(const void*a,const void*b){
    return (*(char*)b-*(char*)a);
}
int main()
{
    char str[1000],left[500],right[500];
    scanf("%[^\n]",str);
    int l =strlen(str);
    for (int i = 0; i < l/2; i++)
    {
        left[i] = str[i];
        right[i] = str[l-i-1];
    }
    left[l / 2] = '\0';right[l / 2] = '\0';              
    qsort(left,strlen(left),sizeof(char),compare);
    swap(right,l);
    if(l%2==0){
    printf("%s%s",left,right);
    }else {
        printf("%s%c%s",left,str[l/2],right);
    }
    return 0;
}