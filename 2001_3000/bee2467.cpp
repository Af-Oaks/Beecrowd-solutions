#include <bits/stdc++.h>

using namespace std;

/*
    se tivermos q resolver essa questão nao podemos usar a estrutura de uma matriz... pois inevitavelmente
    ao modificar uma matriz N vezes de tamanho N estariamos na melhor das hipoteses trabalhando com
    um algoritmo O(N²) e como N<= 10⁵ ... imppossivel.
    deve ter uma forma de abstrair as atribuições de colunas ou linhas de tal forma q nao seja necessário
    implementar a matriz.. assim deixando o algoritmo O(logN) *O(N)entradas passando no limite para N=10⁵

    a maior charada está atualmente ao modificar uma coluna q pode ser criadada ou modificada em O(1) usando
    algumas estruturas de dados, COMO modificar as linhas q tocam essa coluna sem iterar de forma O(N) por cada uma

    descoberto a solução:
    criar sistema de querys onde possamos pegar as respostas prontas em O(log(n)) e modificar a segmente tree em O(log(n))
    --criamos uma arvore binaria balancead
    -- criamos 4 vetores auxiliares para saber qual o valor anteriror da coluna/linha e o valor atual
    -- mantemos noção da ordem de inserção pela variavel iteração
    -- criamos 50 arvores binarias auto-balanceadas relacionada aos valores q podemos inserir na matriz
    -- procuramos nessas 50 arvores, qual elemento mais repete e esse é a resposta.
*/

int ultima_linha[100000], ultima_coluna[100000], atual_linha[100000],
    atual_coluna[100000], iteracao=0;

struct no {
    no *l, *r;
    int size, prior;
    pair<int,int> key;
    no(pair<int,int> key) : key(key), size(1), prior(rand()), l(NULL), r(NULL) {}
};

inline int sz(no* t) {
    if (t == NULL) return 0;
    return t->size;
}
inline void upd_sz(no* t) {
    if (t) t->size = sz(t->l) + 1 + sz(t->r);
}
void split(no* t, pair<int,int> key, no* &l, no* &r) {
    if (t == NULL) {
        l = r = NULL;
    } else if (key  <  t->key) {
        split(t->l, key, l, t->l);
        r = t;
    } else {
        split(t->r, key, t->r, r);
        l = t;
    }
    upd_sz(t);
}
void merge(no* &t, no* l, no* r) {
    if (l == NULL) {
        t = r;
    } else if (r == NULL) {
        t = l;
    } else if (l->prior > r->prior) {
        merge(l->r, l->r, r);
        t = l;
    } else {
        merge(r->l, l, r->l);
        t = r;
    }
    upd_sz(t);
}
void insert(no* &t, pair<int,int> key) {
    no *L, *R;
    no *aux = new no(key);
    split(t, make_pair(key.first, key.second - 1), L, R);
    merge(t, L, aux);
    merge(t, t, R);
}
void erase(no* &t, pair<int,int> key) {
    no *L, *mid, *R;
    split(t, make_pair(key.first, key.second - 1), L, R);
    split(R, key, mid, R);
    merge(t, L, R);
}
int query(no* t, pair<int,int> key) {
    no *L, *R;
    split(t, key, L, R);
    int resp = sz(R);
    merge(t, L, R);
    return resp;
}

no *segtree_linha[51],*segtree_coluna[51];

int main(){

    int tam,quant,range=50;
    scanf("%d %d\n",&tam,&quant);
    for(int x=0;x<=range;x++){
        segtree_coluna[x] = NULL;//crio uma segtree para manter o historico de cada valor possivel q pode ser colocado numa matriz
        segtree_linha[x]  = NULL;
    }
    for(int x=1;x <= tam;x++){
        insert(segtree_coluna[0],{0,x});// insiro a quantidade de linhas e colunas q vao ter na matriz nXn
        insert(segtree_linha[0], {0,x});
    }

    for(int q=0;q<quant;q++){
        int first,sec,third,valor=0;
        iteracao++;
        scanf("%d",&first);
        if(first ==1){//modificar linha SEC com valor THIRD
            scanf("%d %d",&sec,&third);
            erase(segtree_linha[atual_linha[sec]], {ultima_linha[sec],sec});//apago os valores relacionado aquela linha
            atual_linha[sec] = third;//represento o valor atual da linha
            ultima_linha[sec] = iteracao;
            insert(segtree_linha[third],{iteracao,sec});//?????
        }
        else if(first==2){//modifcar coluna SEC com valor THIRD
            scanf("%d %d",&sec,&third);
            erase(segtree_coluna[atual_coluna[sec]], {ultima_coluna[sec],sec});//apago os valores relacionado aquela coluna
            atual_coluna[sec] = third;//represento o valor atual da coluna
            ultima_coluna[sec] = iteracao;
            insert(segtree_coluna[third],{iteracao,sec});//?????
        }
        else if(first==3){//argumento de 2 numeros do tipo imprimir linha sec_arg
            scanf("%d",&sec);
            int atual= atual_linha[sec], ultima = ultima_linha[sec];
            pair<int,int> resp = {-1,-1}, querys = {ultima -1,tam +1};
            valor=0;

            for(int x=0;x<=range;x++){
                if( x == atual ) continue;
                int carry = query(segtree_coluna[x],querys);//faço busca para saber quais valores tem naquela linha
                resp = max(resp,{carry,x});//mantenho um par com quais valores repetem mais
                valor+= carry;
            }
            resp = max(resp,{tam - valor,atual});
            printf("%d\n",resp.second);
        }
        else if(first==4){
            scanf("%d",&sec);
            int atual= atual_coluna[sec], ultima = ultima_coluna[sec];
            pair<int,int> resp = {-1,-1}, querys = {ultima -1,tam +1};
            valor=0;
            for(int x=0;x<=range;x++){
                if( x == atual ) continue;
                int carry = query(segtree_linha[x],querys);//faço busca para saber quais valores tem naquela coluna
                resp = max(resp,{carry,x});//mantenho um par com quais valores repetem mais
                valor+= carry;
            }
            resp = max(resp,{tam - valor,atual});

            printf("%d\n",resp.second);
        }
    }
    return 0;
}