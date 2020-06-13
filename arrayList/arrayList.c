#include "arrayList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

ArrayList_t *arrayListCreate(void) {
  
  ArrayList_t *list = (ArrayList_t *) malloc(sizeof(ArrayList_t));
  if (!list) return NULL;

  list->size = 1;
  list->length = 0;
  list->array = (int *) calloc(list->size, sizeof(int));
  if (!list->array) return NULL;

  return list;
}

void arrayListFree(ArrayList_t *list) {
  
  free(list->array);
  list->array = NULL;
  free(list);
  list = NULL;
}

bool arrayListAppend(ArrayList_t *list, int elem) {
  
  if (list->length >= list->size) {
    list->size *= 2;
    list->array = (int *) realloc(list->array, list->size * sizeof(int));
    if (!list->array) return false;
  }

  (list->array)[list->length] = elem;
  list->length++;

  return true; 
}

int arrayListRemove(ArrayList_t *list, int index) {
  
  if (index < 0 || index >= list->length) {
    fprintf(stderr, "Out of bounds array list access.");
    exit(EXIT_FAILURE);
  }
  
  int value = (list->array)[index];
  
  for (int i = index; i < list->length; i++) {
    (list->array)[i] = (list->array)[i+1];
  }

  list->length--;
  
  return value;  
}

bool arrayListIsEmpty(ArrayList_t *list) {
  return list->length == 0;
}

int arrayListLength(ArrayList_t *list) {
  return list->length;
}

bool arrayListContains(ArrayList_t *list, int elem) {
  
  for (int i = 0; i < list->length; i++)
    if ((list->array)[i] == elem) return true;

  return false;
}

bool arrayListEquals(ArrayList_t *one, ArrayList_t *two) {
  
  if (one->length != two->length) return false;

  for (int i = 0; i < one->length; i++)
    if ((one->array)[i] != (two->array)[i]) return false;
  
  return true;
}

int arrayListGet(ArrayList_t *list, int index) {
  
  if (index < 0 || index >= list->length) {
    fprintf(stderr, "Out of bounds array list access.");
    exit(EXIT_FAILURE);
  }
  
  return (list->array)[index];
}

bool arrayListInsert(ArrayList_t *list, int index, int elem);  

