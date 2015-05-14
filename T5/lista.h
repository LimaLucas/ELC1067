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

typedef struct _list {
	line* first;
	line* last;
	int n;
} list;

/* Creation list */
list* list_create(void);

/* Line insert in the list */
list* list_insert(list* lst, int pos);

/* Remove line in the list */
list* list_remove(list* lst, int pos);

/* Destroy list */
void list_destroy(list* lst);

/* Return the line that is searched in the list */
line* list_search(line* first, int pos);

/* Returns size of list */
int list_size(list* lst);


#endif /* _LISTA_H_ */
