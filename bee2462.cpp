#include <bits/stdc++.h>

using namespace std;

/*
    questao ad-hoc
    solução: verificar a diferença das viagens de ida e volta em minutos para conseguir informação se a viagem da volta é no prox dia
    nao deu certo
    problema: como saber se quando a viagem sai de um horario maior q o da chegada, se virou o dia ou se o fuso horario é negativo...

*/

int main(){

    int voo1_initH,voo1_initM,voo1_finalH,voo1_finalM;
    int voo2_initH,voo2_initM,voo2_finalH,voo2_finalM;

    scanf("%d:%d",&voo1_initH,&voo1_initM);//inicio voo1
    scanf("%d:%d",&voo1_finalH,&voo1_finalM);//final voo1

    scanf("%d:%d",&voo2_initH,&voo2_initM);//inicio voo2
    scanf("%d:%d",&voo2_finalH,&voo2_finalM);//final voo2

    int difHvoo1,difHvoo2,fuso=0,tempo=0;
    difHvoo1= (voo1_finalH*60 + voo1_finalM) -(voo1_initH*60 + voo1_initM);
    difHvoo2 = (voo2_finalH*60+voo2_finalM) -(voo2_initH*60 +voo2_initM);
    tempo= (difHvoo1+difHvoo2)/2;
    fuso = (difHvoo1 -tempo)/60;
    recontagem:
    if(tempo<0 && fuso <=0){//caso onde o horario de chegada é menor q o horario de partida com fuso +
        tempo+=720;
        fuso+=12;
    }
    else if(tempo<0 && fuso>0){//caso onde o horario de chegada é menor q o horario de partida com fuso -
        tempo+=720;
        fuso-=12;
    }
    else if(tempo>0 && fuso>12){//caso de ter virado o dia com fuso negativo
        fuso-=24;
    }
    else if(tempo>0 && fuso<-12){//caso de ter virado o dia com fuso positivo
        fuso+=24;
    }
    if(tempo<0){
        goto recontagem;
    }

    printf("%d %d\n",tempo,fuso);

    return 0;
}