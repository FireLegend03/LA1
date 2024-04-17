#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char isMember(char c, int pos, char frase[]){
    int tamanho = strlen(frase);
    char result = '\0';
    for(int i = pos + 1; i < tamanho; i++){
        if(c == frase[i]) result = c; 
    }
    return result;
}

int main(){

    int n = 0;
    char frase[999]={0};

    if(scanf("%d", &n) != 1) abort();
    char resposta[n];
    for(int i = 0; i < n; i++){
        if(scanf("%s", frase) == 1){
            
            char result = '\0';
            for(int x = 0; result == '\0'; x++){
                result = isMember(frase[x], x, frase);
            }
            resposta[i] = result;
        }else{
            printf("input invalio\n");
            i--;
        }
    }
    for(int i = 0; i < n; i++)
        printf("%c", resposta[i]);
    putchar('\n');
    return 0;
}