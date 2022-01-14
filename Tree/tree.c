#include <stdio.h>
#include <stdlib.h>

struct celula {
	int valor;
	struct celula *esq;
	struct celula *dir;
};

typedef struct celula No;

No* create(int valor) {
	No *n = malloc(sizeof(No));
	n->valor = valor;
	n->esq = NULL;
	n->dir = NULL;
	return n;
}

void imprimir(No *root) {
	if(root==NULL)
		return;
	imprimir(root->esq);
	printf("[%d] ",root->valor);
	imprimir(root->dir);
}

No* busca(No *root, int valor){
	No *aux = root;
	while(aux!=NULL && aux->valor != valor){
		if(valor < aux->valor)
			aux = aux->esq;
		else if(valor > aux->valor)
			aux = aux->dir;
	}
	return aux;
}

void valorExiste(No *root, int valor){
	if(busca(root, valor) == NULL){
		printf("Valor não existe na árvore.");
	} else {
		printf("Valor existe na árvore.");
	}
}

void add(No *root, int valor) {
	if(valor < root->valor){
		if(root->esq == NULL)
			root->esq = create(valor);
		else
			add(root->esq,valor);
	}
	else{
		if(root->dir == NULL)
			root->dir = create(valor);
		else
			add(root->dir,valor);
	}
}

No* rem(No *root, int valor){
 	if (root == NULL)
 		return NULL;
 	else if (root->valor > valor)
 		root->esq = rem(root->esq, valor);
 	else if (root->valor < valor)
 		root->dir = rem(root->dir, valor);
 	else { 
		// nó sem filhos
 		if (root->esq == NULL && root->dir == NULL) {
 			free (root);
 			root = NULL;
 		}
 		// nó só tem filho à direita 
 		else if (root->esq == NULL) {
 			No *t = root;
 			root = root->dir;
 			free (t);
 			}
		// só tem filho à esquerda
 		else if (root->dir == NULL) {
 			No *t = root;
 			root = root->esq;
 			free (t);
 		}
 		// nó tem os dois filhos
 		else {
 			No *f = root->esq;
 			while (f->dir != NULL) {
 				f = f->dir;
 			}
 			root->valor = f->valor;
 			f->valor = valor;
 			root->esq = rem(root->esq,valor);
 		}
 	}
	return root;
}

int main(void) {

	No *root = create(5);

	add(root,2);
	add(root,1);
	add(root,8);
	add(root,4);
	add(root,3);

	rem(root,5);

	//valorExiste(root, 5);

	imprimir(root);

  	return 0;
}