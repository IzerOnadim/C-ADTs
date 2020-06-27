#include "utils.h"

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

/*
 * Creates an array list with dynamically allocated memory and 
 * returns a pointer to it. Returns NULL if allocation fails.
 */
ArrayList_t *createArrayList(void);

/*
 * Creates and initialises ArrayList with a given array.
 * Returns NULL if allocation fails or if given pointer is NULL.
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
 * Removes an element from the given location in the list 
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
 * Returns true if the two given ArrayLists are equal.
 */
bool equalsArrayList(ArrayList_t *one, ArrayList_t *two); 

/*
 * Returns element at given index, gives out of bounds error.
 */
int getArrayList(ArrayList_t *list, int index); 

/*
 * Sets element at given index to given value. If index == length, 
 * appends value. If index > length, produces out of bounds error.
 * Returns false if and only if reallocation fails on append.
 */
bool setArrayList(ArrayList_t *list, int index, int value);

/*
 * Inserts element at given index in given list, 
 * returns false if reallocation fails of element not inserted.
 */
bool insertArrayList(ArrayList_t *list, int index, int elem); 

/*
 * Returns the index of the first occurrence of an element,
 * Returns the -1 if no occurrence of element.
 */
int indexOfArrayList(ArrayList_t *list, int elem);

/*
 * Appends all the elements of the second array list to the first one.
 * Returns true if successful.
 */
bool appendAllArrayList(ArrayList_t *one, ArrayList_t *two);

/*
 * Removes all occurrences of every element in ArrayList two, from
 * ArrayList one. Returns true if there was any thing to remove.
 */
bool removeAllArrayList(ArrayList_t *one, ArrayList_t *two);

/*
 * Removes the first occurrence of given elem from arrayList,
 * returns true if a matching elem was found.
 */
bool removeElemArrayList(ArrayList_t *list, int elem);

/*
 * Removes all occurrences of given element from given list.
 * Returns true if there was at least one element to remove.
 */
bool removeAllElemArrayList(ArrayList_t *list, int elem);

/*
 * Clears / empties array list, without changing capacity.
 */
void clearArrayList(ArrayList_t *list);

/*
 * Creates and returns a new, identical ArrayList to the one given.
 * Returns NULL if allocation fails.
 */
ArrayList_t *cloneArrayList(ArrayList_t *list);

/*
 * Creates and returns a new ArrayList that is a sub-list of the given one,
 * from index start (inclusive) to index end (exclusive). 
 * Produces error if either index is out of bounds.  
 */
ArrayList_t *subListArrayList(ArrayList_t *list, int start, int end);

/*
 * Returns array version of given arrayList. Array is dynamically 
 * allocated and must be freed. Returns  null pointer if allocation fails.
 * Array size will be the same as the length of the arrayList.
 */
int *arrayListToArray(ArrayList_t *list);

/*
 * Returns string representing ArrayList in form [0, 1, 2, 3].
 * String is dynamically allocated and must be freed. 
 * Null returned if allocation fails or if list pointer is NULL.
 */
char *arrayListToString(ArrayList_t *list);

/*
 * Removes all duplicated elements from arrayList. Keeps first occurrence 
 * of element. Returns true if and only if there were any duplicates.
 */
bool remDupArrayList(ArrayList_t *list);

/*
 * Makes sure that the ArrayList given has the given capacity.
 * Resizes ArrayList if needed. Returns false if reallocation fails on resize;
 */
bool ensureCapacityArrayList(ArrayList_t *list, int capacity);

/*-------------------------Queue functions-----------------------------*/

/*
 * Allows ArrayList to be treated as a queue; removes and returns the first 
 * element in the queue.Produces error if queue is empty, so should always be 
 * used in if statement checking for this case.
 */
int dequeueArrayList(ArrayList_t *list);

/*
 * Allows ArrayList to be treated as a queue; returns first element in the queue
 * without removing - error if queue is empty.
 */
int peekArrayList(ArrayList_t *list);

/*
 * Allows ArrayList to be treated as a queue; Adds new element to the end of
 * queue - returns false if reallocation fails.
 */
bool enqueueArrayList(ArrayList_t *list, int elem);

/*--------------------------Set functions------------------------------*/

/*
 * Returns a new ArrayList that is the union of the two given ArrayLists,
 * but contains no duplicates - i.e. is a set.
 */
//TODO: implement this.
ArrayList_t *unionArrayList(const ArrayList_t *one, const ArrayList_t *two);

/*
 * Returns a new ArrayList that is the intersection of the two given ArrayLists,
 * but contains no duplicates - i.e. is a set.
 */
//TODO: implement this.
ArrayList_t *intersectArrayList(const ArrayList_t *one, const ArrayList_t *two);

/*
 * Returns a new ArrayList that is the set difference of ArrayList one and 
 * ArrayList two (one - two or one\two). Contains no duplicates.
 */
//TODO: implement this.
ArrayList_t *diffArrayList(const ArrayList_t *one, const ArrayList_t *two);

/*
 * Returns true if and only if the two given ArrayList are disjoint,
 * i.e. they do not contain any of the same elements.
 */
//TODO: implement this.
bool disjointArrayList(const ArrayList_t *one, const ArrayList_t *two);

#endif
