#include "arrayList.h"

#include <stdbool.h>

ArrayList_t *createArrayList() {
  
  ArrayList_t list = (ArrayList_t *) malloc(sizeof(ArrayList_t));
  if (!list) return NULL;

  list->size = 1;
  list->length = 0;
  list->array = (int *) calloc(1, sizeof(int));
  if (!list->array) return NULL;

  return list;
}

void freeArrayList(ArrayList_t *list) {
  
  free(list->array);
  list->array = NULL;
  free(list);
  list = NULL;
}

bool appendArrayList(ArrayList_t *list, int elem);

int removeArrayList(ArrayList_t *list, int index);

bool isEmpty(ArrayList_t *list);

bool containsArrayList(ArrayList_t *list, int elem);
