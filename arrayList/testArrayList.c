#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "utils.h"
#include "arrayList.h"

#define MAX_LINE_LENGTH (50)
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define testTrue(a) testTrueLine(a, __LINE__)
#define testEquals(a, b) testEqualsLine(a, b,__LINE__)
#define TESTS_PASSED (NUM_TESTS - TESTS_FAILED)

int NUM_TESTS = 0;
int TESTS_FAILED = 0;

bool testTrueLine(bool condition, int line) {
  NUM_TESTS++;
  char fail[MAX_LINE_LENGTH];
  sprintf(fail, ANSI_COLOR_RED "FAIL - line: %d in %s" ANSI_COLOR_RESET, 
      line, __FILE__);
  if (!condition) TESTS_FAILED++;
  printf("Test %3d: %s\n", NUM_TESTS, condition ?  
      ANSI_COLOR_GREEN "PASS"  ANSI_COLOR_RESET : fail);
 return condition; 
}

bool testEqualsLine(int one, int two, int line) {
 return testTrueLine(one == two, line); 
}

void testToString(ArrayList_t *list, char *expected) {
  char *actual = arrayListToString(list);
  if (!testTrue(!strcmp(actual, expected))) {
    printf("Expected: %s\n", expected);
    printf("Actual:   %s\n", actual); 
  }
  free(actual);
}

bool equalArrays(int *one, int *two, int size) {
  for (int i = 0; i < size; i++)
    if (one[i] != two[i]) return false;

  return true;
}

void printArray(int *arr, int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    printf("%s%d%s", i == 0 ? "" : " ", arr[i], i < size - 1 ? "," : "");
  }
  printf("]\n");
}

void removeAllElemTests(void) {
  int arr[] = {2, 3, 4, 2, 2, 56, 78, 34, 443, 123, 2, 2, 7, 45, 2, 5, 3, 2};
  
  ArrayList_t *list = initArrayList(arr, 18);
  testTrue(removeAllElemArrayList(list, 2));
  testTrue(!containsArrayList(list, 2));
  
  char *str = arrayListToString(list);
  testToString(list, "[3, 4, 56, 78, 34, 443, 123, 7, 45, 5, 3]");
  testTrue(!removeAllElemArrayList(list, 2));
  
  int len = lengthArrayList(list);
  testTrue(removeAllElemArrayList(list, 56));
  testEquals(lengthArrayList(list), len - 1);

  freeArrayList(list);
  free(str);
} 

