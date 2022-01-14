#include <stdio.h>
#include <stdlib.h>

//Criação da célula
struct celula{

	int valor;
	struct celula *prox;
};
typedef struct celula Celula;

int tamanho = 0;

// Sem cabeça

void addInicio(Celula **lst, int valor){
	Celula *p = (Celula*) malloc(sizeof(Celula));
	p->valor = valor;
	p->prox = NULL;
	if(*lst!=NULL){
		p->prox = *lst;
	}
	*lst = p;
	tamanho++;
}

void addFim(Celula **lst, int valor){
	Celula *p = (Celula*) malloc(sizeof(Celula));
	p->valor = valor;
	p->prox = NULL;
	if(*lst==NULL){
		*lst = p;
	} else {
		Celula *aux = *lst;
		while (aux->prox!=NULL){
			aux = aux->prox;
		}
		aux->prox = p;
	}
	tamanho++;
}

void addPosicao(Celula **lst, int valor, int posicao){
	Celula *p = (Celula*) malloc(sizeof(Celula));
	p->valor = valor;
	p->prox = NULL;
	if(posicao>tamanho){
		printf("Posição inválida.");
	} else{
		if(posicao == 0){
			addInicio(lst, valor);
		} else {
			Celula *aux = *lst;
			for (int i = 0; i < posicao-1;i++){
				aux = aux->prox;
			}
			p->prox = aux->prox;
			aux->prox = p;
		}
		tamanho++;
	}
}

void removerCelula(Celula **lst, int posicao){
	if(posicao>=tamanho || tamanho == 0){
		printf("Posição inválida ou lista vazia.");
	} else{
		if(posicao == 0){
			Celula *auxcom = *lst;
			auxcom = auxcom->prox;
			*lst = auxcom;
		} else{
			Celula *aux = *lst;
			for(int i = 0; i<posicao-1;i++){
				aux = aux->prox;
			}
			aux->prox = aux->prox->prox;
		}
		tamanho--;
	}
}

void imprimeCelula(Celula *lst){
	Celula *aux = lst;
	printf("Lista: ");
	while(aux!=NULL){
		printf("[%d]",aux->valor);
		aux = aux->prox;
	}
}

int main() {
	// Sem cabeça
	Celula *lst = NULL;
	//removerCelula(lst,0);
	for(int i = 5; i > 0; i--){
		addInicio(&lst,i);
	}

	//addInicio(&lst,0);
	//addFim(&lst,6);
	//addPosicao(&lst,10,0);
	//addPosicao(&lst,10,3);
	//addPosicao(&lst,10,7);
	//addPosicao(&lst,10,10);
	//removerCelula(&lst,0);
	//removerCelula(&lst,3);

	imprimeCelula(lst);

	return 0;
}