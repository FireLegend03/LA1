#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//abs() verifica diferença de dois inteiros

int primeiro_alfabetico(char nomeI[], char nomeR[]){
    int r = -1;
    for(int i = 0; nomeR[i] !='\0' && nomeI[i] != '\0' && i < 20; i++){
        if(nomeR[i] < nomeI[i]){
            r = 0;
            i = 20;
        }else if(nomeR[i] > nomeI[i]){
            r = 1;
            i = 20;
        }
    }
    if(r == -1){
        if(strlen(nomeR) > strlen(nomeI))
        r = 1;
        else
        r = 0;
        
    }
    return r;
}

int melhor_candidato(char nomes[100][20], int lista_pesos[], int lista_alturas[], int n){
    int r = 0;
    for(int i = 1; i < n; i++){
        if(abs(lista_pesos[r] - 90) > abs(lista_pesos[i] - 90))
        r = i;
        else if(abs(lista_pesos[r] - 90) == abs(lista_pesos[i] - 90)){
            
            if(lista_alturas[r] < lista_alturas[i]) r = i;
            else if(lista_alturas[r] == lista_alturas[i]){
                if(primeiro_alfabetico(nomes[i], nomes[r]))
                r = i;
            }
        }
    }
    return r;
}

int main(){

    int n = 0;
    char nomes[100][20] = {0};

    if(scanf("%d", &n) != 1) abort();
    getchar();
    int lista_pesos[n], lista_alturas[n];

    for(int i = 0; i < n; i++){
        if(scanf("%s", nomes[i]) == 1){
            if(scanf("%d", &lista_pesos[i]) == 1){
                if(scanf("%d", &lista_alturas[i]) != 1){
                    printf("input invalido\n");
                    i--;
                }
            }else{
                printf("input invalido\n");
                i--;
            }
        }else{
            printf("input invalido\n");
            i--;
        }
    }
    for(int i = 0; i < n; i++){
        int r = melhor_candidato(nomes, lista_pesos, lista_alturas, n);
        printf("%s %d %d\n", nomes[r], lista_pesos[r], lista_alturas[r]);
        lista_pesos[r] = 300;
    }

    return 0;
}