#include <stdbool.h>

#ifndef UTILS_H
#define UTILS_H

#define EMPTY_BRACKETS_LENGTH (2)
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

typedef struct ArrayList {
  int size;
  int length;
  int *array;
} ArrayList_t;

ArrayList_t *newArrayList(int size);
bool doubleCapacityIfNeeded(ArrayList_t *list);
void outOfBoundsError();
void checkBounds(ArrayList_t *list, int index);
void checkBoundOrEqual(ArrayList_t *list, int index);
void checkNullPointer(const ArrayList_t *list);
int numDigits(int value);
int listStringLength(ArrayList_t *list);
void checkEmptyQueue(ArrayList_t *list);
int min(int one, int two);

#endif
