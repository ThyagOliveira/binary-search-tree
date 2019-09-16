#include <stdio.h>
#include <stdlib.h>


void menu() {
    int option;
    printf("\n\n\t\tMenu de Opções");
    printf("\n\n\t\t01. Recarregar arquivo");
    printf("\n\n\n\t\t02. Listar todos os nomes em ordem alfabética");
    printf("\n\n\n\t\t03. Listar todos os nomes que contém uma substring fornecida");
    printf("\n\n\n\t\t04. Inserir um novo nome na memória");
    printf("\n\n\n\t\t05. Remover um nome da memória");
    printf("\n\n\n\t\t06. Listar e remover da memória todos os nomes que são maiores, em ordem alfabética, que um nome fornecido");
    printf("\n\n\n\t\t07. Listar e remover da memória todos os nomes que são menores, em ordem alfabética, que um nome fornecido");
    printf("\n\n\n\t\t08. Salvar o conteúdo da memória em um arquivo texto");
    printf("\n\n\n\t\t09. Créditos");
    printf("\n\n\n\t\t10. Sair");
    printf("\n\n\t\tEscolha a opção(Apenas Números): ");

    scanf("%d", &option);    

    switch (option) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    case 10:
        break;
    default:
        system("clear");
        return menu();
        break;
    }
}

int main(int argc, char *argv[]) {    
    menu();
    return 0;    
}

