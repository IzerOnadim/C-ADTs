#include "arrayList.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static ArrayList_t *newArrayList(int size);
static bool doubleCapacityIfNeeded(ArrayList_t *list);
static void checkBounds(ArrayList_t *list, int index);

ArrayList_t *createArrayList(void) {
  return newArrayList(0);
}

ArrayList_t *initArrayList(int *array, int size) {
  
  ArrayList_t *list = newArrayList(size);
  if (!list) return NULL;

  for (int i = 0; i < size; i++)
    if (!appendArrayList(list, array[size])) return NULL;

  return list;
}

void freeArrayList(ArrayList_t *list) {
  free(list->array);
  list->array = NULL;
  free(list);
  list = NULL;
}

bool appendArrayList(ArrayList_t *list, int elem) {
  
  //False from doubleCapacityIfNeeded means alloc failed.
  if (!doubleCapacityIfNeeded(list)) return false;

  (list->array)[list->length] = elem;
  list->length++;

  return true; 
}

int removeArrayList(ArrayList_t *list, int index) {
  
  checkBounds(list, index); //May produce an error.

  int value = (list->array)[index];
  
  for (int i = index; i < list->length; i++)
    (list->array)[i] = (list->array)[i+1];

  list->length--;
  
  return value;  
}

bool isEmptyArrayList(ArrayList_t *list) {
  return list->length == 0;
}

int lengthArrayList(ArrayList_t *list) {
  return list->length;
}

bool containsArrayList(ArrayList_t *list, int elem) {
  
  for (int i = 0; i < list->length; i++)
    if ((list->array)[i] == elem) return true;

  return false;
}

bool equalsArrayList(ArrayList_t *one, ArrayList_t *two) {
  
  if (one->length != two->length) return false;

  for (int i = 0; i < one->length; i++)
    if ((one->array)[i] != (two->array)[i]) return false;
  
  return true;
}

int getArrayList(ArrayList_t *list, int index) {
  checkBounds(list, index); // May throw error; 
  return (list->array)[index];
}

bool insertArrayList(ArrayList_t *list, int index, int elem) {
  
  if (index > list->length) return false;

  if (index == list->length) return appendArrayList(list, elem); 
  
  if (!doubleCapacityIfNeeded(list)) return false;
  
  list->length++;
  for (int i = index; i < list->length; i++)
    (list->array)[i+1] = (list->array)[i]; 

  (list->array)[index] = elem; 

  return true;
}

void clearArrayList(ArrayList_t *list) {
  list->length = 0;
}

int indexOfArrayList(ArrayList_t *list, int elem) {

  for (int i = 0; i < list->length; i++) 
    if ((list->array)[i] == elem) return i;
  
  return -1;
}

bool appendAllArrayList(ArrayList_t *one, ArrayList_t *two);

ArrayList_t *cloneArrayList(ArrayList_t *list);

ArrayList_t *subListArrayList(ArrayList_t *list, int start, int end);

int *arrayListToArray(ArrayList_t *list);

char *arrayListToString(ArrayList_t *list);

/*
 * Creates empty arrayList with given size.
 * Returns NULL if allocation fails.
 */
static ArrayList_t *newArrayList(int size) {

  ArrayList_t *list = (ArrayList_t *) malloc(sizeof(ArrayList_t));
  if (!list) return NULL;

  list->size = size + 1;
  list->length = size;
  list->array = (int *) calloc(list->size, sizeof(int));
  if (!list->array) return NULL;
  
  return list;
}

/*
 * Causes error if an index is out of bounds.
 */
static void checkBounds(ArrayList_t *list, int index) {
  if (index < 0 || index >= list->length) {
    fprintf(stderr, "Out of bounds array list access.");
    exit(EXIT_FAILURE);
  }
}

/*
 * double size of array if out of space. 
 */
static bool doubleCapacityIfNeeded(ArrayList_t *list) {
  if (list->length >= list->size) {
    list->size *= 2;
    list->array = (int *) realloc(list->array, list->size * sizeof(int));
    if (!list->array) return false;
  }
  return true;
}

