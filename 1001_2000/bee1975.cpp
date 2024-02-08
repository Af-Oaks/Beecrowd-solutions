#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){

    int n_perolas,alunos,quant;

    string carry,aluno;
    while(cin>>n_perolas>>alunos>>quant){
        if(n_perolas == 0 && alunos ==0 & quant ==0)
            break;
        getline(cin,carry);
        set<string> perolas;
        set<string> mais_erros;
        set<string> classe;
        for(int x=0;x<n_perolas;x++){
            getline(cin,carry);
            perolas.insert(carry);
        }
        int atual=0,maior=0;
        for(int x=0;x<alunos;x++){
            atual=0;
            getline(cin,aluno);
            classe.insert(aluno);
            for(int y=0;y<quant;y++){
                getline(cin,carry);
                if(perolas.count(carry)==1){
                    atual++;
                }
            }
            if(atual>maior){
                set<string> troca;
                troca.insert(aluno);
                maior = atual;
                mais_erros = troca;
            }
            else if( atual == maior && atual >0){
                mais_erros.insert(aluno);
            }
        }
        string resp;
        for(auto a : mais_erros){
            resp.append(a+", ");
        }
        if(resp.size()>0){
            resp.pop_back();
            resp.pop_back();
            resp.push_back('\n');
        }
        else{
            for(auto a : classe)
                resp.append(a+", ");
            resp.pop_back();
            resp.pop_back();
            resp.push_back('\n');
        } 

        cout<<resp;
    }
    return 0;
}