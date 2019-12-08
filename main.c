#include<stdio.h>
#include<stdlib.h>
#include"avl.h"
	void fim(arv* a){
		printf("-+- Inicio relatorio -+-\n%d\n",num_clientes(a));
		while(arv_h(a)!=0)
			remove_raiz(a);
		destroi_arv(a);
		printf("-+- Fim relatorio -+-\n");
	}
	void exibir(arv* a,char x){
		if(x=='c')
			crescente(a);
		else
			decrescente(a);
	}
	void inserir(arv* a){
		int id,op,val;
		scanf("%d %d %d",&id,&op,&val);
		insere(a,id,op,val);
	}
	void remover(arv* a){
		int id;
		scanf("%d",&id);
		remove_no(a,id);
	}
	void consulta(arv* a){
		int id;
		scanf("%d",&id);
		no* aux=busca(a,id);
		if(aux!=NULL)
			printf("existe no com chave: %d\n",id);
		else
			printf("nao existe no com chave: %d\n",id);
	}
	void altura(arv* a){
		printf("%d\n",arv_h(a));
	}
	void nivel(arv* a){
		int i;
		scanf("%d",&i);
		exibir_nivel(a,i);
	}
	int main(){
		char x;
		int flag=0;
		arv* a=criar_arv();
		while(1){
			scanf("%c",&x);
			switch(x){
				case 'c':
					if(flag==1){
						flag=0;
						exibir(a,x);
					}	
					else
						consulta(a);
					break;
				case 'p':
					flag=1;
					break;
				case 'n':
					nivel(a);
					break;
				case'h':
					altura(a);
					break;
				case 'i':
					inserir(a);
					break;
				case 'd':
					flag=0;
					exibir(a,x);
					break;
				case 'r':
					remover(a);
					break;
				case 'f':
					fim(a);
					break;
			};
			if(x=='f')
				break;
		}
		return 0;
	}
