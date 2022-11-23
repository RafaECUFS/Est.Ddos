#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NO{
    int acertos;
    char* codigo_aposta;

}NO;


void trocar (NO** V, int Pai , int i){
    NO* Valor_pai = (NO*)calloc(1,sizeof(NO));
    NO* Valor_atual = (NO*)calloc(1,sizeof(NO));
    Valor_pai -> codigo_aposta = (char*) calloc(17,sizeof(char));
    Valor_atual -> codigo_aposta = (char*) calloc(17,sizeof(char));
    Valor_atual ->acertos = V[i]->acertos;
    Valor_pai ->acertos= V[Pai]->acertos;
    V[Pai]->acertos = Valor_atual->acertos;
    V[i]->acertos= Valor_pai->acertos;
    strcpy(Valor_atual->codigo_aposta,V[i]->codigo_aposta);
    strcpy(Valor_pai -> codigo_aposta,V[Pai]->codigo_aposta);
    strcpy(V[Pai]->codigo_aposta,Valor_atual->codigo_aposta);
    strcpy( V[i]-> codigo_aposta,Valor_pai->codigo_aposta);
}
//fazer heapify depois de constrir os heaps
void heapify_max ( NO** V , int Tam , int i ) {
 // Declaração dos índices
  int P = i , E = (2*i)+1 , D = (2*i)+2 ;
// Filho da esquerda é maior
  if ( E < Tam && (V[E]-> acertos) > (V[P]->acertos)){ P = E ;}
 // Filho da direita é maior
  if ( D < Tam && (V[D]-> acertos) > (V[P]->acertos)){P = D ;}
// Troca e chamada recursiva
  if ( P != i ) {
     trocar (V , P , i );
     if (i>0){
     heapify_max (V , Tam , i-1 ) ;}
}}
void heapify_min ( NO** V , int Tam , int i ) {
 // Declaração dos índices
  int P = i;
  int E = (2*i)+1;
  int D = (2*i)+2 ;
// Filho da esquerda é maior
  if ( E < Tam && (V[E]-> acertos) < (V[P]->acertos)){ P = E ;}
 // Filho da direita é maior
  if ( D < Tam && (V [D]->acertos) < (V [P]->acertos)){P = D ;}
// Troca e chamada recursiva
  if ( P != i ) {
  trocar (V , P , i ) ;
  if (i>0){
  heapify_min (V , Tam , i-1 ) ;}
}}

void extrair_MAX(NO** V, int indice_apostas, NO** Ganhadores_max, int indice_ganhadores ){
    strcpy((Ganhadores_max[indice_ganhadores]->codigo_aposta),(V[0]->codigo_aposta));
    strcpy((V[0]->codigo_aposta),V[indice_apostas]->codigo_aposta);
    int pontos = (V[indice_apostas]->acertos);
    V[0]->acertos = pontos;
    indice_apostas-=1;
    int Pai= (indice_apostas-1)/2;
    heapify_max(V,indice_apostas,Pai);
}
void extrair_MIN(NO** V, int indice_apostas, NO** Ganhadores_min, int indice_ganhadores ){
    strcpy((Ganhadores_min[indice_ganhadores]->codigo_aposta),(V[0]->codigo_aposta));
    strcpy((V[0]->codigo_aposta),V[indice_apostas]->codigo_aposta);
    int pontos = (V[indice_apostas]->acertos);
    V[0]->acertos = pontos;
    indice_apostas-=1;
    int Pai= (indice_apostas-1)/2;
    heapify_min(V,indice_apostas,Pai);
}


