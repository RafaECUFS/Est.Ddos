// Numeros padronizados
#include <stdint.h>
// Biblioteca padrao
#include <stdlib.h>
// Entrada/saida padrao
#include <stdio.h>
// Strings
#include <string.h>

//estrutura arvore
typedef struct no_arv{
    char[51] nome_arq;
    char[3] tipo;
    char * tamanho;
    int ordem;
    struct no_arv* right;
    struct no_arv* left;
}no_arv

/* atribuir a cada iteração
char * string = "hello world"; 
  int i;
  char * copia = (char*)malloc(11*sizeof(char));
  for (i=0; i < 11; i++) {
    copia[i] = string[i];    
} */

const char* trata_caixa_alta_baixa(char * info){
  int indice = 0;
  char * copia = (char*)malloc(strlen(info)*sizeof(char));
  while(info[indice]!='\0') {
  if(info[indice] >= 'a' && info[indice] <= 'z'){
      copia[indice] = info[indice]-32;}
  else{copia[indice]=info[indice];}
  i++;
}
    return copia;
}


void inserir(no_arv * arvore, no_arv param_busca, char* copia_para_comparar, int ordenacao ){
  no_arv * node;
  char* copia_nome_arvore = trata_caixa_alta_baixa(*arvore->nome_arq);
  if (*arvore!=NULL){
    if (copia_nome_arvore>copia_para_comparar){inserir(*arvore->left, param_busca, copia_para_comparar);}
    if (copia_nome_arvore<copia_para_comparar){inserir(*arvore->right, param_busca, copia_para_comparar);}
    if (copia_nome_arvore==copia_para_comparar){
      if (*arvore->tipo=="rw"){
      node->ordem = ordenacao;
      node->nome_arq=param_busca->nome_arq;
      node->tipo=param_busca->tipo;
      node->tamanho=param_busca->tamanho;
      if(tamanho!='1'){strcat(tamanho," byte");}
      else{strcat(tamanho, " bytes");}}
      else{inserir(*arvore->left, param_busca, copia_para_comparar);}
    }
  }
  else{node=(no_arv)malloc(sizeof(no_arv));
  node->ordem = ordenacao;
  node->nome_arq=param_busca->nome_arq;
  node->tipo=param_busca->tipo;
  node->tamanho=param_busca->tamanho;
  if(tamanho!='1'){strcat(tamanho," byte");}
  else{strcat(tamanho, " bytes");} }
}

void percorrer_epd(no_arv * arvore){

}
void percorrer_ped(no_arv * arvore){

}
void percorrer_edp(no_arv * arvore){

}
//criar função onde string só exista localmente e seja chamada a cada nova entrada do input

int main(int argc, char* argv[]) {
  FILE* input = fopen(argv[1], "r");
	FILE* output = fopen(argv[2], "w");
  char * entrada;
// declara string e cria copia para comparar
  int ordenacao = 0;
  char * string = "HEllO worlD~2";
  char* copia_para_comparar = trata_caixa_alta_baixa(string);
  while (input){
    /*"string = fgets(input)"
    funcao inserir
    ordenacao++;
    */

  }
	// Fechando os arquivos
	fclose(input);
	fclose(output);
	// Finalizando programa
	return 0;}
