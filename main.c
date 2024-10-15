#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "simple-linked-list.h"

void pressAnyKeyToContinue() {
    printf("\nPressione enter para continuar...");
    getchar();
    getchar();
}

void clearSystem() {
	system("cls");
}

int main() {
    setlocale(LC_ALL, "Portuguese"); 

    HeaderList* list = createList();
    int choice, value, search;

    printf("Uma nova lista de n�meros inteiros foi criada.\n");
    printf("\nPressione enter para continuar...");
    getchar();

    while (1) {
    	system("cls");
        printf("\nMenu:\n");
        printf("1. Inserir elemento no in�cio da lista\n");
        printf("2. Inserir elemento no final da lista\n");
        printf("3. Verificar se a lista est� vazia\n");
        printf("4. Contar elementos da lista\n");
        printf("5. Mostrar primeiro elemento da lista\n");
        printf("6. Mostrar �ltimo elemento da lista\n");
        printf("7. Buscar um elemento na lista\n");
        printf("8. Imprimir a lista\n");
        printf("9. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite um valor para adicionar no in�cio da lista: ");
                scanf("%d", &value);
                addNodeFirst(list, value);
                printf("Elemento %d adicionado no in�cio da lista.\n", value);
                break;

            case 2:
                printf("Digite um valor para adicionar no final da lista: ");
                scanf("%d", &value);
                addNodeLast(list, value);
                printf("Elemento %d adicionado no final da lista.\n", value);
                break;

            case 3:
                if (isListEmpty(list)) {
                    printf("A lista est� vazia.\n");
                } else {
                    printf("A lista n�o est� vazia.\n");
                }
                break;

            case 4:
                printf("A lista cont�m %d elementos.\n", countList(list));
                break;

            case 5:
                firstNode(list);
                break;

            case 6:
                lastNode(list);
                break;

            case 7:
                printf("Digite o valor que deseja buscar na lista: ");
                scanf("%d", &search);
                findNode(list, search);
                break;

            case 8:
                printList(list);
                break;

            case 9:
                printf("Saindo...\n");
                free(list);
                exit(0);
                break;

            default:
                printf("Op��o inv�lida! Tente novamente.\n");
                break;
        }

        pressAnyKeyToContinue();
    }
    return 0;
}
