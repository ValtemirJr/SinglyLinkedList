#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define N 40

struct _func{
    int cod;
    char nome[N];
    double salario;
    struct _func *next;
};
typedef struct _func Funcionario;

int listaVazia(Funcionario *first){
    if(first == NULL)
        return 1;
    return 0;
}

Funcionario *adicionaInicio(Funcionario *first,Funcionario *novo){
    if(listaVazia(first)){
        return novo;
    }
    novo->next = first;
    first = novo;
    return first;
}

Funcionario *adicionaFinal(Funcionario *first,Funcionario *novo){
    Funcionario *aux;
    if(listaVazia(first)){
        return novo;
    }    
    for(aux = first; aux->next != NULL; aux=aux->next);
    aux->next = novo;
    return first;
}

Funcionario *adicionaDepois(Funcionario *first,Funcionario *novo, int v){
    Funcionario *aux;
    if(listaVazia(first)){
        return novo;
    }
    for(aux = first; aux->next != NULL; aux=aux->next){
        if(aux->cod == v){
            novo->next = aux->next;
            aux->next = novo;
            break;
        }
    }
    return first;
}

Funcionario *criaFunc(int cod, char nome[], double salario){
    Funcionario *novo = malloc(sizeof(Funcionario));
    novo->cod = cod;
    snprintf(novo->nome, sizeof(novo->nome), "%s", nome);
    novo->salario = salario;
    novo->next = NULL;
    return novo;
}

void printLista(Funcionario *first){
    Funcionario *aux;
    for(aux = first; aux != NULL; aux=aux->next){
        printf("%d %s %lf", aux->cod, aux->nome, aux->salario);
        printf("\n");
    }
}

void printListaContrario(Funcionario *first){
    if (first == NULL)
        return;
    printListaContrario(first->next);
    printf("%d %s %lf", first->cod, first->nome, first->salario);
    printf("\n");
}

int main(){
    Funcionario *first = NULL;
    first = adicionaInicio(first, criaFunc(1, "Lucas", 63.5));
    first = adicionaInicio(first, criaFunc(2, "José", 63.5));
    first = adicionaInicio(first, criaFunc(3, "Pedro", 63.5));
    first = adicionaInicio(first, criaFunc(4, "Maria", 100.5));
    first = adicionaFinal(first, criaFunc(0, "Carlos", 10.5));
    first = adicionaDepois(first, criaFunc(7, "Paulo", 10.5), 2);
    printLista(first);
    printf("\n");
    printListaContrario(first);

    return 0;
}
