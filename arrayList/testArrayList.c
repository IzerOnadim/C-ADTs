#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "arrayList.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

bool testTrue(bool condition, char *testname) {
  printf("%s: %s\n", testname, condition ?  
      ANSI_COLOR_GREEN "OK"  ANSI_COLOR_RESET :
      ANSI_COLOR_RED  "FAIL" ANSI_COLOR_RESET);
 return condition; 
}

bool testEquals(int one, int two, char *testname) {
 return testTrue(one == two, testname); 
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

int main(void) {
  ArrayList_t *list = createArrayList();
  
  printf("\n---------appendArrayList tests------------------------\n\n");
  appendArrayList(list, 0);
  appendArrayList(list, 1);
  appendArrayList(list, 2);
  appendArrayList(list, 3);
  testTrue(containsArrayList(list, 3), "Test 01");
  testTrue(containsArrayList(list, 2), "Test 02");
  testTrue(containsArrayList(list, 0), "Test 03");
  testTrue(containsArrayList(list, 1), "Test 04");

  printf("\n---------removeArrayList & containsArrayList tests----\n\n");
  removeArrayList(list, 0);
  testTrue(!containsArrayList(list, 0), "Test 05");
  removeArrayList(list, 0);
  testTrue(!containsArrayList(list, 1), "Test 06");
  removeArrayList(list, 0);
  testTrue(!containsArrayList(list, 2), "Test 07");
  removeArrayList(list, 0);
  testTrue(!containsArrayList(list, 3), "Test 08");
  appendArrayList(list, 0);
  appendArrayList(list, 0);
  removeArrayList(list, 1);
  testTrue(containsArrayList(list, 0), "Test 09");
  removeArrayList(list, 0);
  testTrue(!containsArrayList(list, 0), "Test 10");
  
  printf("\n---------isEmptyArrayList tests----------------------\n\n");
  appendArrayList(list, 13);
  testTrue(!isEmptyArrayList(list), "Test 11");
  removeArrayList(list, 0);
  testTrue(isEmptyArrayList(list), "Test 12");
  
  printf("\n---------lengthArrayList tests------------------------\n\n");
  appendArrayList(list, 13);
  testEquals(lengthArrayList(list), 1, "Test 13");
  appendArrayList(list, 0);
  testEquals(lengthArrayList(list), 2, "Test 14");
  appendArrayList(list, 2753);
  testEquals(lengthArrayList(list), 3, "Test 15");
  appendArrayList(list, 123456);
  testEquals(lengthArrayList(list), 4, "Test 16");
  removeArrayList(list, 3);
  testEquals(lengthArrayList(list), 3, "Test 17");
  removeArrayList(list, 2);
  testEquals(lengthArrayList(list), 2, "Test 18");
  removeArrayList(list, 1);
  testEquals(lengthArrayList(list), 1, "Test 19");
  removeArrayList(list, 0);
  testEquals(lengthArrayList(list), 0, "Test 20");
  
  printf("\n---------equalsArrayList tests------------------------\n\n");
  ArrayList_t *other = createArrayList();
  testTrue(equalsArrayList(list, other), "Test 21");
  appendArrayList(other, 1); 
  testTrue(!equalsArrayList(list, other), "Test 22");
  appendArrayList(other, 2); 
  appendArrayList(list, 1); 
  appendArrayList(list, 2); 
  testTrue(equalsArrayList(list, other), "Test 23");
  appendArrayList(list, 2); 
  testTrue(!equalsArrayList(list, other), "Test 24");
  appendArrayList(other, 2); 
  testTrue(equalsArrayList(list, other), "Test 25");
  removeArrayList(list, 2);
  testTrue(!equalsArrayList(list, other), "Test 26");
  removeArrayList(other, 1);
  testTrue(equalsArrayList(list, other), "Test 27");
  removeArrayList(other, 0);
  removeArrayList(other, 0);
  removeArrayList(list, 0);
  removeArrayList(list, 0);
  testTrue(equalsArrayList(list, other), "Test 28");
  
  printf("\n---------getArrayList tests--------------------------\n\n");
  appendArrayList(list, 13);
  testEquals(getArrayList(list, 0), 13, "Test 29");
  testEquals(getArrayList(list, 0), 13, "Test 30");
  appendArrayList(list, 246772);
  appendArrayList(list, -5463);
  appendArrayList(list, 0x500);
  appendArrayList(list, -0x500);
  testEquals(getArrayList(list, 1), 246772, "Test 31");
  testEquals(getArrayList(list, 2), -5463, "Test 32");
  testEquals(getArrayList(list, 3), 0x500, "Test 33");
  testEquals(getArrayList(list, 4), -0x500, "Test 34");

  printf("\n---------clearArrayList tests------------------------\n\n");
  testTrue(!isEmptyArrayList(list), "Test 35");
  clearArrayList(list);
  testTrue(isEmptyArrayList(list), "Test 36");
  testTrue(!containsArrayList(list, 13), "Test 37");
  testTrue(!containsArrayList(list, 246772), "Test 38");

  printf("\n---------insertArrayList tests-----------------------\n\n");
  appendArrayList(list, 0);  
  appendArrayList(list, 4);  
  insertArrayList(list, 1, 2);
  testTrue(containsArrayList(list, 2), "Test 39");
  testEquals(getArrayList(list, 1), 2, "Test 40");
  testEquals(removeArrayList(list, 0), 0, "Test 41");
  testEquals(removeArrayList(list, 0), 2, "Test 42");
  testEquals(removeArrayList(list, 0), 4, "Test 43");
  testTrue(isEmptyArrayList(list), "Test 44");
  insertArrayList(list, 0, 3);
  testTrue(containsArrayList(list, 3), "Test 45");
  testEquals(removeArrayList(list, 0), 3, "Test 46");

  printf("\n---------indexOfArrayList tests----------------------\n\n");
  appendArrayList(list, 0);
  appendArrayList(list, 1);
  appendArrayList(list, 2);
  testEquals(indexOfArrayList(list, 0), 0, "Test 47"); 
  testEquals(indexOfArrayList(list, 1), 1, "Test 48"); 
  testEquals(indexOfArrayList(list, 2), 2, "Test 49"); 
  testEquals(indexOfArrayList(list, 9), -1, "Test 50"); 
  testEquals(indexOfArrayList(list, 8), -1, "Test 51"); 
  clearArrayList(list); 
  testEquals(indexOfArrayList(list, 0), -1, "Test 52");

  printf("\n---------initArrayList tests-------------------------\n\n");
  int arr[] = {1, 2, 3, 4, 5};
  ArrayList_t *another = initArrayList(arr, 5);
  testTrue(containsArrayList(another, 1), "Test 53");
  testTrue(containsArrayList(another, 2), "Test 54");
  testTrue(containsArrayList(another, 3), "Test 55");
  testTrue(containsArrayList(another, 4), "Test 56");
  testTrue(containsArrayList(another, 5), "Test 57");
  testTrue(!containsArrayList(another, 0), "Test 58");
  testTrue(!containsArrayList(another, 6), "Test 59");
  testTrue(!containsArrayList(another, 8), "Test 60");

  printf("\n---------arrayListToArray tests----------------------\n\n");
  int *newArr = arrayListToArray(another);
  testTrue(equalArrays(arr, newArr, another->length), "Test 61");
  int arr1[1];
  int *arr2 = arrayListToArray(list);
  testTrue(equalArrays(arr1, arr2, list->length), "Test 62");

  printf("\n---------arrayListToString tests---------------------\n\n");
  printf("Test 63:\n  Expected: ");
  printArray(newArr, another->length);
  char *strTest = arrayListToString(another);
  printf("  Actual:   %s\n", strTest); 

  clearArrayList(another);
  char expected[] = "[]";
  char *actual = arrayListToString(another);
  if (!testTrue(!strncmp(actual, expected, 3), "Test 64")) {
    printf("Expected: %s\n", expected);
    printf("Actual:   %s\n", actual); 
  }

  printf("\n---------cloneArrayList tests------------------------\n\n");
  ArrayList_t *clonedList = cloneArrayList(list);
  testTrue(clonedList != list, "Test 65"); 
  testTrue(equalsArrayList(list, clonedList), "Test 66");
  appendArrayList(list, 1); 
  appendArrayList(list, 2); 
  appendArrayList(list, 3); 
  appendArrayList(list, 4); 
  ArrayList_t *clonedList1 = cloneArrayList(list);
  testTrue(clonedList1 != list, "Test 67"); 
  testTrue(equalsArrayList(list, clonedList1), "Test 68");
  testTrue(containsArrayList(clonedList1, 1), "Test 69");
  testTrue(containsArrayList(clonedList1, 2), "Test 70");
  testTrue(containsArrayList(clonedList1, 3), "Test 71");
  testTrue(containsArrayList(clonedList1, 4), "Test 72");
  testTrue(!containsArrayList(clonedList1, 0), "Test 73");
  testTrue(!containsArrayList(clonedList1, 5), "Test 74");
  testEquals(lengthArrayList(clonedList1), 4, "Test 75");
  char expected1[] = "[1, 2, 3, 4]";
  char *actual1 = arrayListToString(clonedList1);
  if (!testTrue(!strcmp(actual1, expected1), "Test 76")) {
    printf("Expected: %s\n", expected1);
    printf("Actual:   %s\n", actual1); 
  }

  printf("\n---------cloneArrayList tests------------------------\n\n");
  ArrayList_t *subList = subListArrayList(list, 1, 3); 
  testEquals(lengthArrayList(subList), 2, "Test 77");
  testTrue(containsArrayList(subList, 2), "Test 78");
  testTrue(containsArrayList(subList, 3), "Test 79");
  testTrue(!containsArrayList(subList, 1), "Test 80");
  testTrue(!containsArrayList(subList, 4), "Test 81");
  char expected2[] = "[2, 3]";
  char *actual2 = arrayListToString(subList);
  if (!testTrue(!strcmp(actual2, expected2), "Test 82")) {
    printf("Expected: %s\n", expected2);
    printf("Actual:   %s\n", actual2); 
  }

  printf("\n------------------------------------------------------\n");
  printf("\nFreeing memory now... Run valgrind to check for leaks.\n");
  freeArrayList(list);
  freeArrayList(other);
  freeArrayList(another);
  freeArrayList(clonedList);
  freeArrayList(clonedList1);
  freeArrayList(subList);
  free(newArr);
  free(arr2); 
  free(strTest);
  free(actual);
  free(actual1);
  free(actual2);
  printf("\n------------------------------------------------------\n\n");
}
