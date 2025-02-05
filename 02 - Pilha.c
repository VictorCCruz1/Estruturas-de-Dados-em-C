#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista encadeada
typedef struct lista {
    int info;
    struct lista *prox;
} TLista;

// Estrutura de uma pilha utilizando lista encadeada
typedef struct pilha {
    TLista *topo;
} TPilha;

// Função para inicializar uma pilha
TPilha *inicializa() {
    TPilha *pilha = (TPilha *)malloc(sizeof(TPilha));
    pilha->topo = NULL;
    return pilha;
}

// Função para liberar memória alocada para a pilha
void libera(TPilha *p) {
    TLista *q = p->topo;
    TLista *r;
    while(q != NULL){
        r = q;
        q = q->prox;
        free(r);
    }
    free(p);
}

// Função para verificar se a pilha está vazia
int pilha_vazia(TPilha *pilha) {
    return pilha->topo == NULL;
}

// Função para inserir um elemento no topo da pilha
void push(TPilha *pilha, int elem) {
    TLista *novo = (TLista*) malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}

// Função para remover e retornar o elemento do topo da pilha
int pop(TPilha *pilha) {
    if (pilha_vazia(pilha)) {
        exit(1);
    }
    TLista *aux = pilha->topo;
    int info = aux->info;
    pilha->topo = aux->prox;
    free(aux);
    return info;
}

// Função para consultar o elemento do topo da pilha sem removê-lo
int peek(TPilha *pilha) {
    if (pilha_vazia(pilha)) {
        return -1; // Retorna -1 caso a pilha esteja vazia
    }
    return pilha->topo->info;
}

// Função para imprimir a pilha sem alterá-la
void imprime_pilha(TPilha *pilha) {
    printf("\nEstado atual da Pilha:\n");
    TPilha *aux = inicializa();
    
    // Transferir elementos para a pilha auxiliar e imprimir
    while (!pilha_vazia(pilha)) {
        int valor = pop(pilha);
        printf("%d ", valor);
        push(aux, valor);
    }
    
    // Restaurar os elementos para a pilha original
    while (!pilha_vazia(aux)) {
        push(pilha, pop(aux));
    }
    
    libera(aux);
    printf("\n");
}

// Função principal para testar a pilha
int main() {
    TPilha *pilha = inicializa();
    push(pilha, 5);
    printf("topo: %d\n", peek(pilha));
    push(pilha, 4);
    printf("topo: %d\n", peek(pilha));
    push(pilha, 3);
    printf("topo: %d\n", peek(pilha));

    imprime_pilha(pilha);

    int info = pop(pilha);
    printf("elemento removido: %d\n", info);

    imprime_pilha(pilha);
    libera(pilha);
    return 0;
}
