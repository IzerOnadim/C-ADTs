#include <stdio.h>
#include <stdlib.h>

#include "utils.h"

ArrayList_t *newArrayList(int size) {

  ArrayList_t *list = (ArrayList_t *) malloc(sizeof(ArrayList_t));
  if (!list) return NULL;

  list->size = size + 1;
  list->length = 0;
  list->array = (int *) calloc(list->size, sizeof(int));
  if (!list->array) return NULL;
  
  return list;
}

int min(int one, int two) {
  return one < two ? one : two; 
}

int numDigits(int value) {
  int count = 0;
  
  for (; value != 0; count++)
    value /= 10;
  
  return count;
}

int listStringLength(ArrayList_t *list) {
  int length = EMPTY_BRACKETS_LENGTH;

  for (int i = 0; i < list->length; i++)
    length += numDigits((list->array)[i]) + EMPTY_BRACKETS_LENGTH;

  return length - EMPTY_BRACKETS_LENGTH;
}

void checkBoundOrEqual(ArrayList_t *list, int index) {
  checkNullPointer(list); 
  if (index < 0 || index > list->length)
    outOfBoundsError();
}

void checkBounds(ArrayList_t *list, int index) {
  checkNullPointer(list); 
  if (index < 0 || index >= list->length)
    outOfBoundsError();
}

bool doubleCapacityIfNeeded(ArrayList_t *list) {
 
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  
  if (list->length >= list->size) {
    list->size *= 2;
    list->array = (int *) realloc(list->array, list->size * sizeof(int));
    if (!list->array) return false;
  }
  return true;
}

void checkNullPointer(const ArrayList_t *list) {
  if (!list) {
    fprintf(stderr, ANSI_COLOR_RED 
        "\nERROR: Null pointer given.\n\n" ANSI_COLOR_RESET);
    exit(EXIT_FAILURE);
  }
}

void checkEmptyQueue(ArrayList_t *list) {
  if (list->length == 0) {
    fprintf(stderr, ANSI_COLOR_RED 
        "\nERROR: Queue is empty\n\n" ANSI_COLOR_RESET);
    exit(EXIT_FAILURE);
  }
}  

void outOfBoundsError() {
  fprintf(stderr, ANSI_COLOR_RED 
      "\nERROR: Out of bounds ArrayList access.\n\n" ANSI_COLOR_RESET);
  exit(EXIT_FAILURE);
}
