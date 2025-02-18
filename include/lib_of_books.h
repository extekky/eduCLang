#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH_STRING 100
#define MAX_NUMBERS_OF_BOOKS 100

typedef struct {
    char last_name[MAX_LENGTH_STRING];
    char first_name[MAX_LENGTH_STRING];
    char title[MAX_LENGTH_STRING];
    char publishing_house[MAX_LENGTH_STRING];
    int year_of_publication;
} Book;

extern Book *library;  
extern int *occ_places;

int add_book(Book book, int idx);
void print_library(void);
void delete_book(const int idx);
void initialize_library(void);

#endif
