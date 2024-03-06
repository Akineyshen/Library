#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PATH "library.txt"

typedef struct Book
{
    int id;
    char author[100];
    char title[100];
    char category[100];
    int year;
    char publisher[100];
    int available;
    struct Book *next;
} Book;

int compareBooksByAuthor(const void* a, const void* b) {
    return strcmp(((Book*)a)->author, ((Book*)b)->author);
}

int compareBooksByTitle(const void* a, const void* b) {
    return strcmp(((Book*)a)->title, ((Book*)b)->title);
}

int compareBooksByAvailability(const int* a, const int* b) {
    return *a - *b;
}


int getCountBook(Book *head);
Book* getLastBook(Book *head);
Book* getBookId(Book *head, int id);
void addBook(Book **head);
void addBookPush(Book **head, Book *book);
void delBook(Book **head);
int printAllBooks(Book *head);
void printBook(Book *book);
void readFile(Book **head);
void writeFile(Book *head);
void editBook(Book *head);
void searchBook(Book *head);
Book* sortedBook(Book *head);


int main()
{
    Book *head = NULL;
    readFile(&head);

        printf (",--.   ,--.,--.\n");
        printf ("|  |   `--'|  |-. ,--.--. ,--,--.,--.--.,--. ,--.\n");
        printf ("|  |   ,--.| .-. '|  .--'' ,-.  ||  .--' \  '  /\n");
        printf ("|  '--.|  || `-' ||  |   \ '-'   ||  |     \   '  \n");
        printf ("`-----'`--' `---' `--'    `--`--'`--'   .-'  /    \n");
        printf ("                                        `---'\n");
    int choice;
    while (1) {
        printf("\nLibrary management menu:\n");
        printf("\n1. Add a book\n");
        printf("2. Delete a book\n");
        printf("3. Edit a book\n");
        printf("4. Search a book\n");
        printf("5. View all books\n");
        printf("6. Sorts all books\n");
        printf("7. Save Changes\n");
        printf("8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addBook(&head);
                break;
            case 2:
                system ("cls");
                printf ("Deleting a book\n");
                printShortsBooks(head);
                delBook(&head);
                system ("cls");
                break;
            case 3:
                system ("cls");
                printf ("Book editing\n");
                printShortsBooks(head);
                editBook(head);
                system ("cls");
                break;
            case 4:
                system ("cls");
                searchBook(head);
                break;
            case 5:
                system ("cls");
                printAllBooks(head);
                break;
            case 6:
                system ("cls");
                sortedBook(head);
                break;
            case 7:
                writeFile(head);
                system ("cls");
                break;
            case 8:
                printf ("Goodbay\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

}


int getCountBook(Book *head)
{
    int counter = 0;
    while(head)
    {
        head = head->next;
        counter++;
    }
    return counter;
}


Book* getBookId(Book *head, int id)
{
    while(head)
    {
        if(head->id == id)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}


Book* getLastBook(Book *head)
{
    if (head == NULL)
        return NULL;

    while(head->next)
    {
        head = head->next;
    }

    return head;
}

void addBook(Book **head)
{
    system ("cls");
    Book *last = getLastBook((*head));
    Book *tmp = (Book*) malloc(sizeof(Book));

    // задает айди
    printf ("Book data entry \n");
    tmp->id = getCountBook((*head));
    printf("\nEnter the new author: ");
    fflush(stdin);
    fgets(tmp->author, 100 , stdin);
    tmp->author[strlen(tmp->author)-1] = 0;

    printf("Enter the new title: ");
    fflush(stdin);
    fgets(tmp->title, 100, stdin);
    tmp->title[strlen(tmp->title)-1] = 0;

    printf("Enter the new category: ");
    fflush(stdin);
    fgets(tmp->category, 100, stdin);
    tmp->category[strlen(tmp->category)-1] = 0;

    printf("Enter the new publisher: ");
    fflush(stdin);
    fgets(tmp->publisher, 100, stdin);
    tmp->publisher[strlen(tmp->publisher)-1] = 0;

    printf("Enter the new year: ");
    scanf("%d", &tmp->year);

    printf("Enter the new availability (1 for available, 0 for not available): ");
    scanf("%d", &tmp->available);
    while (tmp->available != 1 && tmp->available !=0)
    {
        printf ("\nRepit please");
        printf("\nEnter book availability (1 for available, 0 for not available): ");
        scanf("%d", &tmp->available);
    }

    if(getCountBook((*head)) == 0)
    {

        tmp->next = (*head);
        (*head) = tmp;
    } else {
        tmp->next = NULL;
        last->next = tmp;
    }
    system ("cls");
    printf("Book successfully added!\n");

}

void addBookPush(Book **head, Book *book)
{

    Book *last = getLastBook((*head));
    Book *tmp = (Book*) malloc(sizeof(Book));
    tmp->id = getCountBook((*head));
    strcpy(tmp->author, book->author);
    strcpy(tmp->title, book->title);
    strcpy(tmp->category, book->category);
    tmp->year = book->year;
    strcpy(tmp->publisher, book->publisher);
    tmp->available = book->available;

    if(getCountBook((*head)) == 0)
    {
        tmp->next = (*head);
        (*head) = tmp;
    } else {
        tmp->next = NULL;
        last->next = tmp;
    }
}

int printAllBooks(Book *head)
{
    Book *tmp = head;
    while(head)
    {
        printf("\nCatalog: %d\n", head->id);
        printf("Title: %s \n", head->title);
        printf("Author: %s \n", head->author);
        head = head->next;
    }

    head = tmp;

    int choice;
    printf ("\nView the full information of the selected book?");
    printf ("\n1. Yes \n2. No\n");
    printf ("Choose: ");
    scanf ("%d", &choice);
    if(choice == 2)
        return 0;
    if (choice == 1)
        printf("\nEnter the catalog number of the book you want to view information of: ");
    int id;
    scanf("%d", &id);
    system ("cls");
    printBook(getBookId(head, id));
}

int printShortsBooks(Book *head)
{
    Book *tmp = head;
    while(head)
    {
        printf("\ncatalog: %d\n", head->id);
        printf("Title: %s \n", head->title);
        printf("Author: %s \n", head->author);
        head = head->next;
    }
    head = tmp;
}

void writeFile(Book *head)
{
    FILE *file;
    file = fopen(PATH, "wb");
    while(head)
    {
        fprintf(file, "%d,%s,%s,%s,%d,%s,%d \n", head->id, head->author, head->title, head->category, head->year, head->publisher, head->available);
        head = head->next;
    }
    fclose(file);
}

void readFile(Book **head)
{
    FILE *file = fopen(PATH, "rb");
    Book *book = (Book*) malloc(sizeof(Book));

    char str[2000];
    char *istr;
    int count = 0;
    while(fgets(str, 2000, file) != NULL)
    {
        istr = strtok (str,",");
        count += 1;
        while (istr != NULL)
        {
            if(count == 1)
                book->id = atoi(istr);
            else if (count == 2)
                strcpy(book->author, istr);
            else if (count == 3)
                strcpy(book->title, istr);
            else if (count == 4)
                strcpy(book->category, istr);
            else if (count == 5)
                book->year = atoi(istr);
            else if (count == 6)
                strcpy(book->publisher, istr);
            else if (count == 7)
                book->available = atoi(istr);
            istr = strtok (NULL,",");
            count += 1;
        }
        addBookPush(head, book);
        count = 0;
    }

    fclose(file);
}

void printBook(Book *book)
{
    printf("\ncatalog: %d \n", book->id);
    printf("Author: %s \n", book->author);
    printf("Title: %s \n", book->title);
    printf("Category: %s \n", book->category);
    printf("Year: %d \n", book->year);
    printf("Publisher: %s \n", book->publisher);
    printf("Available: %d \n", book->available);
}

void delBook(Book **head)
{
    int id;
    printf("\nEnter the catalog number of the book to delete: ");
    scanf("%d", &id);

    if(id == 0)
    {
            if ((*head)->available == 0) {
            printf("This book is not available and cannot be deleted\n");
            return;
        }
        Book* prev = NULL;
        if(head == NULL)
            exit(-1);
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    } else {
        Book *prev = getBookId((*head), id-1);
        if(prev != NULL)
        {
            Book *book = prev->next;
            prev->next = book->next;
            free(book);
        }
    }
}

void editBook(Book *head)
{
    int id;
    printf("\nEnter book catalog to edit: ");
    scanf("%d", &id);

    Book *book = getBookId(head, id);

    if(book)
    {
        printf("Enter the new author: ");
        fflush(stdin);
        fgets(book->author, 100 , stdin);
        book->author[strlen(book->author)-1] = 0;

        printf("Enter the new title: ");
        fflush(stdin);
        fgets(book->title, 100 , stdin);
        book->title[strlen(book->title)-1] = 0;

        printf("Enter the new category: ");
        fflush(stdin);
        fgets(book->category, 100 , stdin);
        book->category[strlen(book->category)-1] = 0;

        printf("Enter the new year: ");
        scanf("%d", &book->year);

        printf("Enter the new publisher: ");
        fflush(stdin);
        fgets(book->publisher, 100 , stdin);
        book->publisher[strlen(book->publisher)-1] = 0;

        printf("Enter the new available(1 for available, 0 for not available): ");
        scanf("%d", &book->available);

        printf("Book edited!");

    } else {
        printf("Book not found!");
    }

}

void searchBook(Book *head)
{
    int choice;
    printf("\nEnter your search criteria:\n");
    printf("1. Author\n");
    printf("2. Title\n");
    printf("3. Year\n");
    printf("4. Availability\n");
    printf ("\nChoose: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        char author[5000];
        printf("Enter author name: ");
        scanf("%s", author);
        system ("cls");
        printf("Books by %s:\n", author);

        while(head)
        {
            if(strncmp(head->author, author, strlen(author)) == 0)
                printf("%d, %s, %s, %s, %d, %s, %s, %d \n", head->id, head->author, head->title, head->category, head->year, head->publisher, head->publisher, head->available);
            head = head->next;
        }

    } else if(choice == 2) {
        char title[5000];
        printf("Enter title: ");
        scanf("%s", title);
        system ("cls");
        printf("Books with title: %s \n", title);
        while(head)
        {
            if(strncmp(head->title, title, strlen(title)) == 0)
                printf("%d, %s, %s, %s, %d, %s, %s, %d \n", head->id, head->author, head->title, head->category, head->year, head->publisher, head->publisher, head->available);
            head = head->next;
        }
    } else if(choice == 3) {
        int year;
        printf("Enter year: ");
        scanf("%d", &year);
        system ("cls");
        printf("Books from year: %d \n", year);
        while(head)
        {
            if(head->year == year)
                printf("%d, %s, %s, %s, %d, %s, %s, %d \n", head->id, head->author, head->title, head->category, head->year, head->publisher, head->publisher, head->available);
            head = head->next;
        }
    } else if(choice == 4) {
        int available;
        printf("Enter availability (0 for available, 1 for not available): ");
        scanf("%d", &available);
        system ("cls");
        printf("\nBooks %s:\n", available == 0 ? "available" : "not available" );
        while(head)
        {
            if(head->available == available)
            {
                printf("%d, %s, %s, %s, %d, %s, %s, %d \n", head->id, head->author, head->title, head->category, head->year, head->publisher, head->publisher, head->available);
            }
            head = head->next;
        }
    } else {
        printf("Invalid choice.\n");
    }
}

Book* sortedBook(Book *head)
{
    int size = getCountBook(head);
    Book *Books = (Book*)malloc(size*sizeof(Book));

    Book *tmp = head;

    int i = 0;
    while(head)
    {
        Books[i].id = head->id;
        strcpy(Books[i].author, head->author);
        strcpy(Books[i].title, head->title);
        strcpy(Books[i].category, head->category);
        Books[i].year = head->year;
        strcpy(Books[i].publisher, head->publisher);
        Books[i].available = head->available;
        head = head->next;
        i++;
    }
    head = tmp;

    printf("Sort by:\n1. Author\n2. Title\n3. Availability\nChoose: ");
    int choice;
    scanf("%d", &choice);
    system ("cls");

    if (choice == 1) {
        qsort(Books, size, sizeof(Book), compareBooksByAuthor);
        while(head)
    {
        printf("%s\n", head->author);
        head = head->next;
    }
    } else if (choice == 2) {
        qsort(Books, size, sizeof(Book), compareBooksByTitle);
        while(head)
    {
        printf("%s\n", head->title);
        head = head->next;
    }
    } else if (choice == 3) {
        qsort(Books, size, sizeof(Book), (int(*) (const void *, const void *)) compareBooksByAvailability);
        printf("\nShow books (available - 1, not available - 0\n");
        printf ("Choose:");
        scanf("%d", &choice);
        system ("cls");
        switch(choice) {
        case 1:
                while(head)
                {
                    if (head->available == 1)
                    printf("%s\n", head->title);
                    head = head->next;
                }
            break;
        case 0:
                while(head)
                {
                    if(head->available == 0)
                    printf("%s\n", head->title);
                    head = head->next;
                }
                break;
        }
    } else {
        printf("Invalid choice.\n");
    }

    i = 0;
    while(head)
    {
        head->id = Books[i].id;
        strcpy(head->author, Books[i].author);
        strcpy(head->title, Books[i].title);
        strcpy(head->category, Books[i].category);
        strcpy(head->publisher, Books[i].publisher);
        head->year = Books[i].year;
        head->available = Books[i].available;

        head = head->next;
        i++;
    }
}
