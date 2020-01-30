/** @file */
#pragma once
#include "lists_generation.h"

/**
 * Deallocates memory for given Book pointer to head of list
 * @param hd head of deallocated list
 */
void destroyBooks(Book** hd);

/**
 * Deallocates memory for given Label pointer to Linked List. Function uses detroyBooks.
 * @param hd head of deallocated list
 */
void destroyLabels(Label** hd);