int main(void) {

  ArrayList_t *list = createArrayList();
  
  printf("\n-----------------LIST FUNCTION TESTS------------------\n");
  printf("\n---------appendArrayList tests------------------------\n\n");
  appendArrayList(list, 0);
  appendArrayList(list, 1);
  appendArrayList(list, 2);
  appendArrayList(list, 3);
  testTrue(containsArrayList(list, 3));
  testTrue(containsArrayList(list, 2));
  testTrue(containsArrayList(list, 0));
  testTrue(containsArrayList(list, 1));

  printf("\n---------removeArrayList & containsArrayList tests----\n\n");
  removeArrayList(list, 0);
  testTrue(!containsArrayList(list, 0));
  removeArrayList(list, 0);
  testTrue(!containsArrayList(list, 1));
  removeArrayList(list, 0);
  testTrue(!containsArrayList(list, 2));
  removeArrayList(list, 0);
  testTrue(!containsArrayList(list, 3));
  appendArrayList(list, 0);
  appendArrayList(list, 0);
  removeArrayList(list, 1);
  testTrue(containsArrayList(list, 0));
  removeArrayList(list, 0);
  testTrue(!containsArrayList(list, 0));
  
  printf("\n---------isEmptyArrayList tests----------------------\n\n");
  appendArrayList(list, 13);
  testTrue(!isEmptyArrayList(list));
  removeArrayList(list, 0);
  testTrue(isEmptyArrayList(list));
  
  printf("\n---------lengthArrayList tests------------------------\n\n");
  appendArrayList(list, 13);
  testEquals(lengthArrayList(list), 1);
  appendArrayList(list, 0);
  testEquals(lengthArrayList(list), 2);
  appendArrayList(list, 2753);
  testEquals(lengthArrayList(list), 3);
  appendArrayList(list, 123456);
  testEquals(lengthArrayList(list), 4);
  removeArrayList(list, 3);
  testEquals(lengthArrayList(list), 3);
  removeArrayList(list, 2);
  testEquals(lengthArrayList(list), 2);
  removeArrayList(list, 1);
  testEquals(lengthArrayList(list), 1);
  removeArrayList(list, 0);
  testEquals(lengthArrayList(list), 0);
  
  printf("\n---------equalsArrayList tests------------------------\n\n");
  ArrayList_t *other = createArrayList();
  testTrue(equalsArrayList(list, other));
  appendArrayList(other, 1); 
  testTrue(!equalsArrayList(list, other));
  appendArrayList(other, 2); 
  appendArrayList(list, 1); 
  appendArrayList(list, 2); 
  testTrue(equalsArrayList(list, other));
  appendArrayList(list, 2); 
  testTrue(!equalsArrayList(list, other));
  appendArrayList(other, 2); 
  testTrue(equalsArrayList(list, other));
  removeArrayList(list, 2);
  testTrue(!equalsArrayList(list, other));
  removeArrayList(other, 1);
  testTrue(equalsArrayList(list, other));
  removeArrayList(other, 0);
  removeArrayList(other, 0);
  removeArrayList(list, 0);
  removeArrayList(list, 0);
  testTrue(equalsArrayList(list, other));
  
  printf("\n---------getArrayList tests--------------------------\n\n");
  appendArrayList(list, 13);
  testEquals(getArrayList(list, 0), 13);
  testEquals(getArrayList(list, 0), 13);
  appendArrayList(list, 246772);
  appendArrayList(list, -5463);
  appendArrayList(list, 0x500);
  appendArrayList(list, -0x500);
  testEquals(getArrayList(list, 1), 246772);
  testEquals(getArrayList(list, 2), -5463);
  testEquals(getArrayList(list, 3), 0x500);
  testEquals(getArrayList(list, 4), -0x500);

  printf("\n---------clearArrayList tests------------------------\n\n");
  testTrue(!isEmptyArrayList(list));
  clearArrayList(list);
  testTrue(isEmptyArrayList(list));
  testTrue(!containsArrayList(list, 13));
  testTrue(!containsArrayList(list, 246772));

  printf("\n---------insertArrayList tests-----------------------\n\n");
  appendArrayList(list, 0);  
  appendArrayList(list, 4);  
  insertArrayList(list, 1, 2);
  testTrue(containsArrayList(list, 2));
  testEquals(getArrayList(list, 1), 2);
  testToString(list, "[0, 2, 4]");
  testEquals(removeArrayList(list, 0), 0);
  testEquals(removeArrayList(list, 0), 2);
  testEquals(removeArrayList(list, 0), 4);
  testTrue(isEmptyArrayList(list));
  insertArrayList(list, 0, 3);
  testTrue(containsArrayList(list, 3));
  testEquals(removeArrayList(list, 0), 3);

  printf("\n---------indexOfArrayList tests----------------------\n\n");
  appendArrayList(list, 0);
  appendArrayList(list, 1);
  appendArrayList(list, 2);
  testEquals(indexOfArrayList(list, 0), 0); 
  testEquals(indexOfArrayList(list, 1), 1); 
  testEquals(indexOfArrayList(list, 2), 2); 
  testEquals(indexOfArrayList(list, 9), -1); 
  testEquals(indexOfArrayList(list, 8), -1); 
  clearArrayList(list); 
  testEquals(indexOfArrayList(list, 0), -1);

  printf("\n---------initArrayList tests-------------------------\n\n");
  int arr[] = {1, 2, 3, 4, 5};
  ArrayList_t *another = initArrayList(arr, 5);
  testTrue(containsArrayList(another, 1));
  testTrue(containsArrayList(another, 2));
  testTrue(containsArrayList(another, 3));
  testTrue(containsArrayList(another, 4));
  testTrue(containsArrayList(another, 5));
  testTrue(!containsArrayList(another, 0));
  testTrue(!containsArrayList(another, 6));
  testTrue(!containsArrayList(another, 8));

  printf("\n---------arrayListToArray tests----------------------\n\n");
  int *newArr = arrayListToArray(another);
  testTrue(equalArrays(arr, newArr, another->length));
  int arr1[1];
  int *arr2 = arrayListToArray(list);
  testTrue(equalArrays(arr1, arr2, list->length));

  printf("\n---------arrayListToString tests---------------------\n\n");
  testToString(another, "[1, 2, 3, 4, 5]");
  appendArrayList(another, 6);
  testToString(another, "[1, 2, 3, 4, 5, 6]");
  insertArrayList(another, 0, 0);
  testToString(another, "[0, 1, 2, 3, 4, 5, 6]");
  clearArrayList(another);
  testToString(another, "[]");

  printf("\n---------cloneArrayList tests------------------------\n\n");
  ArrayList_t *clonedList = cloneArrayList(list);
  testTrue(clonedList != list); 
  testTrue(equalsArrayList(list, clonedList));
  appendArrayList(list, 1); 
  appendArrayList(list, 2); 
  appendArrayList(list, 3); 
  appendArrayList(list, 4); 
  ArrayList_t *clonedList1 = cloneArrayList(list);
  testTrue(clonedList1 != list); 
  testTrue(equalsArrayList(list, clonedList1));
  testTrue(containsArrayList(clonedList1, 1));
  testTrue(containsArrayList(clonedList1, 2));
  testTrue(containsArrayList(clonedList1, 3));
  testTrue(containsArrayList(clonedList1, 4));
  testTrue(!containsArrayList(clonedList1, 0));
  testTrue(!containsArrayList(clonedList1, 5));
  testEquals(lengthArrayList(clonedList1), 4);
  testToString(clonedList1, "[1, 2, 3, 4]");

  printf("\n---------subListArrayList tests----------------------\n\n");
  ArrayList_t *subList = subListArrayList(list, 1, 3); 
  testEquals(lengthArrayList(subList), 2);
  testTrue(containsArrayList(subList, 2));
  testTrue(containsArrayList(subList, 3));
  testTrue(!containsArrayList(subList, 1));
  testTrue(!containsArrayList(subList, 4));
  testToString(subList, "[2, 3]");

  printf("\n---------appendAllArrayList tests--------------------\n\n");
  appendAllArrayList(other, subList);
  testTrue(!isEmptyArrayList(other));
  testTrue(containsArrayList(other, 2));
  testTrue(containsArrayList(other, 3));
  testTrue(!containsArrayList(other, 1));
  testToString(other, "[2, 3]");

  printf("\n---------ensureCapacityArrayList tests---------------\n\n");
  testTrue(ensureCapacityArrayList(other, 5));
  testEquals(other->size, 5);
  testTrue(ensureCapacityArrayList(list, 12));
  testEquals(list->size, 12);

  printf("\n---------setArrayList tests--------------------------\n\n");
  testTrue(setArrayList(list, 2, 10));
  testEquals(getArrayList(list, 2), 10); 
  testToString(list, "[1, 2, 10, 4]");
  testTrue(setArrayList(list, 4, 2020));
  testEquals(getArrayList(list, 4), 2020); 
  testToString(list, "[1, 2, 10, 4, 2020]");

  printf("\n---------remDupArrayList tests-----------------------\n\n");
  int dupArr[] = {1, 2, 2, 3, 4, 1, 15, 24, 24, 1, 3, 4};
  ArrayList_t *dupList = initArrayList(dupArr, 12);
  testTrue(remDupArrayList(dupList));
  testToString(dupList, "[1, 2, 3, 4, 15, 24]");
  testTrue(!remDupArrayList(dupList));
  clearArrayList(dupList);
  testTrue(!remDupArrayList(dupList));
  appendArrayList(dupList, 21234);
  appendArrayList(dupList, 21234);
  testEquals(lengthArrayList(dupList), 2);
  testTrue(remDupArrayList(dupList));
  testEquals(lengthArrayList(dupList), 1);
  testToString(dupList, "[21234]");

  printf("\n---------removeAllElemArrayList tests----------------\n\n");
  removeAllElemTests();
  
  printf("\n----------------QUEUE FUNCTION TESTS-----------------\n");

  printf("\n---------dequeueArrayList tests----------------------\n\n");
  testEquals(dequeueArrayList(dupList), 21234);
  testTrue(isEmptyArrayList(dupList)); 
  testToString(dupList, "[]");
  int origLen = lengthArrayList(list);
  testEquals(dequeueArrayList(list), 1); 
  testToString(list, "[2, 10, 4, 2020]");
  testEquals(lengthArrayList(list), origLen - 1);

  printf("\n---------peekArrayList tests-------------------------\n\n");
  origLen = lengthArrayList(list);
  testEquals(peekArrayList(list), 2); 
  testEquals(peekArrayList(list), 2); 
  testEquals(lengthArrayList(list), origLen);
  testToString(list, "[2, 10, 4, 2020]");

  printf("\n---------enqueueArrayList tests----------------------\n\n");
  enqueueArrayList(list, 2021);
  testEquals(lengthArrayList(list), origLen + 1);
  testEquals(getArrayList(list, origLen), 2021); 
  testToString(list, "[2, 10, 4, 2020, 2021]");
  testTrue(enqueueArrayList(dupList, 15));
  testEquals(lengthArrayList(dupList), 1);
  testToString(dupList, "[15]"); 

  printf("\n-----------------------SUMMARY-----------------------\n");
  int n = numDigits(NUM_TESTS);
  char tests[MAX_LINE_LENGTH];
  char passed[MAX_LINE_LENGTH];
  char failed[MAX_LINE_LENGTH];
  sprintf(tests, "\nNo. Tests: %*d\n", n, NUM_TESTS);
  sprintf(passed, TESTS_PASSED <= 0 ? "Passed:    %*d\n" :
    ANSI_COLOR_GREEN "Passed:    %*d\n" ANSI_COLOR_RESET, n, TESTS_PASSED);
  sprintf(failed, TESTS_FAILED <= 0 ? "Failed:    %*d\n" :
    ANSI_COLOR_RED "Failed:    %*d\n" ANSI_COLOR_RESET, n, TESTS_FAILED);
  printf("%s%s%s", tests, passed, failed);
  printf("\nFreeing memory now... Run valgrind to check for leaks.\n");
  freeArrayList(list);
  freeArrayList(other);
  freeArrayList(another);
  freeArrayList(clonedList);
  freeArrayList(clonedList1);
  freeArrayList(subList);
  freeArrayList(dupList);
  free(newArr);
  free(arr2); 
  printf("\n------------------------------------------------------\n\n");

  return EXIT_SUCCESS;
}
