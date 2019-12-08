#include<stdio.h>
#include <stdlib.h>
#include"avl.h"

	no* criar_no(int id){
		//Aloca um nó com os parametros zerados e o retorna.
		no* aux=malloc(sizeof(no));
		if(aux==NULL)
			return NULL;
		aux->pai=NULL;
		aux->esq=NULL;
		aux->dir=NULL;
		aux->id=id;
		aux->op=0;
		aux->val=0;
		return aux;
		}
	arv* criar_arv(){
		//Aloca uma arvore com os parametros zerados e o retorna.
		arv* aux=malloc(sizeof(arv));
		if(aux==NULL)
			return NULL;
		aux->raiz=NULL;
		aux->qtd=0;
		return aux;
	}
	void destroi_no(no* n){
		//Desaloca o nó n.
		free(n);
	}
	void destroi_arv(arv* a){
		free(a);
	}
	int num_clientes(arv* a){
		//Retorna a quantidade de nós na árvore.
		return a->qtd;
	}
	no* insere_busca(arv* a,no* n,no* frente,no* fundo){
		//Faz a inserção propriamente dita:se o id já esteja na árvore,destrói o nó n e 
		//retorna o nó com o mesmo id.Caso contrário insere n na arvore e o retorna.
		if(frente==NULL){
			a->qtd++;
			if(fundo==NULL)
				a->raiz=n;
			else{
				n->pai=fundo;
				if(n->id>fundo->id)
					fundo->dir=n;
				else
					fundo->esq=n;
			}
			return n;
		}
		else{
			if(frente->id==n->id){
				destroi_no(n);
				return frente;

			}
			fundo=frente;
			if(frente->id<n->id)
				frente=frente->dir;
			else
				frente=frente->esq;
			return insere_busca(a,n,frente,fundo);
		}
	}
	int arv_h(arv* a){
		//Retorna a altura da arvore
		if(a->raiz==NULL)
			return 0;
		return a->raiz->alt;
	}
	void buscar_nivel(no* n,int i,int j){
		//Faz a busca e exibe o id dos nós do nível j.
		if(n!=NULL){
			if(i==j)
				printf("%d\n",n->id);
			else{
				buscar_nivel(n->esq,i+1,j);
				buscar_nivel(n->dir,i+1,j);
			}
		}
	}
	void exibir_nivel(arv* a,int i){
		buscar_nivel(a->raiz,1,i);
	}
	void in_ordem_c(no* n){
		//Faz a impressão em ordem crescente de id.
		if(n!=NULL){
			in_ordem_c(n->esq);
			printf("%d %d %d\n",n->id,n->op,n->val);
			in_ordem_c(n->dir);
		}
	}
	void in_ordem_d(no* n){
		//Faz a impressão em ordem decrescente de id.
		if(n!=NULL){
			in_ordem_d(n->dir);
			printf("%d %d %d\n",n->id,n->op,n->val);
			in_ordem_d(n->esq);
		}
	}
	void crescente(arv* a){
		//Chama a busca em ordem crescente.
		in_ordem_c(a->raiz);
	}
	void decrescente(arv* a){
		//Chama a busca em ordem decrescente.
		in_ordem_d(a->raiz);
	}
	no* busca(arv* a,int id){
		//Função que procura se existe um nó com o id especificado.
		//Retorna o nó se o nó com esse id está na árvore e NULL caso contrário.
		no* aux=a->raiz;
		while(aux!=NULL && aux->id!=id){
			if (aux->id<id)
				aux=aux->dir;
			else
				aux=aux->esq;
		}
		return aux;
	}
	void recalcular_altura(no* n){
		//Calcula a altura do nó baseado na altura dos filhos.
		if(n!=NULL){
		int c=1;
		if(n->esq!=NULL)
			c=n->esq->alt+1;
		if(n->dir!=NULL && c<n->dir->alt+1)
			c=n->dir->alt+1;
		n->alt=c;
		}
	}
	int balanceamento(no* n){
		//Retorna o balanceamento do nó na altura dos filhos.
		if(n==NULL)
			return 0;
		int c=0;
		if(n->esq!=NULL)
			c+=n->esq->alt;
		if(n->dir!=NULL)
			c-=n->dir->alt;
		return c;
	}
	void rot_s_direita(arv* a,no* n){
		//Realiza uma rotação simples à direita.
		no* aux=n->esq->dir;
		no* aux2=n->esq;
		aux2->pai=n->pai;
		if(aux!=NULL)
			aux->pai=n;
		if(n->pai!=NULL){
			if(n->pai->esq==n)
				n->pai->esq=aux2;
			else
				n->pai->dir=aux2;
		}
		else
			a->raiz=aux2;
		n->esq=aux;
		n->pai=aux2;
		aux2->dir=n;
		recalcular_altura(n);
		recalcular_altura(aux2);
	}
	void rot_s_esquerda(arv* a,no* n){
		//Realiza uma rotação simples à esquerda.
		no* aux=n->dir->esq;
		no* aux2=n->dir;
		if(aux!=NULL)
			aux->pai=n;
		aux2->pai=n->pai;
		if(n->pai!=NULL){
			if(n->pai->esq==n)
				n->pai->esq=aux2;
			else
				n->pai->dir=aux2;
		}
		else
			a->raiz=aux2;
		n->dir=aux;
		n->pai=aux2;
		aux2->esq=n;
		recalcular_altura(n);
		recalcular_altura(aux2);
	}
	void rot_d_direita(arv* a,no* n){
		//Realiza uma rotação dupla à direita.
		no* aux1=n->esq->dir->esq;
		no* aux2=n->esq->dir->dir;
		no* x=n->esq;
		no* y=n->esq->dir;
		if(aux1!=NULL)
			aux1->pai=x;
		if(aux2!=NULL)
			aux2->pai=n;
		y->pai=n->pai;
		if(n->pai!=NULL){
			if(n->pai->esq==n)
				n->pai->esq=y;
			else
				n->pai->dir=y;
		}
		else
			a->raiz=y;
		x->dir=aux1;
		n->esq=aux2;
		y->esq=x;
		y->dir=n;
		x->pai=y;
		n->pai=y;
		recalcular_altura(n);
		recalcular_altura(x);
		recalcular_altura(y);
	}
	void rot_d_esquerda(arv* a,no* n){
		//Realiza uma rotação dupla à esquerda.
		no* aux1=n->dir->esq->dir;
		no* aux2=n->dir->esq->esq;
		no* x=n->dir;
		no* y=n->dir->esq;
		if(aux1!=NULL)
			aux1->pai=x;
		if(aux2!=NULL)
			aux2->pai=n;
		y->pai=n->pai;
		if(n->pai!=NULL){
			if(n->pai->esq==n)
				n->pai->esq=y;
			else
				n->pai->dir=y;
		}
		else
			a->raiz=y;
		x->esq=aux1;
		n->dir=aux2;
		y->dir=x;
		y->esq=n;
		x->pai=y;
		n->pai=y;
		recalcular_altura(n);
		recalcular_altura(x);
		recalcular_altura(y);
	}
	void rebalancear(arv* a,no* n){
		//Verifica se o nó está balanceado.Se não,aplica a rotação adequada ao
		//tipo de desbalanceamento.
		int c=balanceamento(n);
		if(c==2 || c==-2){
			if(c==2){
				if(balanceamento(n->esq)==-1)
					rot_d_direita(a,n);
				else
					rot_s_direita(a,n);
			}
			else
				if(balanceamento(n->esq)==1)
					rot_d_esquerda(a,n);
				else
					rot_s_esquerda(a,n);
		}
	}
	no* arv_raiz(arv* a){
		//Retorna a raiz da avl
		return a->raiz;
	}
	void insere(arv* a,int id,int op,int val){
		//Chama a função para inserir o nó com o id especificado e altera
		//o nó baseado na entrada,além de verificar se em algum lugar da avl
		//a inserção causou um desbalanceamento.
		no* n=criar_no(id);
		n=insere_busca(a,n,a->raiz,NULL);
		n->op++;
		if(op==1)
			n->val-=val;
		else
			n->val+=val;
		while(n!=NULL){
			recalcular_altura(n);
			rebalancear(a,n);
			n=n->pai;
		}
	}
	void transplante(no* n,no* aux){
		//Coloca as informações do nó aux em n.
		n->id=aux->id;
		n->val=aux->val;
		n->op=aux->op;
	}
	no* removendo_no(arv* a,no* n){
		//Faz a remoção propriamente dita e retorna e retorna o nó retirado da fila(ou o pai dele,caso 
		//ele não possua filhos).Note que o nó retornado não é necessariamente o nó do argumento. 
		no* aux=NULL;
		if(n->esq==NULL||n->dir==NULL){
			a->qtd--;
			if(n->esq!=NULL){
				n->esq->pai=n->pai;
				aux=n->esq;
			}
			if(n->dir!=NULL){
				n->dir->pai=n->pai;
				aux=n->dir;
			}
			if(a->raiz==n)
				a->raiz=aux;
			else{
				if(n->pai->esq==n)
					n->pai->esq=aux;
				else
					n->pai->dir=aux;
			}
			if(aux==NULL)
				aux=n->pai;
			destroi_no(n);
			return aux;
		}
		else{
			aux=n->dir;
			while(aux->esq!=NULL)
				aux=aux->esq;
			transplante(n,aux);
			return removendo_no(a,aux);
		}
	}
	void remove_no(arv* a,int id){
		//Chama a função para remover o nó com o id especificado e verifica 
		//se em algum lugar da avl a remoção causou um desbalanceamento.
		no* n=busca(a,id);
		if(n!=NULL){
			n=removendo_no(a,n);
			while(n!=NULL){
				recalcular_altura(n);
				rebalancear(a,n);
				n=n->pai;
			}
		}
	}
	void remove_raiz(arv* a){
		//Chama a função para remover a raiz e verifica se em algum lugar da avl
		//a remoção causou um desbalanceamento.Note que ela exibe os parãmetros do 
		//da raiz
		no* n=a->raiz;
		if(n!=NULL){
			printf("%d %d %d\n",a->raiz->id,a->raiz->op,a->raiz->val);
			n=removendo_no(a,n);
			while(n!=NULL){
				recalcular_altura(n);
				rebalancear(a,n);
				n=n->pai;
			}
		}
	}
