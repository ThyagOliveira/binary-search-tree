#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

void add_name(Tree * tree) {
    char * name = (char *) malloc(40 * sizeof(char));
    printf("Insira o nome a ser adicionado: ");
    scanf("%s", name);
    fflush(stdin);
    add_node(tree, name);
    free(name);
}

void remove_name(Tree * tree) {
    char * name = (char *) malloc(40 * sizeof(char));
    printf("Insira o nome a ser removido: ");    
    scanf("%s", name);
    fflush(stdin);
    remove_node(tree, name);        
    free(name);
}

void remove_name_biggest(Tree * tree) {
    char * name = (char *) malloc(40 * sizeof(char));
    printf("Insira o nome: ");
    scanf("%s", name);    
    fflush(stdin);
    remove_node_biggest(tree, name);
    print_tree(tree);
    free(name);
}

void remove_name_smallest(Tree * tree) {
    char * name = (char *) malloc(40 * sizeof(char));
    printf("Insira o nome: ");
    scanf("%s", name);    
    fflush(stdin);
    remove_node_smallest(tree, name);
    print_tree(tree);
    free(name);
}

void list_name_substring(Tree * tree) {
    char * substring = (char *) malloc(40 * sizeof(char));
    printf("Listar todos os nomes que contem uma substring fornecida\n");
    printf("Insira a substring:\n");
    scanf("%s", substring);
    print_substring(tree, substring);
    free(substring);
}
void menu(Tree * tree) {
    int option = -1;    

    while(option != 10) {
        printf("\n\n\t\tMenu de Opções");
        printf("\n01. Recarregar arquivo");
        printf("\n02. Listar todos os nomes em ordem alfabética");
        printf("\n03. Listar todos os nomes que contém uma substring fornecida");
        printf("\n04. Inserir um novo nome na memória");
        printf("\n05. Remover um nome da memória");
        printf("\n06. Listar e remover da memória todos os nomes que são maiores, em ordem alfabética, que um nome fornecido");
        printf("\n07. Listar e remover da memória todos os nomes que são menores, em ordem alfabética, que um nome fornecido");
        printf("\n08. Salvar o conteúdo da memória em um arquivo texto");
        printf("\n09. Créditos");
        printf("\n10. Sair");
        printf("\nEscolha a opção(Apenas Números): ");

        scanf("%d", &option);    

        switch (option) {
        case 1:        
            break;
        case 2:
            print_tree(tree);
            break;
        case 3:
            list_name_substring(tree);
            break;
        case 4:    
            add_name(tree);
            break;
        case 5:
            remove_name(tree);            
            break;
        case 6:
            remove_name_biggest(tree);
            break;
        case 7:
            remove_name_smallest(tree);
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        default:
            system("clear");
            return menu(tree);
            break;
        }

    }    
}

int main(int argc, char *argv[]) {    
    Tree * tree = create();    
    add_node(tree, "ana");
    add_node(tree, "bruno");
    add_node(tree, "caio");
    add_node(tree, "lucas");
    menu(tree);
    return 0;    
}

