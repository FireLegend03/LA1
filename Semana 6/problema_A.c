#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//retorna numero de vezes que char c esta presente no nome
int numRepChar(char c, char nome[]){
    int r = 0;
    for(int i = 0; nome[i] != '\n'; i++){
        if(c == nome[i]) r++;
    }
    return r;
}
//compare_names verifica se nome e anagrama coincidem, usando a numRepChar
int  compare_names(char nome[], char anagrama[]){
    int r = 1;
    for(int i = 0; anagrama[i] != '\n'; i++){    //vai até \n devido ao fgets o ler no fim da string
        if(anagrama[i] != ' '){
            char c = anagrama[i];
            if(numRepChar(c, anagrama) != numRepChar(c, nome)) r = 0; //se uma tiver uma letra diferente num de vezes que a outra r passa a False 
        }
    }
    return r;
}

int main(){

    int N = 0, cont = 0, result[1000] = {0};

    if(scanf("%d\n", &N) != 1) abort();

    for(int i = 0; i < N; i++){
        int candidatos = 0, compativel = 0;
        char nome[101] = {0};
        if(scanf("%d\n", &candidatos) == 1){
            if(fgets(nome, 101, stdin) != NULL){
                
                for(int x = 1; x <= candidatos; x++){
                    char anagrama[101] = {0};
                    
                    if(fgets(anagrama, 101, stdin) != NULL){
                        if(compare_names(nome, anagrama)){
                            result[cont] = x;
                            cont++;
                            compativel++;
                        }
                    }
                }
                //var compativel verifica se algum nome era anagrama, caso nenhum seja assim é guradado -1
                if(compativel == 0){
                    result[cont] = -1;
                    cont++;
                }
                cont++;
            }
        }
    }
    
    cont = 0;
    for(int i = 0; i < N; i++){
        printf("%d", result[cont]);
        cont++;
        while(result[cont] != 0){
            printf(" %d", result[cont]);
            cont++;
        }
        putchar('\n');
        cont++;
    }

    return 0;
}