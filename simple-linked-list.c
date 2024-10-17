#include <stdio.h>
#include <stdlib.h>
#include "simple-linked-list.h"

// Estrutura para o n� na cabe�a da lista.
typedef struct _headerList {
	Node* begin;
	Node* end;
	int count;
} HeaderList;

// Estrutura para um n� qualquer.
typedef struct _node {
	int value;
	struct _node* next;
} Node;

// Fun��o que cria uma nova lista.
HeaderList* createList() {
    HeaderList* newList = (HeaderList*) calloc(1, sizeof(HeaderList));
    return newList;
}

// Fun��o que destroi uma lista.
void destroyList(HeaderList** header_ref){
	HeaderList* list = *header_ref;
	Node* index = list->begin;
	Node* aux = NULL;
	
	while (index != NULL){
		aux = index;
		index = index->next;
		free(aux);
	}
	free(list);
	*header_ref = NULL;
}

// Fun��o que cria um novo n� solto.
Node* createNode(int value){
	Node* newNode = (Node*) calloc(1, sizeof(Node));
	if(newNode == NULL){
		fprintf(stderr, "Erro: falha na aloca��o de mem�ria.\n");
        exit(EXIT_FAILURE);
	}
	newNode->value = value;
	return newNode;
}
	
// Fun��o que verifica se a lista est� vazia;
bool isListEmpty(HeaderList* header){
	return header->begin == NULL;
}

//Fun��o que cria um novo n� e o insere no in�cio da lista.
void addNodeFirst(HeaderList* header, int value){
	Node* newNode = createNode(value);
	if(isListEmpty(header)){
		header->begin = newNode;
		header->end = newNode;
	}else{
		Node* aux = header->begin;
		header->begin = newNode;
		newNode->next = aux;
	}
	header->count++;
}
	
// Fun��o que cria um novo n� e o insere no fim da lista.
void addNodeLast(HeaderList* header, int value){
	Node* newNode = createNode(value);
	if(isListEmpty(header)){
		header->begin = newNode;
		header->end = newNode;
	}else{
		header->end->next = newNode;
		header->end = newNode;	
	}
	header->count++;
}
	
// Fun��o que imprime uma lista.
void printList(HeaderList* header){
	if(isListEmpty(header)){
		printf("A lista est� vazia.");
	}else{
		Node* index = header->begin;
		puts("Elementos da lista:");
		while(index != NULL){
			printf("Valor: %d. \n", index->value);
			index = index->next;
		}
		puts("Fim da lista.");
	}
}
	
// Fun��o que conta quantos elementos h� na lista.
int countList(HeaderList* header){
	if(isListEmpty(header)){
		puts("A lista est� vazia.");
		return 0;
	}else{
		return header->count;
	}
}
	
// Fun��o que retorna o primeiro elemento da lista.
void firstNode(HeaderList* header){
	if(isListEmpty(header)){
		puts("A lista est� vazia.");
	}else{
	printf("Este � o primeiro elemento da sua lista: %d.", header->begin->value);
	}
}
	
// Fun��o que retorna o �ltimo elemento da lista.
void lastNode(HeaderList* header){
	if(isListEmpty(header)){
		puts("A lista est� vazia.");
	}else{
		printf("Este � o �ltimo elemento da sua lista: %d.", header->end->value);
	}
}

// Fun��o que retorna um elemento na lista buscado pelo usu�rio.
void findNode(HeaderList* header, int search){
	if(isListEmpty(header)){
		puts("A lista est� vazia. \n");
		return;
	}
	Node* index = header->begin;
	while(index != NULL){
		if(index->value == search){
			printf("O elemento %d foi encontrado na lista. \n", search);
			return;
		}
		index = index->next;
	}
	printf("O elemento %d n�o foi encontrado na lista. \n", search);
}
	
// Fun��o que apaga um, e somente um, elemento da lista.
void removeNode(HeaderList* header, int search){
	if(isListEmpty(header)){
		puts("A lista est� vazia.");
		return;
	}
	Node* index = header->begin;
	Node* aux = NULL;
	
	while(index != NULL && index->value != search){
		aux = index;
		index = index->next;
	}
	
	if(index == NULL){
		printf("Elemento %d n�o encontrado.\n", search);
	}else{
		// Verificando se o elemento est� no final da lista
		if(index == header->end){
			header->end = aux;
		}
		// Verificando se o elemento est� no in�cio da lista
		if(index == header->begin){
			header->begin = index->next;
		}else{
			aux->next = index->next;
		}
		free(index);
	}
	header->count--;
}
