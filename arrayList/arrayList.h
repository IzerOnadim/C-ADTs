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
ArrayList_t *arrayListCreate(void);

/*
 * Frees all memory allocated to given array list.
 */
void arrayListFree(ArrayList_t *list);

/*
 * Appends new element to the end of given array list.
 * Returns true if successful.
 */
bool arrayListAppend(ArrayList_t *list, int elem);

/*
 * Removes an element from the a given location in the list 
 * and returns it. 
 */
int arrayListRemove(ArrayList_t *list, int index);

/*
 * Returns true if there are no elements in the given list.
 */
bool arrayListIsEmpty(ArrayList_t *list);

/*
 * Returns the length of the array list;
 */
int arrayListLength(ArrayList_t *list);

/*
 * Returns true if given list contains given element.
 */
bool arrayListContains(ArrayList_t *list, int elem);

/*
 * Returns true if the two given arraylists are equal.
 */
bool arrayListEquals(ArrayList_t *one, ArrayList_t *two); 

/*
 * Returns element at given index, gives out of bounds error.
 */
int arrayListGet(ArrayList_t *list, int index); 

/*
 * Inserts element at given index in given list, 
 * returns false if realloc fails of element not inserted.
 */
bool arrayListInsert(ArrayList_t *list, int index, int elem); 

/*
 * Clears / empties array list, without changing capacity.
 */
void arrayListClear(ArrayList_t *list);

/*
 * Returns the index of the first occurence of an element,
 * Returns the -1 if no occurence of element.
 */
int arrayListIndexOf(ArrayList_t *list, int elem);

#endif
