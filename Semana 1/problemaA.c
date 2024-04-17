#include<stdio.h>
#include<stdlib.h>
int main(){
    int valor=0,maximo=0,ordem=0,i=1;
    
    while (i<6){
        if (scanf("%d", &valor)==1){
            if(valor>maximo){
                maximo=valor;
                ordem=i;
            }
        }else{
            printf("input inválido");
            abort();
        }    
        i++;
    }
    printf("%d\n", ordem);
    return 0;    
}