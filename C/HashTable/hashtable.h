/**
 * hashtable.h - implementation of a hash table with linear probing collision
 * resolution strategy.
 *
 * @author: Jason Turley
 * @date: 6 June 2019
 */

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_


struct pair {
	char *key;
	char *value;
};

typedef struct _hashtable {
	struct pair **slots;
	size_t nelems;
	size_t size;
} hashtable_t;

/**
 * Creates a hashtable with `tsize` slots.
 */
hashtable_t *create_table(size_t tsize);

/**
 * A naive hash algorithm.
 */
int naive_hash(char *key, size_t tsize);

/**
 * Bernstein hash algorithm.
 */
int bernstein_hash(char *key, size_t tsize);

/**
 * Inserts a key-value pair into the hash table.
 */
void insert(hashtable_t ht, char *key, char *value);

/**
 * Returns the value associated with the key.
 */
char *get(hashtable_t ht, char *key);

/**
 * Destroys the given hashtable.
 */
void destroy_table(hashtable_t *ht);

#endif
