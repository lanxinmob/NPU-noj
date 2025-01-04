#include<stdio.h>

int ackman(int a,int b){
    if(a==0)return b+1;
    if(b==0)return ackman(a-1,1);
    return ackman(a-1,ackman(a,b-1));
}
int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    int result = ackman(m,n);
    printf("%d\n",result);
    return 0;
}