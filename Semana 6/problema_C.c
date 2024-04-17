#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int best_order(int lista_price[], char lista_dificuldade[], int n){
    int r = 1;
    for(int i = 2; i <= n; i++){
        if(lista_price[r] < lista_price[i]) r = i;
        else if(lista_price[r] == lista_price[i]){
            if(lista_dificuldade[r] > lista_dificuldade[i]) r = i;
        }
    }
    return r;
}

int main(){

    int n = 0;

    if(scanf("%d", &n) != 1) abort();

    int lista_price[n + 1], lista_num_pedido[n + 1];
    char lista_dificuldade[n + 1];

    for(int i = 1; i <= n; i++){
        int price = 0, pedido = 0;
        char dificuldade = '\0';
        if(scanf("%d ", &pedido) == 1){
            if(scanf("%c ", &dificuldade) == 1){
                if(scanf("%d", &price) == 1){
                    lista_num_pedido[i] = pedido;
                    lista_dificuldade[i] = dificuldade;
                    lista_price[i] = price;
                }else{
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
    for(int i = 1; i <= n; i++){
        int r = best_order(lista_price, lista_dificuldade, n);
        printf("%d %c %d\n", lista_num_pedido[r], lista_dificuldade[r], lista_price[r]);
        lista_price[r] = 0;
    }

    return 0;
}