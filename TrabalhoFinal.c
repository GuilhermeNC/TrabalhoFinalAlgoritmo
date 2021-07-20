#include <stdio.h>
#include <stdlib.h>

int ** alocaMatriz(int tam){//alocando ou reservando espaço de memória para o programa
  int ** matriz;
  matriz = (int **) calloc(tam, sizeof(int *));
  for(int i=0; i<tam; i++){
    matriz[i]=(int*) calloc(tam, sizeof(int));
  }
  return matriz;
}

void preencheMatriz(int **matriz,int tam, int qual){ //entrada de dados - inserção de informações nas matrizes
  printf("\n");
  int preenche=0;
  if(qual==1){
    for(int linha=0; linha<tam; linha++){
      for(int coluna=0; coluna<tam; coluna++){
        printf("Digite um número inteiro para preencher a Matriz Origem: ");
        scanf("%d", &preenche);
        matriz[linha][coluna]=preenche;
      }
    }
  }
  else if(qual==2){
    for(int linha=0; linha<tam; linha++){
      for(int coluna=0; coluna<tam; coluna++){
        printf("Digite um número inteiro para preencher a Matriz Fixa: ");
        scanf("%d", &preenche);
        matriz[linha][coluna]=preenche;
      }
    }
  }
}

void calculaMatriz(int ** matrizOrigem, int ** matrizFixa, int ** matrizResultante, int tamR){//processamento de dados - calculando e inserindo valores na matriz resultante
  int soma=0;
  for(int li=1; li<=tamR; li++){
    for(int co=1; co<=tamR; co++){
      soma+= (matrizOrigem[li-1][co-1] * matrizFixa[0][0]) + (matrizOrigem[li-1][co] * matrizFixa[0][1]) + (matrizOrigem[li-1][co+1] * matrizFixa[0][2]);
      soma+= (matrizOrigem[li][co-1] * matrizFixa[1][0]) + (matrizOrigem[li][co] * matrizFixa[1][1]) + (matrizOrigem[li][co+1] * matrizFixa[1][2]);
      soma+= (matrizOrigem[li+1][co-1] * matrizFixa[2][0]) + (matrizOrigem[li+1][co] * matrizFixa[2][1]) + (matrizOrigem[li+1][co+1] * matrizFixa[2][2]);
      matrizResultante[li-1][co-1]=soma;
      soma=0;
    }
  }
}

void printaMatriz(int ** matriz1, int tam1, int ** matriz2, int tam2, int ** matriz3, int tam3){ //saída de dados - mostrando as matrizes ao usuário
  printf("\n");
  printf("A Matriz Origem ficou assim: ");
  printf("\n\n");
  for(int linha=0; linha<tam1; linha++){
    for(int coluna=0; coluna<tam1; coluna++){
      printf("| %d |", matriz1[linha][coluna]);
    }
    printf("\n");
  }
  printf("\n");
  printf("A Matriz Fixa ficou assim: ");
  printf("\n\n");
  for(int linha=0; linha<tam2; linha++){
    for(int coluna=0; coluna<tam2; coluna++){
      printf("| %d |", matriz2[linha][coluna]);
    }
    printf("\n");
  }
  printf("\n");
  printf("A Matriz Resultante ficou assim: ");
  printf("\n\n");
  for(int linha=0; linha<tam3; linha++){
    for(int coluna=0; coluna<tam3; coluna++){
      printf("| %d |", matriz3[linha][coluna]);
    }
    printf("\n");
  }
}

void liberaMemoria(int ** matriz, int tam){
  for(int i=0; i<tam; i++){
        free(matriz[i]);
  }
  free(matriz);
}

int main(void) {
  
  //setando as variáveis
  int tamanho=0;
  int ** matrizOrigem;
  int ** matrizFixa;
  int ** matrizResultante;

  //entrada de dados
  printf("\n");
  printf("Digite o tamanho da matriz origem: ");
  scanf("%d", &tamanho);
  printf("\n");

  int tamanhoResultante=tamanho-2;

  //chamando as funções
  matrizOrigem = alocaMatriz(tamanho);//alocando espaço de memória
  matrizFixa = alocaMatriz(3);//alocando espaço de memória
  matrizResultante = alocaMatriz(tamanhoResultante);//alocando espaço de memória
  preencheMatriz(matrizOrigem,tamanho, 1);//entrada de dados - preenchimento da matriz
  preencheMatriz(matrizFixa, 3, 2);//entrada de dados - preenchimento da matriz
  calculaMatriz(matrizOrigem, matrizFixa, matrizResultante, tamanhoResultante);//processamento de dados - calculando os resultados para a matriz que recebe os valores
  printaMatriz(matrizOrigem, tamanho, matrizFixa, 3, matrizResultante, tamanhoResultante); //saída de dados - mostrando ao usuário como ficou cada matriz
  liberaMemoria(matrizOrigem, tamanho);//liberando espaço de memória
  liberaMemoria(matrizFixa, 3);//liberando espaço de memória
  liberaMemoria(matrizResultante, tamanhoResultante);//liberando espaço de memória
}