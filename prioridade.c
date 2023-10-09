#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
typedef struct pessoa{
    int idade,prioridade, ordem;
    char nome_pessoa[51];
    char nome_orgao[51];
}pessoa;
typedef struct orgao{
    int qtd_atend;
    char nome_orgao[51];
    struct pessoa* fila;
}orgao;
//lista de orgaos, lê os atendimentos na ordem 
//array de atendimentos para cada um dos orgãos (heap)
//modificar para se encaixar neste contexto
void trocar(pessoa* cliente, int pai, int filho) {//passe o array como parametro na main
    pessoa cliente_pai;
    strcpy(cliente_pai.nome_pessoa, cliente[filho].nome_pessoa);
    cliente_pai.ordem = cliente[filho].ordem;
    cliente_pai.idade = cliente[filho].idade;
    cliente_pai.prioridade = cliente[filho].prioridade;
    strcpy(cliente[filho].nome_pessoa, cliente[pai].nome_pessoa);
    cliente[filho].idade=cliente[pai].idade;
    cliente[filho].prioridade=cliente[pai].prioridade;
    cliente[filho].ordem = cliente[pai].ordem;
    strcpy(cliente[pai].nome_pessoa, cliente_pai.nome_pessoa);
    cliente[pai].ordem = cliente_pai.ordem;
    cliente[pai].prioridade = cliente_pai.prioridade;
    cliente[pai].idade = cliente_pai.idade;
}

void heapify_max ( pessoa* atendido, int Tam_array , int indice ){//acertar heapify de priori com ordem
    // Declaração dos índices
  int Pai = indice;
  int Esq = (2*indice)+1;
  int Dir = (2*indice)+2;
  int maior = Pai;
    if (Esq < Tam_array && atendido[Esq].prioridade > atendido[maior].prioridade) {
        maior = Esq;
    }
    if (Dir < Tam_array && atendido[Dir].prioridade > atendido[maior].prioridade) {
        maior = Dir;
    }

    // If menor is not the parent, swap and recursively call heapify_min
    if (maior != Pai) {
        trocar(atendido, Pai, maior);
        heapify_max(atendido, Tam_array, maior);
    }}
    void remover(pessoa* atendido, FILE* output, int tam){//fazer loop para cada heap
    //fprintf(output,"%s\n",atendido[0].codigo_apos);
    //strcpy(apostas[0].codigo_aposta,apostas[tam-1].codigo_aposta);
    //apostas[0].acertos=apostas[tam-1].acertos;//remover ultima posição
    //acertar para heap de pessoas
}

int main(int argc, char* argv[]){
    pessoa temp_pessoa;
    int indice_orgaos =0; 
    int ordem = 0;
    FILE* input = fopen(argv[1], "r");
    if (input == NULL) {
        printf("ERRO!");
        return 0;
    }

    FILE* output = fopen(argv[2], "w");
    if (output == NULL) {
        printf("ERRO!");
        fclose(input);
        return 0;
    }
    int qtd_orgs, qtd_atend, tam_fila;
    fscanf(input, "%d", &qtd_orgs);
    orgao* lista_orgaos = (orgao*)malloc(sizeof(orgao)*qtd_orgs);
    if (lista_orgaos == NULL) {
        printf("ERRO!");
        return 1;
    }
    
    //faco heap sempre q completr a chamada para 1 orgao?
    //faco fila pra cada orgao?
    for(int index=0; index<qtd_orgs; index++){
        fscanf(input, "%s %d", lista_orgaos[index].nome_orgao, lista_orgaos[index].qtd_atend);
        
    }
    fscanf(input, "%d", &tam_fila);
    pessoa* heap_chamadas =(pessoa*)malloc(sizeof(pessoa)*tam_fila);
    for(int index=0; index<tam_fila; index++){
        fscanf(input,"%s|%s|%d",temp_pessoa.nome_orgao, temp_pessoa.nome_pessoa, temp_pessoa.idade);
        indice_orgaos=0;
        while(strcmp(temp_pessoa.nome_orgao, lista_orgaos[indice_orgaos].nome_orgao)!=0){
            if(lista_orgaos[indice_orgaos].fila==NULL){lista_orgaos[index].fila = (pessoa*)malloc(sizeof(pessoa)*tam_fila);}
            indice_orgaos++;
        }
        strcpy(temp_pessoa.nome_orgao, lista_orgaos[indice_orgaos].fila->nome_orgao);
        strcpy(temp_pessoa.nome_pessoa, lista_orgaos[indice_orgaos].fila->nome_pessoa);
        lista_orgaos[indice_orgaos].fila->idade=temp_pessoa.idade;
        if (temp_pessoa.idade<60)
        {
            lista_orgaos[indice_orgaos].fila->prioridade=1;
        }
        else{lista_orgaos[indice_orgaos].fila->prioridade=2;}
        lista_orgaos[indice_orgaos].fila->ordem=ordem;
        ordem++;
    }
    for(int indice_org=0; indice_org<qtd_orgs; indice_org++){
        for(int pai = (tam_fila-1)/2; pai >= 0; pai--) {
        heapify_max(lista_orgaos[indice_org].fila, tam_fila, pai);}
    }
        
    
    if (heap_chamadas == NULL) {
        printf("ERRO!");
        return 1;
    }
}
