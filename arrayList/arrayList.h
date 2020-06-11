#include <stdbool.h>

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct ArrayList {
  int size;
  int length;
  int *array;
} ArrayList_t;

/*
 * Creates an array list with dynamically allocated memory and 
 * returns a pointer to it. Returns NULL if allocation fails.
 */
ArrayList_t *createArrayList();

/*
 * Frees all memory allocated to given array list.
 */
void freeArrayList(ArrayList_t *list);

/*
 * Appends new element to the end of given array list.
 * Returns true if successful.
 */
bool appendArrayList(ArrayList_t *list, int elem);

/*
 * Removes an element from the a given location in the list 
 * and returns it. 
 */
int removeArrayList(ArrayList_t *list, int index);

/*
 * Returns true if there are no elements in the given list.
 */
bool isEmpty(ArrayList_t *list);

/*
 * Returns true if given list contains given element.
 */
bool containsArrayList(ArrayList_t *list, int elem);

#endif
