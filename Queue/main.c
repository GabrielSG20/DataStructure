#include <stdio.h>
#include <stdlib.h>

//Criação da célula
struct celula{

	int valor;
	struct celula *prox;
};
typedef struct celula Celula;

// Sem cabeça

void addFim(Celula **fila, int valor, Celula **fim){
	Celula *p = (Celula*) malloc(sizeof(Celula));
	p->valor = valor;
	p->prox = NULL;
	if(*fila == NULL){
		*fila = p;
		*fim = p;
	} else {
		Celula *aux = *fim;
		aux->prox = p;
		*fim = p;

		//Celula *aux = *fila;
		//while(aux->prox!=NULL){
			//aux = aux->prox;
		//}
		//aux->prox = p;
	}
}

void removerCelula(Celula **fila){
	if(*fila==NULL){
		printf("Fila vazia.\n");
	} else{
			Celula *auxcom = *fila;
			auxcom = auxcom->prox;
			*fila = auxcom;
	}
}

void imprimeCelula(Celula *fila){
	Celula *aux = fila;
	printf("Fila: ");
	while(aux!=NULL){
		printf("[%d]",aux->valor);
		aux = aux->prox;
	}
}

int main() {
	// Sem cabeça
	Celula *fila = NULL;

	Celula *fim = NULL;

	//removerCelula(&fila);

	for(int i = 1; i < 6; i++){
		addFim(&fila,i,&fim);
	}
	addFim(&fila, 6,&fim);
	removerCelula(&fila);
	
	//removerCelula(&fila);
	//removerCelula(&fila);
	//removerCelula(&fila);
	//removerCelula(&fila);
	//removerCelula(&fila);

	imprimeCelula(fila);

	return 0;
}