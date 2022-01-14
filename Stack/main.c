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

void addInicio(Cabeca *cab, int valor){
	Celula *p = (Celula*) malloc(sizeof(Celula));
	p->valor = valor;
	p->prox = cab->prox;
	cab->prox = p;
}

void removerCelula(Cabeca* cab){
	if(cab->prox == NULL){
		printf("Pilha vazia.\n");
	} else{
			Celula *auxcom = cab->prox->prox;
			cab->prox = auxcom;
	}
}

void imprimeCelula(Cabeca *cab){
	Celula *aux = cab->prox;
	printf("Pilha: ");
	while(aux!=NULL){
		printf("[%d]",aux->valor);
		aux = aux->prox;
	}
}

int main() {
	// Com cabeca
	Cabeca *cab = (Cabeca*) malloc(sizeof(Cabeca));
	cab->prox = NULL;

	//removerCelula(cab);

	for(int i = 1; i < 6; i++){
		addInicio(cab, i);
	}

	addInicio(cab, 6);

	removerCelula(cab);
	//removerCelula(cab);
	//removerCelula(cab);
	//removerCelula(cab);
	//removerCelula(cab);
	//removerCelula(cab);

	imprimeCelula(cab);

	return 0;
}