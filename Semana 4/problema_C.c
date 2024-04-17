#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int repeat(char frase[], int inicio, int final){
    int result = 0;

    for(int i = inicio; i < inicio + final; i++){
        for(int n = i + 1; n < inicio + final; n++){
            if(frase[i] == frase[n]){
                result = 1;
                i = inicio + final;
                n = inicio + final;
            }
        }
    }
    return result;
}

int main(){

    int n = 0, cont = 0;

    if(scanf("%d", &n) != 1) abort();
    int lista_result[n];

    for(int i = 0; i < n; i++){
        char frase[999] = {0};
        int x = 0, result = -1;
        if(scanf("%d", &x) == 1){
            if(scanf("%s", frase) == 1){
                int tamanho = strlen(frase);
                for(cont = 0; cont <= tamanho - x; cont++){
                    if(!repeat(frase, cont, x)){
                        result = cont;
                        cont = tamanho;
                    }
                }
                lista_result[i] = result;
            }else{
                printf("input invalido\n");
                i--;
            }
        }else{
            printf("input invalido\n");
                i--;
        }
    }
    for(int i = 0; i < n; i++)
    printf("%d\n", lista_result[i]);

    return 0;
}