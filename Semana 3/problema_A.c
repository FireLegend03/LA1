#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    char pos[8]={0},mens[1000]={0}, result[1000] = {0};
    int tam_ordem=0, tam_msg=0, x = 0;

    if(scanf("%s", pos)!=1) abort();
    if(scanf("%s", mens)!=1) abort();

    tam_ordem=strlen(pos);
    tam_msg=strlen(mens);
    //repetir ciclo o numero de posiçoes em pos
    for(int i = 0; i < tam_ordem; i++){
        //armazenar posiçao inicial da sequencia n + inicio
        //-1 tem que ser efetuado pois o primeiro char começa em 0
        int inicio = pos[i] - '1';
        //efetuar sequencia, salta de casa em casa consuante o maior numero de pos
        for(int n = inicio; n < tam_msg;n += tam_ordem, x++){
            result[x] = mens[n];
        }
    }
    printf("%s\n", result);
    return 0;
}