#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tanques
{
        char nome[30];
        float capacidade,valor;
};


void main ()
{
    char escolha=0,escolha3=0;
    int escolha1=5;
    float real;
    struct Tanques Tanque[3];
    float caixa=0;

    strcpy(Tanque[0].nome,"Gasolina Aditivada"); Tanque[0].capacidade=300.000; Tanque[0].valor=4.49;
    strcpy(Tanque[1].nome,"Gasolina Comum"); Tanque[1].capacidade=300.000; Tanque[1].valor=4.1;
    strcpy(Tanque[2].nome,"Etanol"); Tanque[2].capacidade=300.000; Tanque[2].valor=3.01;
    while(escolha!='S')
    {
    do{
    printf("\nEscolha uma opcao\n");
    printf("1\t Abastecer\n");
    printf("2\t Estoque\n");
    printf("3\t Caixa\n");
    printf("S\t Sair\n");
    fflush(stdin);
    scanf("%s",&escolha);
    system("cls");
    if((escolha!='1')&&(escolha!='2')&&(escolha!='3')&&(escolha!='S'))
    printf("Escolha invalida, digite novamente\n");
    }while((escolha!='1')&&(escolha!='2')&&(escolha!='3')&&(escolha!='S'));

    switch (escolha)
    {
        case '1':
            do{
            printf("\nN\t Tipo de combustivel\tCapacidade do Tanque\tValor\n");
            printf("\n1\t %s\t%.3f lts\t        R$%.3f",Tanque[0].nome,Tanque[0].capacidade,Tanque[0].valor);
            printf("\n2\t %s\t        %.3f lts\t        R$%.3f",Tanque[1].nome,Tanque[1].capacidade,Tanque[1].valor);
            printf("\n3\t %s\t                %.3f lts\t        R$%.3f\n",Tanque[2].nome,Tanque[2].capacidade,Tanque[2].valor);
            printf("Digite o numero do combustivel que deseja:");
            fflush(stdin);
            scanf("%d",&escolha1);
            system("cls");
            if(escolha1<1||escolha1>3)
            printf("Escolha invalida, digite novamente\n");
            }while(escolha1<1||escolha1>3);

            escolha1=escolha1-1;

            do{
            printf("\nCombustivel selecionado: %s\nValor: %.3f",Tanque[escolha1].nome,Tanque[escolha1].valor);
            printf("\nDigite quantos reais deseja abastecer:");
            scanf("%f",&real);

            system("cls");

            if((Tanque[escolha1].capacidade - (real/Tanque[escolha1].valor))<0)
                printf("Capacidade insuficiente, escolha outra valor");
            if(real<0)
                printf("Valor invalido, digite novamente");
            }while(real<0||(Tanque[escolha1].capacidade - (real/Tanque[escolha1].valor))<0);

            if((Tanque[escolha1].capacidade - (real/Tanque[escolha1].valor))>0){
            Tanque[escolha1].capacidade=Tanque[escolha1].capacidade - (real/Tanque[escolha1].valor);
            caixa=caixa+real;}
            break;


        case '2':
            printf("\n Tipo de combustivel\tCapacidade do Tanque\n");
            printf("\n %s\t%.3f lts",Tanque[0].nome,Tanque[0].capacidade);
            printf("\n %s\t        %.3f lts",Tanque[1].nome,Tanque[1].capacidade);
            printf("\n %s\t                %.3f lts\n",Tanque[2].nome,Tanque[2].capacidade);
            system("pause");
            system("cls");
            break;
        case '3':
            printf("\nValor armazenado no caixa: %.2f\n",caixa);
            system("pause");
            if(caixa>0)
            {
                printf("\nDeseja fechar o caixa(S/N):");
                fflush(stdin);
                scanf("%s",&escolha3);
                if(escolha3=='S');
                caixa=0;

            }
            system("cls");
            break;
    }
    }
}

