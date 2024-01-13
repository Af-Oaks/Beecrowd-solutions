#include <bits/stdc++.h>

using namespace std;

/*
    solucao simples leitor de matriz onde uma variavel x
    mantem registro da ultima posicao na linha anterior onde encontrou 0
    apos isso verificar se a proxima pos na linha de baixo continua 0 e andar o mais
    a direita possivel até encontra um numero diferente de 0
*/

int main(){

    int last_pos=-1,n,m,carry,stop,win =1,actual=0;// n= linha | m = coluna
    scanf("%d %d",&n,&m);
    // possivel resolver sem armazenar numa matriz...

    for(int x=0;x<n;x++){
        stop=1;
        for(int y=0;y<m;y++){
            scanf("%d",&carry);
            if(carry == 0 && stop){
                actual = y+1;
            }
            else{
                stop=0;
            }
            if(!(actual > last_pos) && !stop){
                win =0;
            }
        }

        //printf("x=%d | actual =%d | las_pos =%d || win=%d\n",x,actual,last_pos,win);
        last_pos = actual;

    }
    if(win)
        printf("S\n");
    else{
        printf("N\n");
    }


    return 0;
}