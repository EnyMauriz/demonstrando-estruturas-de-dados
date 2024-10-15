#ifndef SIMPLELINKEDLIST
#define SIMPLELINKEDLIST
#include <stdbool.h>
// Estrutura para o nó na cabeça da lista.
typedef struct _headerList HeaderList;

// Estrutura para um nó qualquer.
typedef struct _node Node;

// Função que cria uma nova lista.
HeaderList* createList();

// Função que cria um novo nó solto.
Node* createNode(int value);

// Função que verifica se a lista está vazia;
bool isListEmpty(HeaderList* header);

// Função que cria um novo nó e o insere no início da lista.
void addNodeFirst(HeaderList* header, int value);

// Função que cria um novo nó e o insere no fim da lista.
void addNodeLast(HeaderList* header, int value);

// Função que imprime uma lista.
void printList(HeaderList* header);

// Função que conta quantos elementos há na lista.
int countList(HeaderList* header);

// Função que retorna o primeiro elemento da lista.
void firstNode(HeaderList* header);

// Função que retorna o último elemento da lista.
void lastNode(HeaderList* header);

// Função que retorna um elemento na lista buscado pelo usuário.
void findNode(HeaderList* header, int search);

#endif
