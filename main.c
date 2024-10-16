#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "simple-linked-list.h"

void pressEnterToContinue() {
    printf("\nPressione enter para continuar...");
    getchar();
    getchar();
}

void clearSystem() {
    system("cls");
}

int main() {
    setlocale(LC_ALL, "Portuguese"); 

    HeaderList* list = createList();  // Cria��o da lista
    int choice, value, search;

    printf("Uma nova lista de n�meros inteiros foi criada.\n");
    printf("\nPressione enter para continuar...");
    getchar();

    while (1) {
        clearSystem();  // Limpa a tela
        printf("\nMenu:\n");
        printf("1. Inserir elemento no in�cio da lista\n");
        printf("2. Inserir elemento no final da lista\n");
        printf("3. Verificar se a lista est� vazia\n");
        printf("4. Contar elementos da lista\n");
        printf("5. Mostrar primeiro elemento da lista\n");
        printf("6. Mostrar �ltimo elemento da lista\n");
        printf("7. Buscar um elemento na lista\n");
        printf("8. Imprimir a lista\n");
        printf("9. Remover um elemento da lista\n");  // Nova op��o para remover elemento
        printf("10. Sair\n");  // Mudan�a no n�mero da op��o "Sair"
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
                // Nova op��o para remover elemento
                printf("Digite o valor que deseja remover da lista: ");
                scanf("%d", &search);
                removeNode(list, search);  // Chama a fun��o para remover o n�
                printf("Elemento %d removido da lista.\n", search);
				break;

            case 10:
                printf("Saindo...\n");
                destroyList(&list);  // Destroi a lista ao sair
                return 0;  // Sai do programa

            default:
                printf("Op��o inv�lida! Tente novamente.\n");
                break;
        }

        pressEnterToContinue();  // Pausa para continuar
    }
    return 0;
}
