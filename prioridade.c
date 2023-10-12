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
    pessoa cliente_temp;
    memcpy(&cliente_temp, &cliente[filho], sizeof(pessoa));
    memcpy(&cliente[filho], &cliente[pai], sizeof(pessoa));
    memcpy(&cliente[pai], &cliente_temp, sizeof(pessoa));
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
    printf("%d\n",qtd_orgs);
    orgao* lista_orgaos = (orgao*)malloc(sizeof(orgao)*qtd_orgs);
    if (lista_orgaos == NULL) {
        printf("ERRO!");
        return 1;
    }
    for(int index=0; index<qtd_orgs; index++){
        fscanf(input, "%s %d", lista_orgaos[index].nome_orgao, &lista_orgaos[index].qtd_atend);
        lista_orgaos[index].fila = NULL;
        
    }
    printf("aqui\n");
    fscanf(input, "%d", &tam_fila);
    for(int index=0; index<tam_fila; index++){
        fscanf(input,"%s|%s|%d",temp_pessoa.nome_orgao, temp_pessoa.nome_pessoa, &temp_pessoa.idade);
        indice_orgaos=0;
        printf("idade = %d\n", temp_pessoa.idade);
        //busca o orgão que coincida com a pessoa atual
        while(indice_orgaos<qtd_orgs && strcmp(temp_pessoa.nome_orgao, lista_orgaos[indice_orgaos].nome_orgao)!=0){
            if(lista_orgaos[indice_orgaos].fila==NULL){lista_orgaos[indice_orgaos].fila = (pessoa*)calloc(tam_fila, sizeof(pessoa));
            if (lista_orgaos[indice_orgaos].fila == NULL) {
            printf("ERRO!");
            return 1;}
            printf("priori = %d\n", lista_orgaos[indice_orgaos].fila[7].prioridade);
            }
            indice_orgaos++;
            
        }

        for(int index_lista=0; index_lista<tam_fila; index_lista++){
            if(lista_orgaos[indice_orgaos].fila[index_lista].prioridade==0){
                strcpy(temp_pessoa.nome_orgao, lista_orgaos[indice_orgaos].fila[index_lista].nome_orgao);
                strcpy(temp_pessoa.nome_pessoa, lista_orgaos[indice_orgaos].fila[index_lista].nome_pessoa);
                lista_orgaos[indice_orgaos].fila[index_lista].idade=temp_pessoa.idade;
                printf("aqui2\n");
                if (temp_pessoa.idade<60) {
                    lista_orgaos[indice_orgaos].fila[index_lista].prioridade=1;}
                else{
                    lista_orgaos[indice_orgaos].fila[index_lista].prioridade=2;}
                lista_orgaos[indice_orgaos].fila[index_lista].ordem=index_lista;
                printf("aqui3\n");
            }//calloc seta prioridade para 0 e nenhum atendimento tem prioridade abaixo de 1, logo prioridade=0 é condição que explicita q n houve input naquela struct
        }
    
    }
    fclose(input);
    fclose(output);
    return 0;}
