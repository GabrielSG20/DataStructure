#include <stdio.h>
#include <stdlib.h>

//Criação da célula
struct celula{

	int valor;
	struct celula *prox;
};
typedef struct celula Celula;

int tamanho = 0;

// Com cabeça

struct cabeca{
	Celula *prox;
};
typedef struct cabeca Cabeca;

void addInicio(Cabeca *cab, int valor){
	Celula *p = (Celula*) malloc(sizeof(Celula));
	p->valor = valor;
	p->prox = cab->prox;
	cab->prox = p;

	tamanho++;
}

void addFim(Cabeca *cab, int valor){
	Celula *p = (Celula*) malloc(sizeof(Celula));
	p->valor = valor;
	p->prox = NULL;
	if(cab->prox==NULL){
		cab->prox = p;
	} else {
		Celula *aux = cab->prox;
		while (aux->prox!=NULL){
			aux = aux->prox;
		}
		aux->prox = p;
	}
	tamanho++;
}

void addPosicao(Cabeca *cab, int valor, int posicao){
	Celula *p = (Celula*) malloc(sizeof(Celula));
	p->valor = valor;
	p->prox = NULL;
	if(posicao>tamanho){
		printf("Posição inválida.");
	} else{
		if(posicao == 0){
			addInicio(cab, valor);
		} else {
			Celula *aux = cab->prox;
			for (int i = 0; i < posicao-1;i++){
				aux = aux->prox;
			}
			p->prox = aux->prox;
			aux->prox = p;
		}
		tamanho++;
	}
}

void removerCelula(Cabeca* cab, int posicao){
	if(posicao>=tamanho || tamanho == 0){
		printf("Posição inválida ou lista vazia.");
	} else{
		if(posicao == 0){
			Celula *auxcom = cab->prox->prox;
			cab->prox = auxcom;
		} else{
			Celula *aux = cab->prox;
			for(int i = 0; i<posicao-1;i++){
				aux = aux->prox;
			}
			aux->prox = aux->prox->prox;
		}
		tamanho--;
	}
}

void imprimeCelula(Cabeca *cab){
	Celula *aux = cab->prox;
	printf("Lista: ");
	while(aux!=NULL){
		printf("[%d]",aux->valor);
		aux = aux->prox;
	}
}

int main() {
	// Com cabeca
	Cabeca *cab = (Cabeca*) malloc(sizeof(Cabeca));
	cab->prox = NULL;

	for(int i = 5; i > 0; i--){
		addInicio(cab, i);
	}

	addFim(cab,10);
	addPosicao(cab, 90, 2);
	removerCelula(cab, 2);
	removerCelula(cab, 5);

	imprimeCelula(cab);

	return 0;
}