#include <stdbool.h>

#ifndef HASH_H
#define HASH_H

//Key-value pair
typedef struct Pair {
  char *key;
  int value;
} Pair_t;

typedef struct HashMap {
  int size;
  Pair_t *map;
} HashMap_t;

/*
 * Creates a hash map and returns a pointer to it. 
 * Returns NULL if allocation fails.
 */
HashMap_t *hash_create(int size);

/*
 * Frees all memory allocated to hash map.
 */
void hash_free(HashMap_t *hash);

/*
 * Inserts key value pair to hash map. Key is NULL terminated string. 
 * Returns true if successful, false if failed/map full of key already exists.
 */
bool hash_insert(HashMap_t *hash, char *key, int value);

/*
 * Same as insert, but will override an existing pair if one exists,
 * if not, will create pair.
 */
bool hash_update(HashMap_t *hash, char *key, int value);

/*
 * Returns true if hash map contains a mapping for given key.
 */
bool hash_contains(HashMap_t *hash, char *key);

/* 
 * Removes key and associated value from map. Returns true if successfully 
 * removed and false if key not found.
 */
bool hash_remove(HashMap_t *hash, char *key);

#endif
