#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "arrayList.h"

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
  
  //False from doubleCapacityIfNeeded means allocation failed.
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

bool setArrayList(ArrayList_t *list, int index, int value) {
  checkNullPointer(list);
  checkBoundOrEqual(list, index);

  if (list->length == index)
    return appendArrayList(list, value);
  
  (list->array)[index] = value;
  return true;
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

bool removeAll(ArrayList_t *one, ArrayList_t *two) {
  //should be updated to use a hash map when I create 
  //a hash map data type.
  checkNullPointer(one); checkNullPointer(two);
  bool found = false;

  for (int i = 0; i < one->length;) {
    if (containsArrayList(two, (one->array)[i])) {
      removeArrayList(one, i);
      found = true;
    } else { 
      i++;
    }
  }
  return found; 
}

bool removeElemArrayList(ArrayList_t *list, int elem) {
  checkNullPointer(list);
  
  for (int i = 0; i < list->length; i++) {
    if ((list->array)[i] == elem) {
      removeArrayList(list, i);
      return true; 
    }
  }
  return false;
}

bool removeAllElemArrayList(ArrayList_t *list, int elem) {
  checkNullPointer(list);
  bool found = false;
  
  for (int i = 0; i < list->length;) {
    if ((list->array)[i] == elem) {
      removeArrayList(list, i);
      found = true;
    } else {
      i++;
    } 
  }

  return found;
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
  checkBoundOrEqual(list, end);

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
  int lenStr = listStringLength(list);
  char *str = (char *) calloc(lenStr, sizeof(char));
  if (!str) return NULL;

  strcat(str, "[");
  
  for (int i = 0; i < list->length; i++) {
    char num[numDigits(list->array[i]) + 2];
    sprintf(num, "%s%d%s", i == 0 ? "" : " ", (list->array)[i], 
        i < list->length - 1 ? "," : ""); 
    strcat(str, num);
  } 
  
  strcat(str, "]"); 

  return str;
}

bool remDupArrayList(ArrayList_t *list) {
  //should be updated to use a hash map when I create 
  //a hash map data type.
  checkNullPointer(list);
  
  bool dup = false;
  ArrayList_t *seen = newArrayList(list->length);
  
  for (int i = 0; i < list->length;) {
    if (containsArrayList(seen, list->array[i])) {
      dup = true;
      removeArrayList(list, i);
    } else {
      appendArrayList(seen, list->array[i]);
      i++;
    }
  }

  freeArrayList(seen); 
  return dup;
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

/*-------------------------Queue functions-----------------------------*/

int dequeueArrayList(ArrayList_t *list) {
  checkNullPointer(list);
  checkEmptyQueue(list);
  return removeArrayList(list, 0);
}

int peekArrayList(ArrayList_t *list) {
  checkNullPointer(list);
  checkEmptyQueue(list);
  return getArrayList(list, 0);
}

bool enqueueArrayList(ArrayList_t *list, int elem) {
  return appendArrayList(list, elem);
}

/*--------------------------Set functions------------------------------*/

ArrayList_t *unionArrayList(const ArrayList_t *one, const ArrayList_t *two);
ArrayList_t *intersectArrayList(const ArrayList_t *one, const ArrayList_t *two);
ArrayList_t *diffArrayList(const ArrayList_t *one, const ArrayList_t *two);
bool disjointArrayList(const ArrayList_t *one, const ArrayList_t *two);

