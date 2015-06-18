#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vertice.h"

typedef struct lista {
	vertice_t* elem;
	lista_t* next;
} lista_t;

