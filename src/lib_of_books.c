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

Book *library = NULL;
int *occ_places = NULL; // occupied places in linbrary

int add_book(Book book, int idx)
{
        // !! Добавить проверку на лимит MAX_LENGTH_STRING
        strcpy(library[idx].first_name, book.first_name);
        strcpy(library[idx].last_name, book.last_name);
        strcpy(library[idx].title, book.title);
        strcpy(library[idx].publishing_house, book.publishing_house);
        library[idx].year_of_publication = book.year_of_publication;

        // occ_places
        return 0;
}

void print_library(void)
{
        for (int i = 0; i < MAX_NUMBERS_OF_BOOKS; i++) {
                if (library[i].year_of_publication != 0) {
                        printf("%s, %s, %s, %s, %d\n", 
                        library[i].first_name,
                        library[i].last_name,
                        library[i].title,
                        library[i].publishing_house,
                        library[i].year_of_publication);
                }
        }
        printf("End of list books\n");
}
// void print_bookInfo_by_name() {}

void delete_book(const int idx)
{
        for (int i = 0; i < MAX_NUMBERS_OF_BOOKS; i++) {
                if (i == idx) {
                        library[i] = (Book){"", "", "", "", 0};
                        return;
                }
        }
        printf("There is no book by index %d!\n", idx);
}

void initialize_library(void)
{
        library = calloc(MAX_NUMBERS_OF_BOOKS, sizeof(Book));
        // occ_places = calloc(MAX_NUMBERS_OF_BOOKS, sizeof(int));

        if (library == NULL /*|| occ_places == NULL*/) {
                fprintf(stderr, "Memory allocation error\n");
                exit(1);
        }
}

// int main() {
//     initialize_library();
//     add_book((Book){"Толстой", "Лев", "Война и мир", "Эксмо", 1869}, 0);
//     add_book((Book){"Достоевский", "Федор", "Преступление и наказание", "АСТ", 1866},1);
//     add_book((Book){"Пушкин", "Александр", "Евгений Онегин", "Наука", 1833}, 99);
//     delete_book(999);
//     print_library();

//     printf("Program execute seccesfull!\n");
//     return 0;
// }