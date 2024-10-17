#include <stdio.h>
#include <stdlib.h>
#include "simple-linked-list.h"

// Estrutura para o nó na cabeça da lista.
typedef struct _headerList {
	Node* begin;
	Node* end;
	int count;
} HeaderList;

// Estrutura para um nó qualquer.
typedef struct _node {
	int value;
	struct _node* next;
} Node;

// Função que cria uma nova lista.
HeaderList* createList() {
    HeaderList* newList = (HeaderList*) calloc(1, sizeof(HeaderList));
    return newList;
}

// Função que destroi uma lista.
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

// Função que cria um novo nó solto.
Node* createNode(int value){
	Node* newNode = (Node*) calloc(1, sizeof(Node));
	if(newNode == NULL){
		fprintf(stderr, "Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
	}
	newNode->value = value;
	return newNode;
}
	
// Função que verifica se a lista está vazia;
bool isListEmpty(HeaderList* header){
	return header->begin == NULL;
}

//Função que cria um novo nó e o insere no início da lista.
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
	
// Função que cria um novo nó e o insere no fim da lista.
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
	
// Função que imprime uma lista.
void printList(HeaderList* header){
	if(isListEmpty(header)){
		printf("A lista está vazia.");
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
	
// Função que conta quantos elementos há na lista.
int countList(HeaderList* header){
	if(isListEmpty(header)){
		puts("A lista está vazia.");
		return 0;
	}else{
		return header->count;
	}
}
	
// Função que retorna o primeiro elemento da lista.
void firstNode(HeaderList* header){
	if(isListEmpty(header)){
		puts("A lista está vazia.");
	}else{
	printf("Este é o primeiro elemento da sua lista: %d.", header->begin->value);
	}
}
	
// Função que retorna o último elemento da lista.
void lastNode(HeaderList* header){
	if(isListEmpty(header)){
		puts("A lista está vazia.");
	}else{
		printf("Este é o último elemento da sua lista: %d.", header->end->value);
	}
}

// Função que retorna um elemento na lista buscado pelo usuário.
void findNode(HeaderList* header, int search){
	if(isListEmpty(header)){
		puts("A lista está vazia. \n");
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
	printf("O elemento %d não foi encontrado na lista. \n", search);
}
	
// Função que apaga um, e somente um, elemento da lista.
void removeNode(HeaderList* header, int search){
	if(isListEmpty(header)){
		puts("A lista está vazia.");
		return;
	}
	Node* index = header->begin;
	Node* aux = NULL;
	
	while(index != NULL && index->value != search){
		aux = index;
		index = index->next;
	}
	
	if(index == NULL){
		printf("Elemento %d não encontrado.\n", search);
	}else{
		// Verificando se o elemento está no final da lista
		if(index == header->end){
			header->end = aux;
		}
		// Verificando se o elemento está no início da lista
		if(index == header->begin){
			header->begin = index->next;
		}else{
			aux->next = index->next;
		}
		free(index);
	}
	header->count--;
}
