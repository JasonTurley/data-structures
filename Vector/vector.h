/**
 * A C style implementation of std::vector.
 */
#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <stdbool.h>
#include <stdlib.h>

/**
 * Used to set the capacity of the vector in vector_create()
 */
#define MIN_CAPACITY 16

/**
 * How much the vector will grow by in automatic allocation (2 means double).
 */
#define GROWTH_FACTOR 2

/**
 * Returns a pointer to a newly created, empty vector.
 *
 */
struct vector *vector_create(size_t capacity);

/**
 * Destroys all container elements of the vector.
 */
void vector_destroy(struct vector *vec);

/**
 * Returns the current number of elements in the vector. Note, this is not
 * necessarily equal to its capacity.
 */
size_t size(struct vector *vec);

/**
 * Returns the number of items this vector can hold.
 */
size_t capacity(struct vector *vec);

/**
 * Checks if the current vector is empty.
 */
int is_empty(struct vector *vec);

/**
 * Returns the item at a given index.
 */
int at(struct vector *vec, int index);

/**
 * Adds a new element to the end of the vector, increasing its size
 * by one. 
 *
 * This automatically resizes the container if necessary.
 */
void push(struct vector *vec, int item);

/**
 * Inserts item at index and shifts that index's value and all trailing
 * items to the right.
 */
void insert(struct vector *vec, int index, int item);

/**
 * Adds an item to the front of the vector, index 0.
 */
void prepend(struct vector *vec, int item);

/**
 * Removes and returns the last element in the vector, reducing its size by one. 
 */
int pop(struct vector *vec);

/**
 * Searches for iterm and removes index holding it, even if in multiple places.
 */
void remove_item(struct vector *vec, int item);

/**
 * Searches for a value and returns the first index with that value, 
 * -1 if not found.
 */
int find(struct vector *vec, int item);

#endif
