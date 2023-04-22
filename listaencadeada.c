#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *proximo;
    int valor;
} No;

void inserir_no_inicio(No **lista, int valor)
{
    No *novo = malloc(sizeof(No));
    novo->valor = valor;    // Atribuindo o valor a ser inserido
    novo->proximo = *lista; // Fazendo meu novo elemento apontar para o antigo inicio
    *lista = novo;          // Fazendo meu inicio tornar a ser meu novo elemento
}

void inserir_no_final(No **lista, int valor)
{
    No *aux, *novo = malloc(sizeof(No));
    novo->valor = valor;  // Atribuindo o valor a ser inserido
    novo->proximo = NULL; // Fazendo o novo elemento apontar para NULL

    if (*lista == NULL)
    {                  // Verificando se minha lista está vazia
        *lista = novo; // Fazendo meu inicio apontar para o novo elemento
    }
    else
    {
        aux = *lista; // Criando um auxiliar para guardar o inicio da lista
        while (aux->proximo != NULL)
        {                       // Verificando se o proximo elemento não aponta para NULL
            aux = aux->proximo; // Fazendo meu elemento atual ser meu proximo elemento
        }
        aux->proximo = novo; // Fazendo meu proximo elemento apontar para meu novo elemento
    }
}

void remover_inicio(No **lista)
{
    No *descarte = malloc(sizeof(No));
    if(*lista != NULL){
        descarte = *lista;          // Criando um auxiliar para guardar o valor do inicio
        *lista = (*lista)->proximo; // Fazendo meu inicio ser o meu proximo elemento
        free(descarte);             // Liberando memoria desnecessária
}
}

void imprimir(No *lista)
{
    printf("\n");
    while (lista)//Verificando se a lista não está vazia
    {
        printf("%d ", lista->valor);
        lista = lista->proximo;//Fazendo meu novo valor ser o proximo valor
    }
    printf("\n");
}

void inserir_ordenado(No **lista, int valor)
{
    No *aux, *novo= malloc(sizeof(No));
    novo->valor = valor;//Atribuindo o valor a ser inserido

    if (*lista == NULL)//Verificando se a lista está vazia
    {
        novo->proximo = NULL;//Fazendo meu novo elemento apontar para NULL
        *lista = novo;//Fazendo meu inicio ser meu novo elemento
    }
    else if (novo->valor < (*lista)->valor)//Verificando se meu novo elemento é menor que o primeiro elemento da lista
    {
        novo->proximo = *lista;//Fazendo meu novo elemento apontar para o inicio da lista
        *lista = novo;//Fazendo meu inicio ser meu novo elemento
    }
    else
    {
        aux = *lista;//Atribuindo a aux meu primeiro elemento da lista
        while (aux->proximo && novo->valor > aux->proximo->valor)//Verificando se o proximo elemento é diferente de NULL e se meu elemento é maior que meu proximo elemento
        {
            aux = aux->proximo;//Fazendo aux ser meu proximo elemento
        }
        novo->proximo = aux->proximo;//Fazendo meu novo elemento apontar para o proximo elemento
        aux->proximo = novo;//Fazendo meu proximo elemento ser meu novo elemento
    }
}

void remover_fim(No **lista){
    No *aux, *descarte = malloc(sizeof(No));

    if(*lista != NULL){
        aux = *lista;
        while(aux->proximo->proximo != NULL){
            aux = aux->proximo; 
        }descarte = aux->proximo->proximo;
        aux->proximo = NULL;
        free(descarte); 
    }
}

void remover_valor(No **lista, int valor){
    No *aux, *descarte = malloc(sizeof(No));
    if(*lista != NULL){
        aux = *lista;
        if((*lista)->valor == valor){
            descarte = *lista;
            *lista = (*lista)->proximo;
        
        }
        else{
            while(aux->proximo != NULL && aux->proximo->valor != valor){
                aux = aux->proximo;
            }
            descarte = aux->proximo;
            aux->proximo = aux->proximo->proximo;

        }
        free(descarte);
}
}

int main()
{
    No *lista = NULL;

    int valor, opcao;

    do
    {
        printf("1. inserir no inicio\n2. inserir no final\n3. inserir ordenado\n4. remover do inicio\n7. remover do fim\n8. remover valor\n5. imprimir\n6. sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            scanf("%d", &valor);
            inserir_no_final(&lista, valor);
            break;
        case 3:
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 4:
            remover_inicio(&lista);
            break;
        case 5:
            imprimir(lista);
            break;
        case 7:
            remover_fim(&lista);
            break;
        case 8:
            scanf("%d", &valor);
            remover_valor(&lista, valor);
            break;
        }
    } while (opcao != 6);

    return 0;
}