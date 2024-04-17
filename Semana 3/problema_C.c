#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    int i=0,x=0,size=0,N=0,maior=0,atual=0,cont=1;

    if(scanf("%d", &N)!=1) abort();
    int result[N];
    while(i<N){
        if(scanf("%d", &size)!=1) printf("input invalido\n");
        else if(scanf("%d", &maior)!=1) printf("input invalido");
        else{
            cont=1;
            for(x=1;x<size;x++){ 
                if(scanf("%d", &atual)!=1);
                else if(atual>maior){
                    maior=atual;
                    cont++;
                }
            }
            result[i]=cont;
            i++;
        }
    }
    for(i=0;i<N;i++){
        printf("%d\n", result[i]);
    }

    return 0;
}