#ifndef AVL
#define AVL

typedef struct no no;
typedef struct arv arv;
struct no{
    //Registro de nó com os campos obrigatórios mais o campo alt,que indica a altura do nó
    //na avl.
    int val,id,op,alt;
    struct no* pai;
    struct no* esq;
    struct no* dir;
};

struct arv{
    //Registro da avl com os campos raiz e qtd,que indica a quantidade de nós da arvore;
    no* raiz;
    int qtd;
};

void destroi_arv(arv* a);//Desaloca a árvore.
arv* criar_arv();//Aloca e retorna uma árvore.
void exibir_nivel(arv* a,int i);//Exibe os nós de i-ésimo nível da árvore a.
no* busca(arv* a,int id);//Retorna o nó de chave id na árvore a ou NULL caso não exista tal nó.
void remove_no(arv* a,int id);//Remove o nó com chave id.
void insere(arv* a,int id,int op,int val);//insere na árvore um nó com os parâmetros dados.Caso
//o nó ja exista,suas informações apenas são alteradas.
void crescente(arv* a);//Exibe os nós com ordem crescente de chave.
void decrescente(arv* a);//Exibe os nós com ordem decrescente de chave.
void remove_raiz(arv* a);//Remove e exibe a raiz da árvore. 
int arv_h(arv* a);//Retorna a altura da árvore.
int num_clientes(arv* a);//Retorna a quantidade de nós na árvore

#endif
