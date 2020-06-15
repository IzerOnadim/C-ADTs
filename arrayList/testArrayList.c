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
  ArrayList_t *list = arrayListCreate();
  
  printf("\n---------Contains appended elements-------------------\n\n");
  arrayListAppend(list, 0);
  arrayListAppend(list, 1);
  arrayListAppend(list, 2);
  arrayListAppend(list, 3);
  testbool(arrayListContains(list, 3), "Test 01");
  testbool(arrayListContains(list, 2), "Test 02");
  testbool(arrayListContains(list, 0), "Test 03");
  testbool(arrayListContains(list, 1), "Test 04");

  printf("\n---------Doesn't contain removed elements-------------\n\n");
  arrayListRemove(list, 0);
  testbool(!arrayListContains(list, 0), "Test 05");
  arrayListRemove(list, 0);
  testbool(!arrayListContains(list, 1), "Test 06");
  arrayListRemove(list, 0);
  testbool(!arrayListContains(list, 2), "Test 07");
  arrayListRemove(list, 0);
  testbool(!arrayListContains(list, 3), "Test 08");

  printf("\n---------Only removes one element at a time-----------\n\n");
  arrayListAppend(list, 0);
  arrayListAppend(list, 0);
  arrayListRemove(list, 1);
  testbool(arrayListContains(list, 0), "Test 09");
  arrayListRemove(list, 0);
  testbool(!arrayListContains(list, 0), "Test 10");
  
  printf("\n---------isEmpty tests-------------------------------\n\n");
  arrayListAppend(list, 13);
  testbool(!arrayListIsEmpty(list), "Test 11");
  arrayListRemove(list, 0);
  testbool(arrayListIsEmpty(list), "Test 12");
  
  printf("\n---------length tests---------------------------------\n\n");
  arrayListAppend(list, 13);
  testbool(arrayListLength(list) == 1, "Test 13");
  arrayListAppend(list, 0);
  testbool(arrayListLength(list) == 2, "Test 14");
  arrayListAppend(list, 2753);
  testbool(arrayListLength(list) == 3, "Test 15");
  arrayListAppend(list, 123456);
  testbool(arrayListLength(list) == 4, "Test 16");
  arrayListRemove(list, 3);
  testbool(arrayListLength(list) == 3, "Test 17");
  arrayListRemove(list, 2);
  testbool(arrayListLength(list) == 2, "Test 18");
  arrayListRemove(list, 1);
  testbool(arrayListLength(list) == 1, "Test 19");
  arrayListRemove(list, 0);
  testbool(arrayListLength(list) == 0, "Test 20");
  
  printf("\n---------equals tests---------------------------------\n\n");
  ArrayList_t *other = arrayListCreate();
  testbool(arrayListEquals(list, other), "Test 21");
  arrayListAppend(other, 1); 
  testbool(!arrayListEquals(list, other), "Test 22");
  arrayListAppend(other, 2); 
  arrayListAppend(list, 1); 
  arrayListAppend(list, 2); 
  testbool(arrayListEquals(list, other), "Test 23");
  arrayListAppend(list, 2); 
  testbool(!arrayListEquals(list, other), "Test 24");
  arrayListAppend(other, 2); 
  testbool(arrayListEquals(list, other), "Test 25");
  arrayListRemove(list, 2);
  testbool(!arrayListEquals(list, other), "Test 26");
  arrayListRemove(other, 1);
  testbool(arrayListEquals(list, other), "Test 27");
  arrayListRemove(other, 0);
  arrayListRemove(other, 0);
  arrayListRemove(list, 0);
  arrayListRemove(list, 0);
  testbool(arrayListEquals(list, other), "Test 28");
  
  printf("\n---------get tests-----------------------------------\n\n");
  arrayListAppend(list, 13);
  testbool(arrayListGet(list, 0) == 13, "Test 29");
  testbool(arrayListGet(list, 0) == 13, "Test 30");
  arrayListAppend(list, 246772);
  arrayListAppend(list, -5463);
  arrayListAppend(list, 0x500);
  arrayListAppend(list, -0x500);
  testbool(arrayListGet(list, 1) == 246772, "Test 31");
  testbool(arrayListGet(list, 2) == -5463, "Test 32");
  testbool(arrayListGet(list, 3) == 0x500, "Test 33");
  testbool(arrayListGet(list, 4) == -0x500, "Test 34");

  printf("\n---------clear tests---------------------------------\n\n");
  testbool(!arrayListIsEmpty(list), "Test 35");
  arrayListClear(list);
  testbool(arrayListIsEmpty(list), "Test 36");
  testbool(!arrayListContains(list, 13), "Test 37");
  testbool(!arrayListContains(list, 246772), "Test 38");

  printf("\n---------insert tests--------------------------------\n\n");
  arrayListAppend(list, 0);  
  arrayListAppend(list, 4);  
  arrayListInsert(list, 1, 2);
  testbool(arrayListContains(list, 2), "Test 39");
  testbool(arrayListGet(list, 1) == 2, "Test 40");
  testbool(arrayListRemove(list, 0) == 0, "Test 41");
  testbool(arrayListRemove(list, 0) == 2, "Test 42");
  testbool(arrayListRemove(list, 0) == 4, "Test 43");
  testbool(arrayListIsEmpty(list), "Test 44");
  arrayListInsert(list, 0, 3);
  testbool(arrayListContains(list, 3), "Test 45");
  testbool(arrayListRemove(list, 0) == 3, "Test 46");

  printf("\n---------insert tests--------------------------------\n\n");
  arrayListAppend(list, 0);
  arrayListAppend(list, 1);
  arrayListAppend(list, 2);
  testbool(arrayListIndexOf(list, 0) == 0, "Test 47"); 
  testbool(arrayListIndexOf(list, 1) == 1, "Test 48"); 
  testbool(arrayListIndexOf(list, 2) == 2, "Test 49"); 
  testbool(arrayListIndexOf(list, 9) == -1, "Test 50"); 
  testbool(arrayListIndexOf(list, 8) == -1, "Test 51"); 
  arrayListClear(list); 
  testbool(arrayListIndexOf(list, 0) == -1, "Test 52");

  printf("\n------------------------------------------------------\n");
  printf("\nFreeing memory now... Run valgrind to check for leaks.\n");
  arrayListFree(list);
  arrayListFree(other); 
  printf("\n------------------------------------------------------\n\n");
}
