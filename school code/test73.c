#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

typedef struct 
{
    char name[10];
    int count;
}Atom;

void resolve(const char*str,Atom atoms[],int * atom_count){
    int i = 0;
    while (i<strlen(str))
    {
        char atom_e[10] = "";
        int count = 0;
        if(isupper(str[i])){
            atom_e[0] = str[i++];
        }
        int j = 1;
        while (i<strlen(str)&&islower(str[i]))
        {
            atom_e[j++] = str[i++];
        }
        atom_e[j] = '\0';
        while (i<strlen(str)&&isdigit(str[i]))
        {
            count = count*10+(str[i++]-'0');
        }
        if(count==0){
            count = 1;
        }
        int found = 0;
        for(int j=0;j<*atom_count;j++){
            if(strcmp(atoms[j].name,atom_e)==0)
            {atoms[j].count+=count;
             found = 1;
             break;
            }     
        }
        if(!found){
            strcpy(atoms[*atom_count].name,atom_e);
            atoms[*atom_count].count = count;
            (*atom_count)++;
        }
        
    }
    
}

int compare(const void*a,const void *b){
    return strcmp(((Atom*)a)->name,((Atom*)b)->name);
}

int main(){
    char str[100];
    scanf("%s",str);

    Atom atoms[MAX];
    int atom_count = 0;

    resolve(str,atoms,&atom_count);
    
    qsort(atoms,atom_count,sizeof(Atom),compare);//compare为1交换a、b，为-1不换a、b
    for (int i = 0; i < atom_count; i++)
    {
        printf("%s %d\n",atoms[i].name,atoms[i].count);
    }
    
    return 0;
}