#include<stdio.h>
#include<stdlib.h>

int repete(int lista_atual[], int n, int guiche){
    int cont = 0, r = 0;
    for(int i = 0; i <= n; i++){
        if(lista_atual[i] == guiche) cont++;
    }
    if(cont > 1) r = 1;
    return r;
}
void inicializa_a_zero(int repeticoes[], int num_guiches){
    for(int i = 0; i < num_guiches; i++)
    repeticoes[i] = 0;
}

int main(){

    int n = 0, resultado[1000] = {0}, contador = 0;

    if(scanf("%d", &n) != 1) abort();

    for(int i = 0; i < n; i++){
        int guiche = 0, num_guiches = 0;
        if(scanf("%d", &num_guiches) == 1){
            if(num_guiches <=100 && num_guiches > 1){

                int lista_atual[num_guiches], repeticoes[num_guiches + 1];
                inicializa_a_zero(repeticoes, num_guiches);
                if(scanf("%d", &guiche) == 1){
                    resultado[contador] = guiche;
                    contador++;
                    repeticoes[0] = guiche;

                    for(int n = 0; n < num_guiches; n++){
                        if(scanf("%d", &lista_atual[n]) != 1){
                            printf("input invalido");
                            n--;
                        }
                    }
                    for(int n = 0; n < num_guiches; n++){
                        guiche = lista_atual[guiche - 1];
                        repeticoes[n + 1] = guiche;
                        if(guiche == 0){
                            resultado[contador] = -2;
                            contador += 2;
                            n = num_guiches;
                        }else if(repete(repeticoes, (n + 1), guiche)){
                            resultado[contador] = -1;
                            contador += 2;
                            n = num_guiches;
                        }else{
                            resultado[contador] = guiche;
                            contador++;
                        }
                    }
                }else{
                    printf("inpput invalido");
                    i--;
                }
            }else{
                printf("inpput invalido");
                i--; 
            }
        }else{
            printf("inpput invalido");
            i--;
        }
    }

    contador = 0;
    for(int i = 0; i < n; i++, contador++){
        printf("%d", resultado[contador]);
        contador++;
        while(resultado[contador] != 0){
            if(resultado[contador] == -1){
                printf(" CICLO INFERNAL\n");
                contador++;
            }else if(resultado[contador] == -2){
                printf("\n");
                contador++;
            }else{
                printf(" %d", resultado[contador]);
                contador++;
            }
        }
    }
    
    return 0;
}