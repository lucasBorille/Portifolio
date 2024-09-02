#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
int main() {
  int ver = 0;
  while (ver == 0) {
    // tela menu
    printf("-----JOGO DA MEMORIA----\n\n\n");
    printf("-Digite o numero da opcao desejada:\n\n");
    printf("1-JOGAR\n2-REGRAS\n3-SAIR\n");
    int opc, voltar = 0;
    scanf("%d", &opc);
    switch (opc) {
    case 1:
      system("clear");
      ver = 1;
      break;
    case 2:
      system("clear");
      printf("----REGRAS----\n\n\n\n");
      printf(
          "1-As tabelas do jogo sao formadas por coordenadas(linhas,colunas) "
          "iniciadas em 0 em terminadas no numero anterior ao digitado pelo "
          "jogador.\n\n2-O resultado da multiplicacao entre o numero de linhas "
          "e o numero de colunas deve ser par.");
      printf("\n\n3-O resultado da multiplicacao entre o numero de linhas e o "
             "numero de colunas deve ser menor ou igual a 52(numero de letras "
             "do alfabeto x 2).");
      printf("\n\n4-O jogador tera um numero de tentativas igual a metade de "
             "espacos da tabela.");
      printf("\n\n\nDigite 1 para voltar para o menu:\n");
      scanf("%d", &voltar);
      system("clear");
      break;
    case 3:
      printf("Tchau!");
      return 0;
    }
  }

  // criando tabela
  int nlinhas, ncolunas;

  printf("Numero de linhas da tabela:\n");
  scanf("%d", &nlinhas);
  printf("Numero de colunas da tabela:\n");
  scanf("%d", &ncolunas);
  // verificar se é par
  if ((nlinhas * ncolunas) % 2 != 0 || nlinhas * ncolunas > 52) {
    printf("Nao eh possivel fazer o jogo da memoria, tente novamente com "
           "numeros pares e menores!");
    return 0;
  }

  // preenchendo a matriz com zeros
  char matriz[nlinhas][ncolunas];
  int i, j;

  for (i = 0; i < nlinhas; i++) {
    for (j = 0; j < ncolunas; j++) {
      matriz[i][j] = '0';
    }
  }

  // preenchendo aleatoriamente a matriz
  int randlinha, randcoluna;
  srand(time(NULL));
  char alfabeto[] = "AABBCCDDEEFFGGHHIIJJKKLLMMNNOOPPQQRRSSTTUUVVWWXXYYZZ";
  i = 0;
  while (i < nlinhas * ncolunas) {
    randlinha = rand() % nlinhas;
    randcoluna = rand() % ncolunas;
    if (matriz[randlinha][randcoluna] == '0') {
      matriz[randlinha][randcoluna] = alfabeto[i];
      i++;
    }
  }

  printf("\nteste matriz\n");
  for (i = 0; i < nlinhas; i++) {
    for (j = 0; j < ncolunas; j++) {
      printf("%c  ", matriz[i][j]);
    }
    printf("\n");
  }
  sleep((nlinhas * ncolunas) / 16);
  system("clear");
  char jogador[nlinhas][ncolunas];
  for (i = 0; i < nlinhas; i++) {
    for (j = 0; j < ncolunas; j++) {
      jogador[i][j] = '*';
    }
  }
  for (i = 0; i < nlinhas; i++) {
    for (j = 0; j < ncolunas; j++) {
      printf("%c  ", jogador[i][j]);
    }
    printf("\n");
  }
  // jogabilidade
  int vida = (nlinhas * ncolunas) / 2;
  int pontos = 0;
  int xcarta1, ycarta1, xcarta2, ycarta2;
  printf("Voce tem %d vidas!\n", vida);
  while (pontos < (nlinhas * ncolunas) / 2) {
    printf("Escreva as coordenadas da primeira carta:\n");
    scanf("%d %d", &xcarta1, &ycarta1);
    jogador[xcarta1][ycarta1] = matriz[xcarta1][ycarta1];
    for (i = 0; i < nlinhas; i++) {
      for (j = 0; j < ncolunas; j++) {
        printf("%c  ", jogador[i][j]);
      }
      printf("\n");
    }

    printf("Escreva as coordenadas da segunda carta:\n");
    scanf("%d %d", &xcarta2, &ycarta2);
    jogador[xcarta2][ycarta2] = matriz[xcarta2][ycarta2];
    for (i = 0; i < nlinhas; i++) {
      for (j = 0; j < ncolunas; j++) {
        printf("%c  ", jogador[i][j]);
      }
      printf("\n");
    }

    if (matriz[xcarta1][ycarta1] == matriz[xcarta2][ycarta2]) {
      printf("ACERTOU MIZERAVI\n");
      pontos++;
    } else {
      printf("errrrrrou!\n");
      sleep(1);
      system("clear");
      jogador[xcarta1][ycarta1] = '*';
      jogador[xcarta2][ycarta2] = '*';
      for (i = 0; i < nlinhas; i++) {
        for (j = 0; j < ncolunas; j++) {
          printf("%c  ", jogador[i][j]);
        }
        printf("\n");
      }
      vida--;
      printf("Voce tem %d vidas\n", vida);
    }
    if (vida <= 0) {
      printf("Suas vidas acabaram!");
      return 0;
    }
  }

  printf("\nACABOU!");

  return 0;
}