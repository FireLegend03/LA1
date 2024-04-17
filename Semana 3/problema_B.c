#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){

    int N=0,i=0,x=0,tamanho=0,pos=5,result[20]={0};
    char comandos[20]={'\0'};

    if(scanf("%d", &N)!=1) abort();
    for(i=0;i<N;i++){
        if(scanf("%s", comandos)==1){
            tamanho=strlen(comandos);
            for(x=0;x<tamanho;x++){
                switch(comandos[x]){
                    case 'C':
                    if(pos!=7 && pos!=8 && pos!=9) pos+=3;
                    break;
                    case 'B':
                    if(pos!=1 && pos!=2 && pos!=3) pos-=3;
                    break;
                    case 'E':
                    if(pos!=7 && pos!=4 && pos!=1) pos-=1;
                    break;
                    case 'D':
                    if(pos!=9 && pos!=6 && pos!=3) pos+=1;
                    break;
                }
            }
            result[i]=pos;
        }else printf("input invalido\n");
    }
    for(i=0;i<N;i++) printf("%d", result[i]);
    putchar('\n');

    return 0;
}