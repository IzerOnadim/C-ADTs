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
ArrayList_t *createArrayList(void);

/*
 * Creats and initialises arrayList with a given array.
 * Returns NULL if allocation fails.
 */
ArrayList_t *initArrayList(int *array, int size);

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
bool isEmptyArrayList(ArrayList_t *list);

/*
 * Returns the length of the array list;
 */
int lengthArrayList(ArrayList_t *list);

/*
 * Returns true if given list contains given element.
 */
bool containsArrayList(ArrayList_t *list, int elem);

/*
 * Returns true if the two given arraylists are equal.
 */
bool equalsArrayList(ArrayList_t *one, ArrayList_t *two); 

/*
 * Returns element at given index, gives out of bounds error.
 */
int getArrayList(ArrayList_t *list, int index); 

/*
 * Inserts element at given index in given list, 
 * returns false if realloc fails of element not inserted.
 */
bool insertArrayList(ArrayList_t *list, int index, int elem); 

/*
 * Clears / empties array list, without changing capacity.
 */
void clearArrayList(ArrayList_t *list);

/*
 * Returns the index of the first occurence of an element,
 * Returns the -1 if no occurence of element.
 */
int indexOfArrayList(ArrayList_t *list, int elem);

/*
 * Appends all the elements of the second array list to the first one.
 * Rerturns true if successful.
 */
bool appendAllArrayList(ArrayList_t *one, ArrayList_t *two);

/*
 * Creates and returns a new, identical arrayList to the one given.
 * Returns NULL if alloc fails.
 */
ArrayList_t *cloneArrayList(ArrayList_t *list);

/*
 * Creates and returns a new arrayList that is a sublist of the given one,
 * from index start (inclusive) to index end (exclusive). 
 * Produces error if either index is out of bounds.  
 */
ArrayList_t *subListArrayList(ArrayList_t *list, int start, int end);

/*
 * Returns array version of given ArrayList. Array is dynamically 
 * allocated and must be freed. Returns  null pointer if alloc fails.
 * Array size will be the same as the length of the ArrayList.
 */
int *arrayListToArray(ArrayList_t *list);

/*
 * Returns string representing ArrayList in form [0, 1, 2, 3].
 * String is dynamically allocated and must be free. 
 * Null returned if alloc fails.
 * Size of string will be 3 * length of ArrayList due to [ ,] chars.
 */
char *arrayListToString(ArrayList_t *list);

#endif
