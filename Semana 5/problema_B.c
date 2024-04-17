#include<stdio.h>
#include<stdlib.h>

int horas_comum(int logs[][101], int hora, int n_agentes){
    int cont = 0, r = 0;
    for(int i = 1; i <= n_agentes; i++){
        cont += logs[hora][i];
    }
    if(cont > 1) r = 1;
    return r;
}
void agentes_comuns(int logs[][101] ,int agentes_suspeitos[], int hora,int n_agentes){
    int cont = 0;
    for(int i = 1; i <= n_agentes; i++){
        if(logs[hora][i] == 1){
            agentes_suspeitos[cont] = i;
            cont++;
        }
    }
}
void inicializa_a_zero(int agentes_suspeitos[], int n_agentes){
    for(int i = 0; i < n_agentes; i++)
    agentes_suspeitos[i] = 0;
}

int main(){

    int n_agentes = 0, n = 0, logs[24][101] = {0};

    if(scanf("%d", &n_agentes) != 1) abort();
    if(scanf("%d", &n) != 1) abort();

    for(int i = 0; i < n; i++){
        int agente = 0, chegada = 0, partida = 0;
        if(scanf("%d", &agente) == 1 && scanf("%d", &chegada) == 1 && scanf("%d", &partida) == 1){
            while(chegada <= partida){
                logs[chegada][agente] = 1;
                chegada++;
            }
        }else{
            printf("Input invalido");
            i--;
        }
    }
    for(int hora = 0; hora < 24; hora++){
        int agentes_suspeitos[n_agentes];
        inicializa_a_zero(agentes_suspeitos, n_agentes);
        if(horas_comum(logs, hora, n_agentes)){
            printf("%d", hora);
            agentes_comuns(logs, agentes_suspeitos, hora, n_agentes);
            for(int i = 0; i < n_agentes; i++){
                if(agentes_suspeitos[i] != 0) printf(" %d", agentes_suspeitos[i]);
            }
            putchar('\n');
        }
    }

    return 0;
}