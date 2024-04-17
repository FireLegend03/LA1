#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int vogal(char c){
    char vogais[] = "AEIOUY";
    for(int i = 0; i < 6; i++){
        if(c == vogais[i]) 
        return 1;
    }
    return 0;
}

int contar_frase(char frase[]){
    
    char last_char = frase[0];
    int result = 0, tamanho = 0, falha = 0;

    tamanho = strlen(frase);
    for(int i = 1; i < tamanho; i++){
        falha = 0;
        while(frase[i] != ' ' && i < tamanho){
            char char_atual = frase[i];
            if(vogal(last_char) && vogal(char_atual)) 
            falha++;
            else if(!vogal(last_char) && !vogal(char_atual))
            falha++;
            last_char = char_atual;
            i++;
        }
        if(falha == 0)
        result++;
        i++;
        last_char = frase[i];
    }
    return result; 
}
int find_pos(char frase[], char letra){
    int i = 0, tamanho = strlen(frase);
    for(i = 0; i < tamanho; i++){
        if(frase[i] == letra)
        return i;
    }
    return -1;
}

int main(){

    int casos = 0, i = 0;

    if(scanf("%d", &casos) != 1) abort();
    int resposta[casos + 1];
    for(i = 0; i <= casos; i++){
         char frase[1000] = {0};
         if (fgets(frase, sizeof(frase), stdin) != NULL){;
            int pos_newline = find_pos(frase, '\n');
            frase[pos_newline] = '\0';
            resposta[i] = contar_frase(frase);
         }else{
            i--;
            printf("input invalido\n");
         }
    }
    for(i = 1; i <= casos; i++){
        printf("%d\n", resposta[i]);
    }
    
    return 0;
}