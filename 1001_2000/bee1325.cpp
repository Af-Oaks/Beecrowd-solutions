#include <bits/stdc++.h>

using namespace std;

bool possivel(char letra,int posicao){

    switch (posicao)
    {
        case 0:
            if(letra == 's' || letra == 'r')
                return true;
            else
                return false;
            break;

        case 1:
            if(letra == 'p' || letra == 'q')
                return true;
            else
                return false;
            break;

        case 2:
            if(letra == 'q' || letra == 'r')
                return true;
            else
                return false;
            break;

        case 3:
            if(letra == 'p' || letra == 's')
                return true;
            else
                return false;
            break;
    }
        return false;
}

string nao_similares(int posicao,string entrada){

    string vizinho = "<none>";
    string auxiliar = entrada;
    int tamanho=entrada.size()-1;
    vector<char> aux_encontrar; aux_encontrar.resize(4);

    switch (entrada[entrada.size()-1])
    {
    case 'p':
        aux_encontrar = {'s','s','q','q'};
        break;
    case 'q':
        aux_encontrar = {'r','r','p','p'};
        break;
    case 's':        
        aux_encontrar = {'p','p','r','r'};
        break;
    case 'r':       
        aux_encontrar = {'q','q','s','s'};
        break;
    }
        //auxiliar[tamanho] = aux_encontrar[posicao];
        while(tamanho > 0){
            if(possivel(entrada[tamanho],posicao)){
                goto desinverte;
            }
            tamanho--;
        }
        if(tamanho == 0)
            return "<none>";

        desinverte:
        while(tamanho < entrada.size()){

            switch (posicao)
            {
            case 0:
                if(auxiliar[tamanho] == 'p')
                    auxiliar[tamanho] = 's';
                if(auxiliar[tamanho] = 'q' )
                    auxiliar[tamanho] = 'r';
                if(auxiliar[tamanho] == 's')
                    auxiliar[tamanho] = 'p';
                if(auxiliar[tamanho] = 'r' )
                    auxiliar[tamanho] = 'q';
                break;
            case 1:
                if(auxiliar[tamanho] == 'p')
                    auxiliar[tamanho] = 's';
                if(auxiliar[tamanho] = 'q' )
                    auxiliar[tamanho] = 'r';
                if(auxiliar[tamanho] == 's')
                    auxiliar[tamanho] = 'p';
                if(auxiliar[tamanho] = 'r' )
                    auxiliar[tamanho] = 'q';
                break;
            case 2:
                if(auxiliar[tamanho] == 'p')
                    auxiliar[tamanho] = 'q';
                if(auxiliar[tamanho] = 'q' )
                    auxiliar[tamanho] = 'p';
                if(auxiliar[tamanho] == 's')
                    auxiliar[tamanho] = 'r';
                if(auxiliar[tamanho] = 'r' )
                    auxiliar[tamanho] = 's';
                break;
            case 3:
                if(auxiliar[tamanho] == 'p')
                    auxiliar[tamanho] = 'q';
                if(auxiliar[tamanho] = 'q' )
                    auxiliar[tamanho] = 'p';
                if(auxiliar[tamanho] == 's')
                    auxiliar[tamanho] = 'r';
                if(auxiliar[tamanho] = 'r' )
                    auxiliar[tamanho] = 's';
                break;

            }
            tamanho++;
        }

        return auxiliar;
}

int main(){

    int num_teste,carry;
    string entrada;
    cin>>num_teste;
    for(int x =0;x<num_teste;x++){
        cin>>entrada;

        int tamanho = entrada.size();
        vector<string> resposta;
        resposta.resize(4);
        resposta[0] = nao_similares(0,entrada);
        resposta[1] = nao_similares(1,entrada);
        resposta[2] = nao_similares(2,entrada);
        resposta[3] = nao_similares(3,entrada);
        printf("\n");
        for(string a : resposta)
            cout<<a<<" ";

    }

    return 0;
}