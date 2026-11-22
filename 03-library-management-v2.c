#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 80
#define N 60

typedef struct { int id; char title[T], author[N]; float price; int avail; } Book;
Book *b; int n = 0;

void clr() { int c; while ((c = getchar()) != '\n' && c != EOF); }
void rl(char *s, int sz) { if (fgets(s, sz, stdin)) s[strcspn(s, "\n")] = '\0'; }

void create() {
    printf("Number of books to add: ");
    if (scanf("%d", &n) != 1 || n <= 0) { n = 0; puts("Invalid number."); clr(); return; }
    clr(); free(b);
    b = calloc(n, sizeof(Book));
    if (!b) { puts("Memory allocation failed."); n = 0; return; }
    for (int i = 0; i < n; i++) {
        printf("\nBook %d ID: ", i + 1); scanf("%d", &b[i].id); clr();
        printf("Title: "); rl(b[i].title, T);
        printf("Author: "); rl(b[i].author, N);
        printf("Price: "); scanf("%f", &b[i].price); clr();
        b[i].avail = 1;
    }
}

int find(int id) { for (int i = 0; i < n; i++) if (b[i].id == id) return i; return -1; }
void show(int i) {
    printf("%-8d %-24s %-18s %8.2f %s\n", b[i].id, b[i].title, b[i].author, b[i].price,
           b[i].avail ? "Available" : "Issued");
}

void display() {
    int count = 0;
    if (!b || n == 0) { puts("No book records. Add records first."); return; }
    puts("ID       Title                    Author                Price Status");
    for (int i = 0; i < n; i++) if (b[i].avail) { show(i); count++; }
    if (!count) puts("No books are currently available.");
}

void search() {
    int id; printf("Enter Book ID: "); scanf("%d", &id);
    int i = find(id);
    if (i < 0) { puts("Book not found."); return; }
    puts("ID       Title                    Author                Price Status");
    show(i);
}

void issueBook() {
    int id; printf("Enter Book ID to issue: "); scanf("%d", &id);
    int i = find(id);
    if (i < 0) puts("Book not found.");
    else if (!b[i].avail) puts("Book is already issued.");
    else { b[i].avail = 0; puts("Book issued successfully."); }
}

void returnBook() {
    int id; printf("Enter Book ID to return: "); scanf("%d", &id);
    int i = find(id);
    if (i < 0) puts("Book not found.");
    else if (b[i].avail) puts("Book is already available.");
    else { b[i].avail = 1; puts("Book returned successfully."); }
}

int main() {
    int ch;
    do {
        puts("\n1.Add Book Records  2.Display Available Books  3.Search by ID");
        puts("4.Issue a Book      5.Return a Book              6.Exit");
        printf("Choice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: puts("Exiting."); break;
            default: puts("Invalid choice.");
        }
    } while (ch != 6);
    free(b);
    return 0;
}
