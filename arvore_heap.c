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
    tamanho=i+1; //CRIE TAMANHO PARA OS HEAPS FORA DESSA FUNÇÃO
    V[indice] = Apostador;
    heapify_max(V,tamanho,indice);
}
void inserir_min(NO** V, NO* Apostador,uint32_t indice){
    tamanho=i+1;
    V[indice] = Apostador;
    heapify_min(V,tamanho,indice);
}
void extrair_MAX(NO** V, int Tam, NO** Ganhadores_max){
    Tam-=1;
    Ganhadores_max[]=
}
int comparar(uint32_t* sorteados, uint32_t* apostados, uint32_t apostas){
    uint32_t posicao_s, posicao_a;
    uint32_t qt_acertos=0;
    //iterando para cada numero apostado
    for(posicao_a=0, posicao_a<15, posicao_a++){
        //iterando para cadanumero sorteado
    for(posicao_s=0, posicao_s<15, posicao_s++){
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
  uint32_t premio, qt_apostadores, ;
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

    }
    Apostador->acertos=pontuacao;
    Apostador->numeros_apostados = nums_apostados;
    //INSERIR A APOSTA NA ARVORE
    //AUMENTAR O VALOR DA VARIAVEL TAMANHO
    pontuacao=0;


  }

  
  
  

  /*Contar quantos acertos em cada entrada e, se for maior/menor, atribuir a max/min_acert*/
  
  }
