#include <stdio.h>
#include <limits.h>
#define MAX 1000


int main(void){
    int temp[MAX];
    int n;
    int i;
    double media;
    int maior_temp, dia_maior_temp;
    int menor_temp, dia_menor_temp;
    printf("Entre a quantidade de dias: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Entre a temperatuda do dia %d: ",i);
        scanf("%d",&temp[i]);
    }

    media = 0.0;
    for(i=0;i<n;i++){
        media += temp[i];
    }
    media /= n;

    printf("Dias em que a temperatura foi maior ou igual a media\n");
    for(i=0;i<n;i++){
        if(temp[i]>=media){
            printf("Dia %d\n",i);
        }
    }
    return 0;
}
