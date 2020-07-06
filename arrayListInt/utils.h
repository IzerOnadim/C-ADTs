#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

#define EMPTY_BRACKETS_LENGTH (2)
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/*
 * Struct to represent ArrayList abstract data type.
 */
typedef struct ArrayList {
  int size;
  int length;
  int *array;
} ArrayList_t;

/*
 * Creates empty arrayList with given size.
 * Returns NULL if allocation fails.
 */
ArrayList_t *newArrayList(int size);

/*
 * double size of array if out of space. 
 */
bool doubleCapacityIfNeeded(ArrayList_t *list);

/*
 * Produces Error, exits program.
 */
void outOfBoundsError();

/*
 * Causes error if an index is out of bounds.
 */
void checkBounds(ArrayList_t *list, int index);

/*
 * Causes error if index out of bounds but allows index == list->length
 */
void checkBoundOrEqual(ArrayList_t *list, int index);

/*
 * Gives error if pointer is NULL.
 */
void checkNullPointer(const ArrayList_t *list);

/*
 * Returns the number of digits in an integer.
 */
int numDigits(int value);

/*
 * Returns length of char array needed for string representation of ArrayList.
 */
int listStringLength(ArrayList_t *list);

/*
 * Produces Error, exits program.
 */
void checkEmptyQueue(ArrayList_t *list);

/*
 * Returns the smaller of two integers.
 */
int min(int one, int two);

#endif
