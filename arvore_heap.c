#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct aposta{
    int acertos;
    char codigo_aposta[33];
}bet;

void trocar(bet* apostas, int pai, int filho) {//passe o array como parametro na main
    bet Valor_pai;
    strcpy(Valor_pai.codigo_aposta, apostas[filho].codigo_aposta);
    Valor_pai.acertos = apostas[filho].acertos;
    strcpy(apostas[filho].codigo_aposta, apostas[pai].codigo_aposta);
    apostas[filho].acertos = apostas[pai].acertos;
    strcpy(apostas[pai].codigo_aposta, Valor_pai.codigo_aposta);
    apostas[pai].acertos = Valor_pai.acertos;
}

void heapify_max ( bet* apostas, int Tam_array , int indice ){
    // Declaração dos índices
  int Pai = indice;
  int Esq = (2*indice)+1;
  int Dir = (2*indice)+2;
  int maior = Pai;
    if (Esq < Tam_array && apostas[Esq].acertos > apostas[maior].acertos) {
        maior = Esq;
    }
    if (Dir < Tam_array && apostas[Dir].acertos > apostas[maior].acertos) {
        maior = Dir;
    }

    // If menor is not the parent, swap and recursively call heapify_min
    if (maior != Pai) {
        trocar(apostas, Pai, maior);
        heapify_max(apostas, Tam_array, maior);
    }}
void heapify_min(bet* apostas, int Tam_array, int indice) {
    int Pai = indice;
    int Esq = 2 * indice + 1;
    int Dir = 2 * indice + 2;

    // Find the smallest among parent, left child, and right child
    int menor = Pai;
    if (Esq < Tam_array && apostas[Esq].acertos < apostas[menor].acertos) {
        menor = Esq;
    }
    if (Dir < Tam_array && apostas[Dir].acertos < apostas[menor].acertos) {
        menor = Dir;
    }

    // If menor is not the parent, swap and recursively call heapify_min
    if (menor != Pai) {
        trocar(apostas, Pai, menor);
        heapify_min(apostas, Tam_array, menor);
    }}
void remover(bet* apostas, FILE* output, int tam){//fazer loop para cada heap
    fprintf(output,"%s\n",apostas[0].codigo_aposta);
    strcpy(apostas[0].codigo_aposta,apostas[tam-1].codigo_aposta);
    apostas[0].acertos=apostas[tam-1].acertos;//remover ultima posição
}
int calcula_acertos(int escolhas[15], int sorteados[10]){
        int acertos = 0;
        for(int numero=0; numero<15; numero++){
            for(int sort_num=0; sort_num<10; sort_num++){
                if(escolhas[numero]==sorteados[sort_num]){
                    acertos++;
                    break;
                }
            }}
            return acertos;
    }

int main(int argc, char* argv[]){
    //precisa de dois heaps(um max e um minimo)
    int premio_total,premio_max,premio_min,total_apost,tam_max=0,tam_min=0,max_acert=0,min_acert=10, tam_heap_main_iter;
    int sort[10], apostado[15];
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
    
    fscanf(input, "%d", &premio_total);
    premio_max = premio_min = premio_total/2;
    fscanf(input, "%d", &total_apost);
    bet* heap_main = (bet*)malloc(sizeof(bet)*total_apost);
    if (heap_main == NULL) {
        printf("ERRO!");
        return 1;
    }
    tam_heap_main_iter=total_apost;
    fscanf(input, "%d %d %d %d %d %d %d %d %d %d", &sort[0],&sort[1],&sort[2],&sort[3],&sort[4],&sort[5],&sort[6],&sort[7],&sort[8],&sort[9]);
        
    for(int cont=0; cont<total_apost; cont++){
        fscanf(input, "%s %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", heap_main[cont].codigo_aposta, &apostado[0],&apostado[1],&apostado[2],&apostado[3],&apostado[4],&apostado[5],&apostado[6],&apostado[7],&apostado[8],&apostado[9],&apostado[10],&apostado[11],&apostado[12],&apostado[13],&apostado[14]);
        heap_main[cont].acertos = calcula_acertos(apostado,sort);
        //calcula tamanho dos heaps max_min
        if(heap_main[cont].acertos<=min_acert){if(heap_main[cont].acertos==min_acert){tam_min+=1;}
        else{tam_min=1;
        min_acert=heap_main[cont].acertos;
        }}
        
        if(heap_main[cont].acertos>=max_acert){if(heap_main[cont].acertos==max_acert){tam_max+=1;}
        else{tam_max=1;
        max_acert=heap_main[cont].acertos;}
        }
        
        }


    for(int pai = (total_apost-1)/2; pai >= 0; pai--) {
        heapify_max(heap_main, total_apost, pai);
    }
    fprintf(output,"[%d:%d:%d]\n",tam_max,max_acert,(premio_max/tam_max));
    for(int maxim_ganhador=0; maxim_ganhador<tam_max; maxim_ganhador++){
        remover(heap_main,output,tam_heap_main_iter);
        tam_heap_main_iter--;
        heapify_max(heap_main,tam_heap_main_iter,0);
    }
    for(int pai = (tam_heap_main_iter-1)/2; pai >= 0; pai--) {
        heapify_min(heap_main, tam_heap_main_iter, pai);
    }
    fprintf(output,"[%d:%d:%d]\n",tam_min,min_acert,(premio_min/tam_min));
    for(int min_ganhador=0; min_ganhador<tam_min; min_ganhador++) {
        remover(heap_main,output,tam_heap_main_iter);
        tam_heap_main_iter--;
        heapify_min(heap_main,tam_heap_main_iter,0);
    }

    fclose(output);
    fclose(input);
    return 0;
}
