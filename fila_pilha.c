//fila: unidirecional. remoção na cabeça
//pilha: cresce na cauda. 

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
typedef struct impressora{
    char nome[51];
    char doc[51];
    int contaPg;
    struct impressora *Prox;
}Printer;
typedef struct{
    Printer* cabeca, *cauda;
}Lista;
typedef struct documento{
    char doc[51];
    int paginas;
    struct documento *next;
}Doc;
typedef struct{
    Doc* inicio,*fim;
}Fila;
void cria_lista(Lista* lista){
    lista->cabeca=NULL;
}
void cria_fila(Fila* fila){
    fila->inicio=NULL;
}
Printer* checar(Fila* fila,Lista* lista){
    //busca nao achou
    Printer* atual = lista->cabeca;
    while(atual == lista->cabeca){
        do {
            if (atual->contaPg == 0) {
                return atual;
            }
            atual = atual->Prox;
        } while (atual != lista->cabeca);
        imprimir(fila,lista);}
    

}
void imprimir(Fila* fila,Lista* lista){
    Printer* atual = lista->cabeca;
    do
    {
        if(atual->contaPg>0){
            atual->contaPg--;
        }
        atual=atual->Prox;
    } while (atual!=lista->cabeca);
    
}      
void atribuir(Fila* fila, Lista* lista) {//atribui documento a uma impressora livre e remove doc da fila
    Printer* disponivel= checar(fila,lista);
    Doc* pop = fila->inicio;
    
        strcpy(disponivel->doc, pop->doc);//copia valor
        disponivel->contaPg=pop->paginas;//seta o valor 
        fila->inicio=pop->next;
        free(pop);
        pop=NULL;
        //fprintf(output, "[ OK  ] REMOVE %s\n", stringx);
}
    
void insere_impressora(Lista* lista){
    Printer* novo = malloc(sizeof(Printer));
    
    if (lista->cabeca!=NULL)
    {   
            lista->cauda->Prox=novo; //a atual cauda aponta pro novo elemento
            novo->Prox=lista->cabeca; //proximo do novo elemento é a cabeça
            lista->cauda=novo; //novo elemento é definido como a nova cauda
    }
    
    else{
        lista->cabeca=novo;
        lista->cauda=novo;
        lista->cabeca->Prox=novo;
        lista->cauda->Prox=novo;
    } 
}
void insere_doc(Fila* fila){
    Doc* novo = malloc(sizeof(Doc));
    
    if (fila->inicio!=NULL)
    {   
            fila->fim->next=novo; //a atual cauda aponta pro novo elemento
            fila->fim=novo; //novo elemento é definido como a nova cauda
    }
    
    else{
        fila->inicio=novo;
        fila->fim=novo;
    } 
}
void show(Lista* lista, char stringx[51], FILE* output){
    No* pop = busca(lista,stringx);
    
    if(pop!=NULL){
        fprintf(output, "[ OK  ] %s<-%s->%s\n", pop->Anter->User, pop->User, pop->Prox->User);
    }
    else{
        fprintf(output, "[ERROR] ?<-%s->?\n", stringx);
    }}
