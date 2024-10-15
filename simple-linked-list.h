#ifndef SIMPLELINKEDLIST
#define SIMPLELINKEDLIST
#include <stdbool.h>
// Estrutura para o n� na cabe�a da lista.
typedef struct _headerList HeaderList;

// Estrutura para um n� qualquer.
typedef struct _node Node;

// Fun��o que cria uma nova lista.
HeaderList* createList();

// Fun��o que cria um novo n� solto.
Node* createNode(int value);

// Fun��o que verifica se a lista est� vazia;
bool isListEmpty(HeaderList* header);

// Fun��o que cria um novo n� e o insere no in�cio da lista.
void addNodeFirst(HeaderList* header, int value);

// Fun��o que cria um novo n� e o insere no fim da lista.
void addNodeLast(HeaderList* header, int value);

// Fun��o que imprime uma lista.
void printList(HeaderList* header);

// Fun��o que conta quantos elementos h� na lista.
int countList(HeaderList* header);

// Fun��o que retorna o primeiro elemento da lista.
void firstNode(HeaderList* header);

// Fun��o que retorna o �ltimo elemento da lista.
void lastNode(HeaderList* header);

// Fun��o que retorna um elemento na lista buscado pelo usu�rio.
void findNode(HeaderList* header, int search);

#endif
