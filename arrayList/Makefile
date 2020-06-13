CC = gcc 
CFLAGS = -g -Wall -pedantic
BUILD = testArrayList

all: $(BUILD)

clean:
	/bin/rm -f $(BUILD) *.o core

testArrayList: testArrayList.o arrayList.o

testArrayList.o: arrayList.h
arrayList.o: arrayList.h
