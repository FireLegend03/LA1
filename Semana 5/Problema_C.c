#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//strcmp returna 0 se forem iguais

//Verifica se nome já pertence a matriz de funcionarios, se pertence retorna a sua posiçao
int pertence_pos(char nome[], char nomes[][21]){
    int r = -1;
    for(int i = 0; i < 40; i++){
        if(strcmp(nomes[i], nome) == 0) r = i;
    }
    return r;
}
//Encontra posiçao de um char numa string, usado para encontrar \n de fgets e depois substituir por \0
int find_pos(char frase[], char letra){
    int i = 0, tamanho = strlen(frase);
    for(i = 0; i < tamanho; i++){
        if(frase[i] == letra)
        return i;
    }
    return -1;
}
//Encontra posiçao de funcionario com menos presenças
int find_baldas(int presencas[]){
    int menor_pres = presencas[0], r = 0;
    for(int i = 0; i < 40; i++){
        if(presencas[i] > 0){ 
            if(presencas[i] < menor_pres){
                menor_pres = presencas[i];
                r = i;
            }
        }
    }
    return r;
}

int main(){
    char nomes[40][21] = {0};
    int presencas[40] = {0}, quantas = 0, dias = 0;
    
    if(scanf("%d\n", &dias) != 1) abort();

    for(int i = 0; i < dias; i++){
        char lista_diaria[1000]={0};
        if(fgets(lista_diaria, sizeof(lista_diaria), stdin) != NULL){
            
            int new_line = find_pos(lista_diaria, '\n');
            lista_diaria[new_line] = '\0';
            int tamanho = strlen(lista_diaria);

            for(int n = 0; lista_diaria[n] != '\0'; n++){
                //Separar os nomes da lista
                char nome[21] = {0};
                for(int x = 0; lista_diaria[n] != ' ' && n < tamanho; x++, n++){
                    nome[x] = lista_diaria[n];    
                }
                //Atualiza matriz de funcionarios caso nao pertença e atualiza o valor da lista de presenças na mesma posiçao
                int pos = pertence_pos(nome, nomes);
                if(pos == -1){
                    strcpy(nomes[quantas], nome);
                    presencas[quantas] += 1;
                    quantas++;
                }else{
                    presencas[pos] += 1;
                }
            }     
        }else{
            printf("input invalido\n");
            i--;
        }
    }
    int r = find_baldas(presencas);
    for(int i = 0; nomes[r][i] != '\0'; i++)
        printf("%c", nomes[r][i]);
    
    putchar('\n');
    return 0;
}