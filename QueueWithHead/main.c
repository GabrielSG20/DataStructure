#include <stdio.h>
#include <stdlib.h>

//Criação da célula
struct celula{

	int valor;
	struct celula *prox;
};
typedef struct celula Celula;

// Com cabeça

struct cabeca{
	Celula *prox;
};
typedef struct cabeca Cabeca;

void addFim(Cabeca *cab, int valor, Celula **fim){
	Celula *p = (Celula*) malloc(sizeof(Celula));
	p->valor = valor;
	p->prox = NULL;
	if(cab->prox==NULL){
		cab->prox = p;
		*fim = p;
	} else {
		Celula *aux = *fim;
		aux->prox = p;
		*fim = p;

		//Celula *aux = cab->prox;
		//while(aux->prox!=NULL){
			//aux = aux->prox;
		//}
		//aux->prox = p;
	}
}

void removerCelula(Cabeca* cab){
	if(cab->prox == NULL){
		printf("Fila vazia.\n");
	} else{
			Celula *auxcom = cab->prox->prox;
			cab->prox = auxcom;
	}
}

void imprimeCelula(Cabeca *cab){
	Celula *aux = cab->prox;
	printf("Fila: ");
	while(aux!=NULL){
		printf("[%d]",aux->valor);
		aux = aux->prox;
	}
}

int main() {
	// Com cabeca
	Cabeca *cab = (Cabeca*) malloc(sizeof(Cabeca));
	cab->prox = NULL;
	Celula *fim = (Celula*) malloc(sizeof(Celula));
	fim->prox = NULL;

	//removerCelula(cab);

	for(int i = 1; i < 6; i++){
		addFim(cab, i, &fim);
	}

	addFim(cab, 6, &fim);
	
	removerCelula(cab);
	//removerCelula(cab);
	//removerCelula(cab);
	//removerCelula(cab);
	//removerCelula(cab);
	//removerCelula(cab);

	imprimeCelula(cab);

	return 0;
}