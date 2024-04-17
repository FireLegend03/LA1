#include<stdio.h>
#include<stdlib.h>

int main(){
    int alt1=0,alt2=0,alt3=0;

    if (scanf("%d", &alt1)==1){
        if (scanf("%d", &alt2)==1){
            if (scanf("%d", &alt3)==1){
                if((alt1<=alt2 && alt2<=alt3)||(alt1>=alt2 && alt2>=alt3)){
                    printf("OK\n");
                }else{
                    printf("NAO\n");
                }
            }else{
                printf("Input Invalido\n");
            }
        }else{
            printf("Input Invalido\n");
        }
    }else{
        printf("Input Invalido\n");
    }
    return 0;
}