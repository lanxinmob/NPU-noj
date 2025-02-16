#include<stdio.h>
#include<string.h>

int str_endwith(char *,char*);
int main()
{
    char str[100];
    char suffix[100];
    /*fgets(str,100,stdin);//fgets会读取换行符\n
    fgets(suffix,100,stdin);*/
    scanf("%[^\n] %[^\n]", str, suffix);
    int res = str_endwith(str,suffix);
    if(res){
        printf("Yes\n");
    }else{
        printf("No\n");
    } 
    return 0;
}
int str_endwith(char *str,char *suffix)
{   int flag = 1;
    int r = strlen(str);
    int l = strlen(suffix);
    if (l > r) {
        return 0;
    }
    for (int i = 0; i < l; i++)
    {   
        if(str[r]==suffix[l]){
            r--;
            l--;
        }else{
            flag = 0;
        }   
    }  
    return flag;
}