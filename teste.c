#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    double info;
    struct no *prox;
} No;

typedef struct lista{
    No *primeiro;
} Lista;

Lista* lista_Criar(){
    Lista *l = (Lista *) malloc(sizeof(Lista));
    l->primeiro = NULL;
    return l;
}

void lista_Inserir_Inicio(Lista *l, int info){
    No *n = (No *) malloc(sizeof(No));
    n->info = info;

    n->prox = l->primeiro;
    l->primeiro = n;
}

void lista_Inserir(Lista *l, int pos, int info){
    if (pos == 0){
        lista_Inserir_Inicio(l, info);
        return;
    }

    No *n = (No *) malloc(sizeof(No));
    n->info = info;
    

    No *tmp = l->primeiro;
    int i;
    for (i=0; i<pos-1; i++){
        if(tmp == NULL){
            printf("Posição inexistente!");
            return;
        }
        tmp = tmp->prox;
    }

    n->prox = tmp->prox;
    tmp->prox = n; 
}

double lista_Remover_inicio(Lista *l) {
    if(l->primeiro == NULL) {
        printf("Lista vazia\n");
        return 0;
    }

    No *tmp = l->primeiro;
    double info = tmp->info;

    l->primeiro = tmp->prox;

    free(tmp);

    return info;
}

int main(){

}

double lista_Remover(Lista *l, int pos) {
    if(pos==0){
        lista_Remover_inicio(l);
    }

    No *tmp = l->primeiro;
    int i;
    for(i=0; i<pos-1; i++){
        if(tmp == NULL){
            printf("Posição inexistente");
            return 0;
        }
        tmp = tmp->prox;
    }

    No *excluir = tmp->prox;
    if(excluir == NULL){
        printf("Posição Inexistente");
        return 0;
    }
    double info = excluir->info;
    tmp->prox = excluir->prox;
    free(excluir);

    return info;

}

double lista_Obter(Lista *l, int pos) {
    No *tmp = l->primeiro;
    int i;
    for(i=0; i<pos; i++){
        if(tmp == NULL){
            printf("Posicao inexistente");
            return 0;
        }
        tmp = tmp->prox;
    }
    return tmp->info;
}

void lista_Exibir(Lista *l, int pos) {
    No *tmp = l->primeiro;
    int i;
    for(i=0; i<pos; i++){
        if(tmp == NULL){
            printf("Posicao inexistente");
        }
        tmp = tmp->prox;
    }
    printf("O conteudo desse posicao é: %f", tmp->info);
}

void lista_Exibir_Tudo(Lista *l) {
    No *tmp = l->primeiro;
    int i = 1;
    while(tmp != NULL){
        printf("Posicao %d: %f", i, tmp->info);
        tmp = tmp->prox;
        i++;
    }
}