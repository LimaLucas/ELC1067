/*
 * lista.h
 * Funções de TAD lista duplamente encadeada.
 *
 */

#include "lista.h"
#include "memo.h"

/* List creation */
list* list_create(void)
{
	line* ln = (line*) memo_aloca(sizeof(line));
	ln->text = (char*) memo_aloca(sizeof(char));
	ln->text[0] = '\0';
	ln->next = NULL;
	ln->prev = NULL;

	list lst* = (list*) memo_aloca(sizeof(list));
	lst->first = ln;
	lst->last = ln;

	return list;
}

/* Line insert in the list */
list* list_insert(list* lst, int pos)
{

}

/* Remove line in the list */
list* list_remove(list* lst, int pos)
{

}

/* Destroy list */
void list_destroy(list* lst)
{
	memo_libera(lst->first->text);
	memo_libera(lst->first);
	memo_libera(lst);
}

/* Line return that is search in the list */
line* list_search(line* first, int pos)
{
	line* ln = first;
	if(ln == NULL)
		return 0;
	else if(pos == 0)
		return ln;
	else
		return list_search(ln->next, pos-1);
}

/* Returns size of list */
int list_size(list* lst)
{
	return lst->n;
}

