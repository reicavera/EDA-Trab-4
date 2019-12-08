#ifndef AVL
#define AVL
#include<stdio.h>
#include<stdlib.h>
#include "avl.h"

struct no{
	//Registro de nó com os campos obrigatórios mais o campo alt,que indica a altura do nó
	//na avl.  
	int val,id,op,alt;
	struct no* pai;
	struct no* esq;
	struct no* dir;
};
typedef struct no no;
struct arv{
	//Registro da avl com os campos raiz e qtd,que indica a quantidade de nós da arvore;
	no* raiz;
	int qtd;
};
typedef struct arv arv;
exibir_nivel(arv* a,int i);//Exibe os nós de i-ésimo nível da árvore a.
busca(arv* a,int id);//Retorna o nó de chave id na árvore a ou NULL caso não exista tal nó.
remove_no(arv* a,int id);//Remove o nó com chave id.
insere(arv* a,int id,int op,int val);//insere na árvore um nó com os parâmetros dados.Caso
//o nó ja exista,suas informações apenas são alteradas.
crescente(arv* a);//Exibe os nós com ordem crescente de chave.
decrescente(arv* a);//Exibe os nós com ordem decrescente de chave.
remove_raiz(arv* a);//Remove e exibe a raiz da árvore. 
arv_h(arv* a);//Retorna a altura da árvore.

#endif
