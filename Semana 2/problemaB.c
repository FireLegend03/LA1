#include<stdio.h>
#include<stdlib.h>

int main(){

    int andar=0, andares=0, comandos=0, input=0;

    if(scanf("%d", &andar)!=1) abort();
    if(scanf("%d", &andares)!=1) abort();
    if(scanf("%d", &comandos)!=1) abort();

    while(comandos>0){
        if(scanf("%d", &input)!=1){
            printf("input invalido\n");
        }else{
            if(input==1 || input==-1){
                if(andar+input<0||andar+input>andares){
                    comandos--;
                }else{
                    andar+=input;
                    comandos--;
                }    
            }else{
                printf("input invalido\n");
            }
        }
    }
    printf("%d\n", andar);
    return 0;
}