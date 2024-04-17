#include<stdio.h>
#include<stdlib.h>

int main(){
    
    char jogada_inzel=' ', jogada_cmd=' ';
    int empates=0, pontos_inzel=0, pontos_cmd=0, njogadas=0, pedraI=0, pedraC=0, papelI=0, papelC=0,
    tesouraI=0, tesouraC=0;

    if(scanf("%d", &njogadas)!=1) abort();
    while(njogadas>0){
        if(scanf(" %c%c", &jogada_inzel, &jogada_cmd)!=2) printf("input invalido\n");
        else{
            if(jogada_inzel=='@') pedraI=1;
            if(jogada_inzel=='|') papelI=1;
            if(jogada_inzel=='X') tesouraI=1;
            if(jogada_cmd=='*') pedraC=1;
            if(jogada_cmd=='-') papelC=1;
            if(jogada_cmd=='+') tesouraC=1;

            if(pedraI==0 && pedraC==0 && papelI==0 && papelC==0 && tesouraI==0 && tesouraC==0)
            printf("input invalido\n");
            else{
                if(pedraI==1 && pedraC==1) empates++;
                if(pedraI==1 && papelC==1) pontos_cmd++;
                if(pedraI==1 && tesouraC==1) pontos_inzel++;

                if(papelI==1 && pedraC==1) pontos_inzel++;
                if(papelI==1 && papelC==1) empates++;
                if(papelI==1 && tesouraC==1) pontos_cmd++;

                if(tesouraI==1 && pedraC==1) pontos_cmd++;
                if(tesouraI==1 && papelC==1) pontos_inzel++;
                if(tesouraI==1 && tesouraC==1) empates++;
                pedraI=0, pedraC=0, papelI=0, papelC=0, tesouraI=0, tesouraC=0;
                njogadas--;
            }
        }
    }
    printf("%d %d %d\n", pontos_inzel, pontos_cmd, empates);
    return 0;
}