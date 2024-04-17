#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char msg[1000]={0}, pos[8]={0};
    int tamanho_msg=0, tamanho_pos=0, cont=0;

    if(scanf("%s", pos) != 1) abort();
    if(scanf("%s", msg) != 1) abort();

    tamanho_msg=strlen(msg);
    tamanho_pos=strlen(pos);
    char result[tamanho_msg];

    for(int i = 0; i < tamanho_pos; i++){
        int inicio = pos[i] - '1';
        for(int n = inicio; n < tamanho_msg; n += tamanho_pos){
            result[cont] = msg[n];
            cont++;
        }
    }
    for(int i = 0; i < tamanho_msg; i++){
        printf("%c", result[i]);
    }
    printf("%d", tamanho_msg);
}