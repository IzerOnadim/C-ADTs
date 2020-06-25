#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "arrayList.h"

#define EMPTY_BRACKETS_LENGTH (2)

static ArrayList_t *newArrayList(int size);
static bool doubleCapacityIfNeeded(ArrayList_t *list);
static void checkBounds(ArrayList_t *list, int index);
static void checkNullPointer(ArrayList_t *list);

ArrayList_t *createArrayList(void) {
  return newArrayList(0);
}

ArrayList_t *initArrayList(int *array, int size) {
  
  if (!array) return NULL;

  ArrayList_t *list = newArrayList(size);
  if (!list) return NULL;

  for (int i = 0; i < size; i++)
    if (!appendArrayList(list, array[i])) return NULL;

  return list;
}

void freeArrayList(ArrayList_t *list) {
  if (!list) return;
  free(list->array);
  list->array = NULL;
  free(list);
  list = NULL;
}

bool appendArrayList(ArrayList_t *list, int elem) {
  
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  
  //False from doubleCapacityIfNeeded means alloc failed.
  if (!doubleCapacityIfNeeded(list)) return false;

  (list->array)[list->length] = elem;
  list->length++;

  return true; 
}

int removeArrayList(ArrayList_t *list, int index) {
  
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  checkBounds(list, index); //May produce an error.

  int value = (list->array)[index];
  
  for (int i = index; i < list->length; i++)
    (list->array)[i] = (list->array)[i+1];

  list->length--;
  
  return value;  
}

bool isEmptyArrayList(ArrayList_t *list) {
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  return list->length == 0;
}

int lengthArrayList(ArrayList_t *list) {
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  return list->length;
}

bool containsArrayList(ArrayList_t *list, int elem) {
  
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  
  for (int i = 0; i < list->length; i++)
    if ((list->array)[i] == elem) return true;

  return false;
}

bool equalsArrayList(ArrayList_t *one, ArrayList_t *two) {
  
  checkNullPointer(one); checkNullPointer(two); 
  
  if (one->length != two->length) return false;

  for (int i = 0; i < one->length; i++)
    if ((one->array)[i] != (two->array)[i]) return false;

  return true;
}

int getArrayList(ArrayList_t *list, int index) {
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  checkBounds(list, index); // May throw error; 
  return (list->array)[index];
}

bool insertArrayList(ArrayList_t *list, int index, int elem) {
  
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  
  if (index > list->length) return false;

  if (index == list->length) return appendArrayList(list, elem); 
  
  if (!doubleCapacityIfNeeded(list)) return false;
  
  list->length++;
  for (int i = list->length; i > index; i--)
    (list->array)[i] = (list->array)[i-1]; 

  (list->array)[index] = elem; 

  return true;
}

void clearArrayList(ArrayList_t *list) {
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  list->length = 0;
}

int indexOfArrayList(ArrayList_t *list, int elem) {

  checkNullPointer(list); //Produces error if list is NULL pointer. 
  
  for (int i = 0; i < list->length; i++)
    if ((list->array)[i] == elem) return i;

  return -1;
}

bool appendAllArrayList(ArrayList_t *one, ArrayList_t *two) {
  checkNullPointer(one);
  checkNullPointer(two);

  for (int i = 0; i < two->length; i++)
    if (!appendArrayList(one, (two->array)[i])) return false;

  return true;
}

ArrayList_t *cloneArrayList(ArrayList_t *list) {
  
  checkNullPointer(list);
  
  int *arr = arrayListToArray(list);
  if (!arr) return NULL;
  ArrayList_t *clone = initArrayList(arr, list->length);
  free(arr);

  return clone;
}

ArrayList_t *subListArrayList(ArrayList_t *list, int start, int end) {
  if (end < start) return NULL;
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  checkBounds(list, start);
  checkBounds(list, end);

  ArrayList_t *subList = newArrayList(end - start); 
  if (!subList) return NULL; 

  for (int i = start; i < end; i++)
    if (!appendArrayList(subList, (list->array)[i])) return NULL;

  return subList;
}

int *arrayListToArray(ArrayList_t *list) {
  
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  
  int *arr = (int *) calloc(list->length, sizeof(int));
  if (!arr) return NULL;

  for (int i = 0; i < list->length; i++)
    arr[i] = (list->array)[i];

  return arr;
}

char *arrayListToString(ArrayList_t *list) {
  
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  
  int strLen = (list->length == 0) ? EMPTY_BRACKETS_LENGTH : list->length * 3;
  char *str = (char *) calloc(strLen, sizeof(char));
  if (!str) return NULL;

  strcat(str, "[");
  
  for (int i = 0; i < list->length; i++) {
    char num[3];
    sprintf(num, "%s%d%s", i == 0 ? "" : " ", (list->array)[i], 
        i < list->length - 1 ? "," : ""); 
    strcat(str, num);
  } 
  
  strcat(str, "]"); 

  return str;
}

bool ensureCapacityArrayList(ArrayList_t *list, int capacity) {
  checkNullPointer(list);

  if (list->size < capacity) {
    list->size = capacity;
    list->array = (int *) realloc(list->array, list->size * sizeof(int));
    if (!list->array) return false;  
  }
  
  return true;  
}

/*
 * Creates empty arrayList with given size.
 * Returns NULL if allocation fails.
 */
static ArrayList_t *newArrayList(int size) {

  ArrayList_t *list = (ArrayList_t *) malloc(sizeof(ArrayList_t));
  if (!list) return NULL;

  list->size = size + 1;
  list->length = 0;
  list->array = (int *) calloc(list->size, sizeof(int));
  if (!list->array) return NULL;
  
  return list;
}

/*
 * Causes error if an index is out of bounds.
 */
static void checkBounds(ArrayList_t *list, int index) {
  
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  
  if (index < 0 || index >= list->length) {
    fprintf(stderr, "Out of bounds array list access.");
    exit(EXIT_FAILURE);
  }
}

/*
 * double size of array if out of space. 
 */
static bool doubleCapacityIfNeeded(ArrayList_t *list) {
 
  checkNullPointer(list); //Produces error if list is NULL pointer. 
  
  if (list->length >= list->size) {
    list->size *= 2;
    list->array = (int *) realloc(list->array, list->size * sizeof(int));
    if (!list->array) return false;
  }
  return true;
}

/*
 * Gives error if pointer is NULL.
 */
static void checkNullPointer(ArrayList_t *list) {
  if (!list) {
    fprintf(stderr, "Null pointer given.");
    exit(EXIT_FAILURE);
  }
}
