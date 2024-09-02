#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct login{
  char login[20];
  char senha[20];

};

void inside(char nome[],int *i,int *qtd,struct login logins[]){
    printf("\nBem vindo %s!\n\n",nome);
    *i = 1;
    printf("---Logins---\n");
    for (int j = 0; j<*qtd;j++){
        printf("%d | Login:%s  Senha:%s\n",j+1,logins[j].login,logins[j].senha);
    }
}

int registro(struct login logins[], int *qtd){
    printf("Digite seu login: ");
    scanf("%s",logins[*qtd].login);
    for (int i=0;i<5;i++){
        if(strcmp(logins[*qtd].login,logins[i].login)==0 && i!=*qtd){
            printf("Login ja existente!");
           sleep(2);
           system("clear");
            return 0;
        }else{
            printf("Digite sua senha: ");
            scanf("%s",logins[*qtd].senha);
            *qtd+=1;
            printf("Registro completo com sucesso!\n");
            sleep(2);
            system("clear");
            return 0;
        }
    }
}

void login(struct login logins[], int *verif, int *qtd){
    char logint[20],senhat[20];
    printf("Login: ");
    scanf("%s",logint);
    printf("Senha: ");
    scanf("%s",senhat);
    int i,loginv=0;
    for (i=0;i<5;i++){
        if (strcmp(logint,logins[i].login)==0){
            loginv = 1;
            if (strcmp(senhat,logins[i].senha)==0){
                printf("Login feito com sucesso!\n");
                sleep(2);
                system("clear");
                inside(logins[i].login, &*verif,&*qtd,logins);
            }else {
                printf("Senha incorreta!\n");
                sleep(2);
                system("clear");
            }   
        }
        }
        if (loginv == 0){
            printf("Login inexistente!\n");
            sleep(2);
            system("clear");
            i = 5;
    }
}


int main() {
    int i=0,escolha,qtd = 0;
    struct login logins[5];
    while(i==0){
        printf("---MENU---\n\n1-Login\n2-Registrar-se\n3-Sair\n");
        scanf("%d",&escolha);
        switch(escolha){
            case 1:login(logins,&i,&qtd);break;
            case 2:registro(logins,&qtd);break;
            case 3:printf("Obrigado!");i = 1; break;
            default:printf("Digite um valor válido\n");sleep(2);system("clear");
        }
    }

    return 0;
}