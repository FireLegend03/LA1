#include<stdio.h>
#include<stdlib.h>

int main(){

    int n=0,x=0,y=0,carta=0;

    if(scanf("%d", &n)==0){
        abort();
    }else{
        while(n>0){
            if(scanf("%d", &carta)==1){
                if(carta>0 && carta<79){
                    if(carta==1+4*(carta/4)) y-=1;
                    if(carta==2+4*(carta/4)) y+=1;
                    if(carta==3+4*(carta/4)) x-=1;
                    if(carta==4*(carta/4)) x+=1;
                }else{
                    printf("valor invalido\n");
                }
            }else{
                printf("valor invalido\n");
            }
            n--;
        }
       printf("%d %d\n", x, y); 
    }
    return 0;
}