/*
 * lista.h
 * Funções de TAD lista duplamente encadeada.
 *
 */
#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "memo.h"

/* List creation */
list* list_create(void){
	
	line* ln = (line*) memo_aloca(sizeof(line));
	ln->text = (char*) memo_aloca(sizeof(char));
	ln->text[0] = '\0';
	ln->next = NULL;
	ln->prev = NULL;

	list* lst = (list*) memo_aloca(sizeof(list));
	lst->first = ln;
	lst->last = ln;
	lst->n = 0;

	return lst;
}

/* Line insert in the list */
list* list_insert(list* lst, int pos){

	if(pos<0) pos*=-1;

	int size = list_size(lst);
	if(size+1 < pos || pos == 0){
		printf("Não é possível inserir linha nessa posição!\n");
		return lst;
	}

	line* ln = (line*) memo_aloca(sizeof(line));
	ln->text = (char*) memo_aloca(sizeof(char));
	ln->text[0] = '\0';

	if(pos > 1){
		line* aux = list_search(lst->first, pos-1); 
		ln->prev = aux;
		ln->next = aux->next;
		if(aux->next == NULL)
			lst->last = ln;
		else
			aux->next->prev = ln;
		aux->next = ln;
	}else{
		ln->prev = NULL;
		ln->next = lst->first;
		lst->first->prev = ln;
		lst->first = ln;
	}
	
	lst->n++;

	return lst;
}

/* Remove line in the list */
list* list_remove(list* lst, int pos){

	if(pos<0) pos*=-1;

	int size = list_size(lst);
	if(size+1 < pos || pos == 0){
		printf("Não é possível remover a linha nessa posição!\n");
		return lst;
	}

	line* ln = list_search(lst->first, pos);

	if(ln->next == NULL){
		ln->prev->next = NULL;
		lst->last = ln->prev;
	}else if(ln->prev == NULL){
		ln->next->prev = NULL;
		lst->first = ln->next;
	}else{
		ln->prev->next = ln->next;
		ln->next->prev = ln->prev;
	}
	memo_libera(ln->text);
	memo_libera(ln);

	return lst;
}

/* Destroy list */
void list_destroy(list* lst){

	memo_libera(lst->first->text);
	memo_libera(lst->first);
	memo_libera(lst);
}

/* Line return that is search in the list */
line* list_search(line* first, int pos){

	line* ln = first;
	if(ln == NULL)
		return 0;
	else if(pos == 0)
		return ln;
	else
		return list_search(ln->next, pos-1);
}

/* Returns size of list */
int list_size(list* lst) {

	return lst->n;
}

