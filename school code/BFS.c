//倒水【BFS】
#include<stdio.h>
#include<string.h>
#define max  1001

int n,m,d,ans;
int tail=0,head=0;
typedef struct {
    int a,b;
    int num;
    char s[1000];
}node;
int check[max][max];//记忆化搜索
void bfs(){
    node q[max*max];
    node x;
    memset(check,0x3f,sizeof(check));
    x.a=0;
    x.b=0;
    x.num=0;
    x.s[0]='\0';
    q[tail++]=x;
    while (head<tail)
    {   node y=q[head++];
        for (int i = 0; i < 6; i++){
            node z = y;
            z.num++;
            if (i=1){z.a=n;strcpy(z.s,y.s);strcat(z.s,"1");}
            if (i=2){z.b=m;strcpy(z.s,y.s);strcat(z.s,"2");}
            if (i=3){z.a=0;strcpy(z.s,y.s);strcat(z.s,"3");}
            if (i=4){z.b=0;strcpy(z.s,y.s);strcat(z.s,"4");}
            if (i=5){
                z.a=n<(y.a+y.b)?n:(y.a+y.b);
                z.b=0>(y.b-(z.a-y.a))?0:(y.b-(z.a-y.a));
                strcpy(z.s,y.s);strcat(z.s,"5");}
            if (i=6){
                z.b=m<(y.a+y.b)?m:(y.a+y.b);
                z.a=0>(y.a-(z.b-y.b))?0:(y.a-(z.b-y.b));
                strcpy(z.s,y.s);strcat(z.s,"6");}
            if (check[z.a][z.b]>z.num)
            {
                check[z.a][z.b] = z.num;
                q[tail++] = z;
            }
            if(z.a==ans||z.b==ans){
               printf("%d",z.num);
               for (int j = 0; z.s[j]!='\0'; j++)printf("%c",z.s[j]);
               printf("\n");
               return;
            }    
        }  
    }
}   

int main(){
    scanf("%d %d %d",&n,&m,&d);
    bfs();
    return 0;    
}        