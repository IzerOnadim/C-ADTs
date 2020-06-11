#include "hashMap.h"

#include <stdlib.h>
#define HASH (5381)

static int hash(char *str) {
  unsigned int result = HASH;
  
  while(*str++)
    result = (result << 5) + result + *str;
  
  return result;
}

HashMap_t *hash_create(int size) {
  if (size <= 0) {
    perror("HashMap cannot have size less than or equal to zero.");
    exit(EXIT_FAILURE);
  } 

  HashMap *hashMap = (HashMap_t *) malloc(sizeof(HashMap_t));
  if (!hashMap) return NULL;

  hashMap->size = size;
  hashMap->map = (Pair_t *) calloc(size, sizeof(Pair_t));  
  if (!hashMap->map) return NULL;

  return hashMap;
}

void hash_free(HashMap_t *hashMap) {
  free(hashMap->map);
  free(hashMap);
}

bool hash_insert(HashMap_t *hashMap, char *key, int value) {
  int index = hash(key) % (hashMap->size);  
}

bool hash_update(HashMap_t *hashMap, char *key, int value) {
  int index = hash(key) % (hashMap->size);  
}

bool hash_contains(HashMap_t *hashMap, char *key) {
  int index = hash(key) % (hashMap->size);  
}

bool hash_remove(HashMap_t *hashMap, char *key) {
  int index = hash(key) % (hashMap->size);  
}
