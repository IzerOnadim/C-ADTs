#include "arrayList.h"

#include <stdio.h>
#include <stdbool.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void testbool(bool condition, char *testname) {
  printf("%s: %s\n", testname, condition ?  
      ANSI_COLOR_GREEN "OK"  ANSI_COLOR_RESET :
      ANSI_COLOR_RED  "FAIL" ANSI_COLOR_RESET); 
}

int main(void) {
  ArrayList_t *list = createArrayList();
  
  printf("\n---------Contains appended elements-------------------\n\n");
  appendArrayList(list, 0);
  appendArrayList(list, 1);
  appendArrayList(list, 2);
  appendArrayList(list, 3);
  testbool(containsArrayList(list, 3), "Test 01");
  testbool(containsArrayList(list, 2), "Test 02");
  testbool(containsArrayList(list, 0), "Test 03");
  testbool(containsArrayList(list, 1), "Test 04");

  printf("\n---------Doesn't contain removed elements-------------\n\n");
  removeArrayList(list, 0);
  testbool(!containsArrayList(list, 0), "Test 05");
  removeArrayList(list, 0);
  testbool(!containsArrayList(list, 1), "Test 06");
  removeArrayList(list, 0);
  testbool(!containsArrayList(list, 2), "Test 07");
  removeArrayList(list, 0);
  testbool(!containsArrayList(list, 3), "Test 08");

  printf("\n---------Only removes one element at a time-----------\n\n");
  appendArrayList(list, 0);
  appendArrayList(list, 0);
  removeArrayList(list, 1);
  testbool(containsArrayList(list, 0), "Test 09");
  removeArrayList(list, 0);
  testbool(!containsArrayList(list, 0), "Test 10");
  
  printf("\n---------isEmpty tests-------------------------------\n\n");
  appendArrayList(list, 13);
  testbool(!isEmptyArrayList(list), "Test 11");
  removeArrayList(list, 0);
  testbool(isEmptyArrayList(list), "Test 12");
  
  printf("\n---------length tests---------------------------------\n\n");
  appendArrayList(list, 13);
  testbool(lengthArrayList(list) == 1, "Test 13");
  appendArrayList(list, 0);
  testbool(lengthArrayList(list) == 2, "Test 14");
  appendArrayList(list, 2753);
  testbool(lengthArrayList(list) == 3, "Test 15");
  appendArrayList(list, 123456);
  testbool(lengthArrayList(list) == 4, "Test 16");
  removeArrayList(list, 3);
  testbool(lengthArrayList(list) == 3, "Test 17");
  removeArrayList(list, 2);
  testbool(lengthArrayList(list) == 2, "Test 18");
  removeArrayList(list, 1);
  testbool(lengthArrayList(list) == 1, "Test 19");
  removeArrayList(list, 0);
  testbool(lengthArrayList(list) == 0, "Test 20");
  
  printf("\n---------equals tests---------------------------------\n\n");
  ArrayList_t *other = createArrayList();
  testbool(equalsArrayList(list, other), "Test 21");
  appendArrayList(other, 1); 
  testbool(!equalsArrayList(list, other), "Test 22");
  appendArrayList(other, 2); 
  appendArrayList(list, 1); 
  appendArrayList(list, 2); 
  testbool(equalsArrayList(list, other), "Test 23");
  appendArrayList(list, 2); 
  testbool(!equalsArrayList(list, other), "Test 24");
  appendArrayList(other, 2); 
  testbool(equalsArrayList(list, other), "Test 25");
  removeArrayList(list, 2);
  testbool(!equalsArrayList(list, other), "Test 26");
  removeArrayList(other, 1);
  testbool(equalsArrayList(list, other), "Test 27");
  removeArrayList(other, 0);
  removeArrayList(other, 0);
  removeArrayList(list, 0);
  removeArrayList(list, 0);
  testbool(equalsArrayList(list, other), "Test 28");
  
  printf("\n---------get tests-----------------------------------\n\n");
  appendArrayList(list, 13);
  testbool(getArrayList(list, 0) == 13, "Test 29");
  testbool(getArrayList(list, 0) == 13, "Test 30");
  appendArrayList(list, 246772);
  appendArrayList(list, -5463);
  appendArrayList(list, 0x500);
  appendArrayList(list, -0x500);
  testbool(getArrayList(list, 1) == 246772, "Test 31");
  testbool(getArrayList(list, 2) == -5463, "Test 32");
  testbool(getArrayList(list, 3) == 0x500, "Test 33");
  testbool(getArrayList(list, 4) == -0x500, "Test 34");

  printf("\n---------clear tests---------------------------------\n\n");
  testbool(!isEmptyArrayList(list), "Test 35");
  clearArrayList(list);
  testbool(isEmptyArrayList(list), "Test 36");
  testbool(!containsArrayList(list, 13), "Test 37");
  testbool(!containsArrayList(list, 246772), "Test 38");

  printf("\n---------insert tests--------------------------------\n\n");
  appendArrayList(list, 0);  
  appendArrayList(list, 4);  
  insertArrayList(list, 1, 2);
  testbool(containsArrayList(list, 2), "Test 39");
  testbool(getArrayList(list, 1) == 2, "Test 40");
  testbool(removeArrayList(list, 0) == 0, "Test 41");
  testbool(removeArrayList(list, 0) == 2, "Test 42");
  testbool(removeArrayList(list, 0) == 4, "Test 43");
  testbool(isEmptyArrayList(list), "Test 44");
  insertArrayList(list, 0, 3);
  testbool(containsArrayList(list, 3), "Test 45");
  testbool(removeArrayList(list, 0) == 3, "Test 46");

  printf("\n---------index of tests------------------------------\n\n");
  appendArrayList(list, 0);
  appendArrayList(list, 1);
  appendArrayList(list, 2);
  testbool(indexOfArrayList(list, 0) == 0, "Test 47"); 
  testbool(indexOfArrayList(list, 1) == 1, "Test 48"); 
  testbool(indexOfArrayList(list, 2) == 2, "Test 49"); 
  testbool(indexOfArrayList(list, 9) == -1, "Test 50"); 
  testbool(indexOfArrayList(list, 8) == -1, "Test 51"); 
  clearArrayList(list); 
  testbool(indexOfArrayList(list, 0) == -1, "Test 52");

  printf("\n---------init tests----------------------------------\n\n");
  int arr[] = {1, 2, 3, 4, 5};
  ArrayList_t *another = initArrayList(arr, 5);
  testbool(containsArrayList(another, 1), "Test53");
  testbool(containsArrayList(another, 2), "Test54");
  testbool(containsArrayList(another, 3), "Test55");
  testbool(containsArrayList(another, 4), "Test56");
  testbool(containsArrayList(another, 5), "Test57");
  testbool(!containsArrayList(another, 0), "Test58");
  testbool(!containsArrayList(another, 6), "Test59");
  testbool(!containsArrayList(another, 8), "Test60");

  printf("\n------------------------------------------------------\n");
  printf("\nFreeing memory now... Run valgrind to check for leaks.\n");
  freeArrayList(list);
  freeArrayList(other);
  freeArrayList(another); 
  printf("\n------------------------------------------------------\n\n");
}
