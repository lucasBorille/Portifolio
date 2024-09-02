#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void depositar(float *saldo) {
  float deposito;
  printf("Valor do depósito: ");
  scanf("%f", &deposito);
  if (deposito > 0) {
    printf("Depósito realizado com sucesso!\n");
    *saldo += deposito;
    sleep(2);
  } else {
    printf("Valor inválido!\n");
    sleep(2);
  }
}
void sacar(float *saldo) {
  float saque;
  printf("Valor do saque: ");
  scanf("%f", &saque);
  if (saque > 0 && saque <= *saldo) {
    *saldo -= saque;
    printf("Saque realizado com sucesso!\n");
    sleep(2);
  } else {
    printf("Valor Inválido!\n");
    sleep(2);
  }
}
void verificarSaldo(float *saldo) {
  printf("Saldo atual: R$%.2f\n", *saldo);
  sleep(2);
}

int main() {
  float saldo = 0;

  while (1 == 1) {
    system("clear");
    printf("---Menu---\n\n");
    printf("Opções:\n1-Depositar\n2-Sacar\n3-Verificar Saldo\n4-Sair\n");
    int escolha;
    scanf("%d", &escolha);
    switch (escolha) {
    case 1:
      system("clear");
      depositar(&saldo);
      break;
    case 2:
      system("clear");
      sacar(&saldo);
      break;
    case 3:
      system("clear");
      verificarSaldo(&saldo);
      break;
    case 4:
      return 0;
    default:
      system("clear");
      printf("Digite um valor válido!\n");
      sleep(2);
      system("clear");
      break;
    }
  }

  return 0;
}