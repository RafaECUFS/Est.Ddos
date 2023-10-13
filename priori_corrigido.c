#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    int idade, prioridade, ordem;
    char nome_pessoa[51];
    char nome_orgao[51];
} pessoa;

typedef struct orgao {
    int qtd_atend,alocado;
    char nome_orgao[51];
    struct pessoa* fila;
} orgao;

void trocar(pessoa* cliente, int pai, int filho) {
    pessoa cliente_temp;
    memcpy(&cliente_temp, &cliente[filho], sizeof(pessoa));
    memcpy(&cliente[filho], &cliente[pai], sizeof(pessoa));
    memcpy(&cliente[pai], &cliente_temp, sizeof(pessoa));
}

int main(int argc, char* argv[]) {
    pessoa* temp_pessoa = malloc(sizeof(pessoa));
    int indice_orgaos = 0;
    int ind_fila = 0;

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
    fscanf(input, "%d\n", &qtd_orgs);
    printf("%d\n", qtd_orgs);

    orgao* lista_orgaos = (orgao*)malloc(sizeof(orgao) * qtd_orgs);
    if (lista_orgaos == NULL) {
        printf("ERRO!");
        return 1;
    }

    for (int index = 0; index < qtd_orgs; index++) {
        fscanf(input, " %49[^ ] %d\n", lista_orgaos[index].nome_orgao, &lista_orgaos[index].qtd_atend);
        lista_orgaos[index].fila = NULL;
        lista_orgaos[index].alocado = 0;
    } //preenche o array de orgaos

    fscanf(input, "%d\n", &tam_fila);
    //pega o valor do tamanho maximo da fila

    for (int linha = 0; linha < tam_fila; linha++) {
        fscanf(input, "%[^|]|%[^|]|%d\n", temp_pessoa->nome_orgao, temp_pessoa->nome_pessoa, &temp_pessoa->idade);
        printf("oie%s\n", temp_pessoa->nome_orgao);
        printf("%s\n", temp_pessoa->nome_orgao);
        printf("%s\n", temp_pessoa->nome_pessoa);
        printf("%d\n", linha);
        printf("idade = %d\n", temp_pessoa->idade);

        for (indice_orgaos = 0; indice_orgaos < qtd_orgs; indice_orgaos++) {
            printf("oi%s\n", lista_orgaos[indice_orgaos].nome_orgao);
            if (strcmp(temp_pessoa->nome_orgao, lista_orgaos[indice_orgaos].nome_orgao) != 0) {
                continue;
            }//encontra o orgao igual ao da pessoa
            
            

            if (lista_orgaos[indice_orgaos].alocado==0) {
                lista_orgaos[indice_orgaos].fila = (pessoa*)calloc(tam_fila, sizeof(pessoa));
                printf("orgao = %s\n",lista_orgaos[indice_orgaos].nome_orgao);
                if (lista_orgaos[indice_orgaos].fila == NULL) {
                    printf("ERRO!");
                    return 1;
                }
                lista_orgaos[indice_orgaos].alocado=1;
                printf("alocado = %d\n",lista_orgaos[indice_orgaos].alocado);
            }   
            //checa se a fila ja foi alocada. se não, aloca.

        }

        for (ind_fila = 0; ind_fila < tam_fila; ind_fila++) {
            if (lista_orgaos[indice_orgaos].fila[ind_fila].prioridade == 0) {
                strcpy(temp_pessoa->nome_orgao, lista_orgaos[indice_orgaos].fila[ind_fila].nome_orgao);
                strcpy(temp_pessoa->nome_pessoa, lista_orgaos[indice_orgaos].fila[ind_fila].nome_pessoa);
                lista_orgaos[indice_orgaos].fila[ind_fila].idade = temp_pessoa->idade;

                printf("aqui2\n");

                if (temp_pessoa->idade < 60) {
                    lista_orgaos[indice_orgaos].fila[ind_fila].prioridade = 1;
                } else {
                    lista_orgaos[indice_orgaos].fila[ind_fila].prioridade = 2;
                }

                lista_orgaos[indice_orgaos].fila[ind_fila].ordem = ind_fila;

                printf("aqui3\n");
            }
        }
    }

    fclose(input);
    fclose(output);

    free(temp_pessoa);

    return 0;
}
