#include <stdint.h>
#include <stdio.h>
#include <String.h>
#include <stdlib.h>

typedef struct NO{
    int codigo_aposta, acertos;
    int * numeros_apostados;
}NO;

void heapify_max ( NO** V , uint32_t Tam , uint32_t i ) {
 // Declaração dos índices
  uint32_t P = i , E = (2*i)+1 , D = (2*i)+2 ;
// Filho da esquerda é maior
  if ( E < Tam && (V[E]-> acertos) > (V[P]->acertos){ P = E ;}
 // Filho da direita é maior
  if ( D < Tam && (V[D]-> acertos) > (V[P]->acertos)){P = D ;}
// Troca e chamada recursiva
  if ( P != i ) {
  trocar (V , P , i ) ;
  heapify_max (V , Tam , P ) ;
}}
void heapify_min ( NO** V , uint32_t Tam , uint32_t i ) {
 // Declaração dos índices
  uint32_t P = i , E = (2*i)+1 , D = (2*i)+2 ;
// Filho da esquerda é maior
  if ( E < Tam && (V[E]-> acertos) < (V[P]->acertos)){ P = E ;}
 // Filho da direita é maior
  if ( D < Tam && (V [D]->acertos) < (V [P]->acertos)){P = D ;}
// Troca e chamada recursiva
  if ( P != i ) {
  trocar (V , P , i ) ;
  heapify_min (V , Tam , P ) ;
}}
void trocar (NO** V, uint32_t Pai , uint32_t i){
    uint32_t Valor_pai = V[Pai];
    uint32_t Valor_atual= V[i];
    V[i]=Valor_pai;
    V[Pai]=Valor_atual;
}
void inserir_max(NO** V, NO* Apostador,uint32_t indice){
    uint32_t tamanho=indice+1; //CRIE TAMANHO PARA OS HEAPS FORA DESSA FUNÇÃO
    V[indice] = Apostador;
    heapify_max(V,tamanho,indice);
}
void inserir_min(NO** V, NO* Apostador,uint32_t indice){
    uint32_t tamanho=indice+1;
    V[indice] = Apostador;
    heapify_min(V,tamanho,indice);
}
void extrair_MAX(NO** V, uint_32t indice_apostas, NO** Ganhadores_max, uint32_t indice_ganhadores ){
    Ganhadores_max[indice_ganhadores]=V[0];
    V[0] = V[indice_apostas];
    V[indice_apostas] = NULL;
    heapify_max(V,(indice_apostas)-1,0);
}
void extrair_MIN(NO** V, uint_32t indice_apostas, NO** Ganhadores_max, uint32_t indice_ganhadores  ){
    Ganhadores_min[indice_ganhadores]=V[0];
    V[0] = V[indice_apostas];
    V[indice_apostas] = NULL;
    heapify_min(V,(indice_apostas)-1,0);
}
int comparar(uint32_t* sorteados, uint32_t* apostados, uint32_t apostas){
    uint32_t posicao_s, posicao_a;
    uint32_t qt_acertos=0;
    //iterando para cada numero apostado
    for(posicao_a=0; posicao_a<15; posicao_a++){
        //iterando para cada numero sorteado
    for(posicao_s=0; posicao_s<15; posicao_s++){
    //comparando os numeros de cada lista
    if (sorteados[posicao_s] == apostados[posicao_a]){
        qt_acertos+=1;
        break;
    }
    else{
            continue;
        }
    }
    }


    return qt_acertos;
}

/*solução: extrair da raiz, fazer heap para subir o maior valor e parar quando nao for mais igual ao maior*/
int main(int argc, char* argv[]) {

  FILE* input = fopen(argv[1], "r");
  FILE* output = fopen(argv[2], "w");
  uint32_t premio, qt_apostadores;
  uint32_t indice=0;
  uint32_t indice_ganhadores=0;
  uint32_t* sorteados;
  uint32_t tam_max=0;
  uint32_t tam_min=0;
  NO* Apostador;
  NO** Vetor_MAX = calloc(sizeof(NO));
  NO** Vetor_MIN = calloc(sizeof(NO));
  NO** Ganhadores_max = calloc(sizeof(NO));
  NO** Ganhadores_min = calloc(sizeof(NO));
  fscanf(input,"%d ",premio);
  fscanf(input,"%d ",qt_apostadores);
  fscanf(input,"%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",sorteados[0], sorteados[1], sorteados[2], sorteados[3], sorteados[4], sorteados[5], sorteados[6], 
  sorteados[7], sorteados[8], sorteados[9], sorteados[10], sorteados[11], sorteados[12], sorteados[13], sorteados[14]);
  char* entrada, cod_aposta;
  int nums_apostados[15];
  uint32_t pontuacao=0;
  //pegando entrada
  while(fscanf(input, "%s", entrada)==1){
    //separando o codigo de aposta
    cod_aposta=strtok(entrada, " ");
    Apostador->codigo_aposta=cod_aposta;

    //pegando cada numero
    for(int indice_apostados=0,indice_apostados<15,indice_apostados++){
        nums_apostados[indice_apostados]=strtok(NULL, " ");
        //comparando com os numeros sorteados
        for (int indice_corretos=0, indice_corretos<15, indice_corretos++){
            if (nums_apostados[indice_apostados]==sorteados[indice_corretos]){
                pontuacao++
                break;
            }
        }

    }//inserindo no vetor de ponteiros
    Apostador->acertos=pontuacao;
    Apostador->numeros_apostados = nums_apostados;
    inserir_max(Vetor_MAX,Apostador,indice);
    inserir_min(Vetor_MIN,Apostador,indice);
    pontuacao=0;
    indice+=1;
  }
  //extraindo para os vetores de ganhadores
  uint32_t maior = Vetor_MAX[0] -> acertos;
  uint32_t menor = Vetor_MIN[0] -> acertos;
  while ((Vetor_MAX[0] -> acertos)== maior){
      extrair_MAX(Vetor_MAX,indice,Ganhadores_max,indice_ganhadores);
      indice_ganhadores+=1;
  }
  
  //definir premio e qt de ganhadores no max
  uint32_t ganhadores_heap_max = indice_ganhadores + 1;
  uint32_t premio_heap_max = ((premio/2)/ganhadores_heap_max);
  
  //extraindo para vetores de ganhadores
  indice_ganhadores = 0;
  while ((Vetor_MIN[0] -> acertos)== menor){
      extrair_MAX(Vetor_MIN,indice,Ganhadores_min,indice_ganhadores);
      indice_ganhadores+=1;
  }
  //definir premio e qt de ganhadores no min
  uint32_t ganhadores_heap_min = indice_ganhadores + 1;
  uint32_t premio_heap_min = ((premio/2)/ganhadores_heap_min);
  
  //printando para o arquivo de saída
fprintf(output,"[%d:%d:%d]\n",ganhadores_heap_max,maior,premio_heap_max);
for(uint32_t ganhadores=0, ganhadores<ganhadores_heap_max, ganhadores++){
  fprintf(output,"%s\n",Ganhadores_max[ganhadores] -> codigo_aposta);
}
fprintf(output,"[%d:%d:%d]\n",ganhadores_heap_min,menor,premio_heap_min);
for(uint32_t ganhadores=0, ganhadores<ganhadores_heap_min, ganhadores++){
  fprintf(output,"%s\n",Ganhadores_min[ganhadores] -> codigo_aposta);
}
fclose(input);
fclose(output);
free(Vetor_MAX);
free(Vetor_MIN);
free(Ganhadores_max);
free(Ganhadores_min);
return 0;
  }