//solução: extrair da raiz, fazer heap para subir o maior valor e parar quando nao for mais igual ao maior
int main(int argc, char* argv[]){

  FILE* input = fopen(argv[1], "r");
  if(input == NULL){printf("ERRO!");
    fclose(input);
    return 0;}
  FILE* output = fopen(argv[2], "w");
  int premio=0, qt_apostadores=0, num_apostado=0,maior=0,menor=0,indice_ganhadores=0;
  int sorteados[10];
  int tam_max=0,tam_min=0, N_ganhadores_max = 0, N_ganhadores_min = 0;
  fscanf(input,"%d",premio);
  fscanf(input,"%d",qt_apostadores);
  for(int i=0;i<10;i++){
    fscanf(input,"%d",sorteados[i]);
  }

  NO** Vetor_MAX =(NO**) calloc(qt_apostadores,sizeof(NO*));
  NO** Vetor_MIN = (NO**) calloc(qt_apostadores,sizeof(NO*));
  char* entrada;
  int indice=0,pontuacao=0,num_maior=0,num_menor=15;
  //pegando entrada

  while(fscanf(input, "%s", entrada)==1){
    //alocando memoria e copiando o codigo de aposta para o nó
    Vetor_MAX[indice] = (NO*)calloc(1,sizeof(NO));
    Vetor_MIN[indice] = (NO*)calloc(1,sizeof(NO));
    Vetor_MAX[indice]->codigo_aposta= (char*) calloc(17,sizeof(char));
    Vetor_MIN[indice]->codigo_aposta= (char*) calloc(17,sizeof(char));
    strcpy((Vetor_MAX[indice]->codigo_aposta),entrada);
    strcpy((Vetor_MIN[indice]->codigo_aposta),entrada);

    //pegando cada numero
    for(int indice_apostados=0;indice_apostados<15;indice_apostados++){
        fscanf(input,"%d",num_apostado);
        /*nums_apostados[indice_apostados]=(int*)malloc(sizeof(int));
        nums_apostados[indice_apostados]= num_apostado;*/
        //comparando com os numeros sorteados
        for (int indice_corretos=0; indice_corretos<10; indice_corretos++){
            if (num_apostado==sorteados[indice_corretos]){
                pontuacao++;
                break;}}}
    //conferindo qual o maior/menor valor de acertos e a quantidade de vencedores
    if(num_maior==pontuacao){maior++;}
    else{
      if(num_maior<pontuacao){maior=1;
    num_maior=pontuacao;}}
    if(num_menor==pontuacao){menor++;}
    else{if(num_menor<pontuacao){menor=1;
    num_menor=pontuacao;}}
    Vetor_MAX[indice]->acertos=pontuacao;
    Vetor_MIN[indice]->acertos=pontuacao;
    indice+=1;}

    //construção do heap e qt de acertos vencedora
    int ultimo_no_interno = (qt_apostadores -1)/2;
    heapify_max(Vetor_MAX,qt_apostadores,(ultimo_no_interno));
    //maior = (Vetor_MAX[0] -> acertos);//onde tiver ponteiros, faça copia dos valores
    heapify_min(Vetor_MIN,qt_apostadores,(ultimo_no_interno));
    //menor = Vetor_MIN[0] -> acertos;

    NO** Ganhadores_max = (NO**)calloc(maior,sizeof(NO*));
    NO** Ganhadores_min = (NO**)calloc(menor,sizeof(NO*));


  //extraindo para os vetores de ganhadores
  while ((Vetor_MAX[0] -> acertos)== num_maior){
      Ganhadores_max[indice_ganhadores] = (NO*)calloc(1,sizeof(NO));
      Ganhadores_max[indice_ganhadores]->codigo_aposta= (char*) malloc(sizeof(char)*17);
      extrair_MAX(Vetor_MAX,indice,Ganhadores_max,indice_ganhadores);
      indice_ganhadores+=1;
  }

  //definir premio e qt de ganhadores no max
  int ganhadores_heap_max = indice_ganhadores + 1;
  int premio_heap_max = ((premio/2)/ganhadores_heap_max);

  //extraindo para vetores de ganhadores
  indice_ganhadores = 0;
  while ((Vetor_MIN[0] -> acertos)== num_menor){
      Ganhadores_min[indice_ganhadores] = (NO*)calloc(1,sizeof(NO));
      Ganhadores_min[indice_ganhadores]->codigo_aposta= (char*) malloc(sizeof(char)*17);
      extrair_MIN(Vetor_MIN,indice,Ganhadores_min,indice_ganhadores);
      indice_ganhadores+=1;
  }
  //definir premio e qt de ganhadores no min
  int ganhadores_heap_min = indice_ganhadores + 1;
  int premio_heap_min = ((premio/2)/ganhadores_heap_min);

  //printando para o arquivo de saída
fprintf(output,"[%d:%d:%d]\n",ganhadores_heap_max,num_maior,premio_heap_max);
for(int ganhadores=0; ganhadores<ganhadores_heap_max; ganhadores++){
  fprintf(output,"%s\n",(Ganhadores_max[ganhadores] -> codigo_aposta));
}
fprintf(output,"[%d:%d:%d]\n",ganhadores_heap_min,num_menor,premio_heap_min);
for(int ganhadores=0; ganhadores<ganhadores_heap_min; ganhadores++){
  fprintf(output,"%s\n",(Ganhadores_min[ganhadores] -> codigo_aposta));
}
fclose(input);
fclose(output);
free(Vetor_MAX);
free(Vetor_MIN);
free(Ganhadores_max);
free(Ganhadores_min);
return 0;}
