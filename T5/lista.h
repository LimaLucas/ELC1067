/*
 * lista.h
 * Funções de TAD lista duplamente encadeada.
 *
 */
#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdlib.h>
#include "memo.h"

typedef struct _line {
	char* text;
	struct _line* prev;
	struct _line* next;
} line;

typedef struct _begend {
	line* first;
	line* last;
} begend;

/* Inicialization of the list */
begend* createList(void);

void destroyList(begend* list);

begend* insertList(begend* list, int pos);

line* serchList(begend* list, int pos);

begend* removeList(begend* list, int pos);


#endif /* _LISTA_H_ */
