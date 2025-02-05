#include <stdio.h>
#include <stdlib.h>

typedef struct sNoA {
	int chave;
	struct sNoA *esq;
	struct sNoA *dir;
} TNoA;

void imprime(TNoA *nodo, int tab) {
	for (int i = 0; i < tab; i++) {
		printf("-");
	}
	if (nodo != NULL) {
		printf("%d\n", nodo->chave);
		imprime(nodo->esq, tab + 2);
		printf("\n");
		imprime(nodo->dir, tab + 2);
	} else printf("vazio");
}

TNoA *insere(TNoA *no, int chave) {
	if (no == NULL) {
		no = (TNoA *) malloc(sizeof(TNoA));
		no->chave = chave;
		no->esq = NULL;
		no->dir = NULL;
	} else if (chave < (no->chave))
		no->esq = insere(no->esq, chave);
	else if (chave > (no->chave)) {
		no->dir = insere(no->dir, chave);
	} else {
		printf("Inser��o inv�lida! ");
		exit(1);
	}
	return no;
}

TNoA *maior_no_esquerda(TNoA *no) {
	TNoA *atual = no;

	/* loop para encontrar o n� mais � direita */
	while (atual->dir != NULL)
		atual = atual->dir;
	return atual;
}

/*Esta fun��o recebe a raiz da �rvore ou sub-arvore e a chave a ser exclu�da
Retorna ponteiro para a nova raiz da sub-�rvore sendo modificada*/
TNoA *exclui(TNoA *raiz, int chave) {
	// Caso base - nada a fazer
	if (raiz == NULL)
        return raiz;
	// Se chave � menor do que a chave da raiz,
	//procura na sub�rvore esquerda
	if (chave < raiz->chave)
		raiz->esq = exclui(raiz->esq, chave);
	// Se chave � maior do que a chave da raiz,
	//procura na sub�rvore direita
	else if (chave > raiz->chave)
		raiz->dir = exclui(raiz->dir, chave);
	// Sen�o, a chave � igual e esse � o n� que tem que ser exclu�do
	else{
		// s� tem sub�rvore direita ou nenhuma sub�rvore
		if (raiz->esq == NULL){
			/*FAZER CODIGO AQUI*/
			TNoA *aux = raiz->dir;
			free(raiz);
			return aux;
		// s� tem sub�rvore esquerda ou nenhuma sub�rvore
		} else if (raiz->dir == NULL){
			/*FAZER CODIGO AQUI*/
			TNoA *aux = raiz-> esq;
			free(raiz);
			return aux;
		} else { // n� com 2 filhos - pega o maior da sub�rvore esquerda
			/*FAZER O CODIGO AQUI*/
			TNoA * aux = maior_no_esquerda(raiz->esq);
			raiz->chave = aux->chave;
			raiz->esq = exclui(raiz->esq, aux->chave);
		}
	}
	return raiz;
}

int main(void) {
	TNoA *raiz, *no;
	raiz = NULL;
	//arvore usada no slide da disciplina
	raiz = insere(raiz, 200);
	//subarvore esquerda
	insere(raiz, 100);
	insere(raiz, 80);
	insere(raiz, 150);
	insere(raiz, 70);
	insere(raiz, 65);
	insere(raiz, 79);
	insere(raiz, 120);
	insere(raiz, 110);
	insere(raiz, 130);

	//subarvore direita
	insere(raiz, 300);
	insere(raiz, 250);
	insere(raiz, 400);
	insere(raiz, 220);
	insere(raiz, 270);
	insere(raiz, 260);
	insere(raiz, 350);
	insere(raiz, 500);

	printf("\n\nArvore original: \n");
	imprime(raiz, 0);

	exclui(raiz, 100);
	exclui(raiz, 150);
	exclui(raiz, 80);
	exclui(raiz, 270);
	exclui(raiz, 400);
	exclui(raiz, 200);

	printf("\n\nArvore resultante da exclusao: \n");
	imprime(raiz, 0);
}
