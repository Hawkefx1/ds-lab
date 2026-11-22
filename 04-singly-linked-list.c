#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define S 30

typedef struct Node {
    char usn[S], name[S], branch[S];
    int sem;
    struct Node *next;
} Node;

Node *head = NULL;

Node *readNode() {
    Node *p = malloc(sizeof(Node));
    if (!p) { puts("Memory allocation failed."); exit(1); }
    printf("USN: "); scanf("%29s", p->usn);
    printf("Name (one word): "); scanf("%29s", p->name);
    printf("Branch: "); scanf("%29s", p->branch);
    printf("Semester: "); scanf("%d", &p->sem);
    p->next = NULL;
    return p;
}

void frontIns() { Node *p = readNode(); p->next = head; head = p; }

void endIns() {
    Node *p = readNode(), *t;
    if (!head) { head = p; return; }
    for (t = head; t->next; t = t->next);
    t->next = p;
}

void delFront() {
    if (!head) { puts("List is empty."); return; }
    Node *t = head; head = head->next; free(t);
    puts("First record deleted.");
}

void delEnd() {
    Node *t, *prev = NULL;
    if (!head) { puts("List is empty."); return; }
    for (t = head; t->next; t = t->next) prev = t;
    if (prev) prev->next = NULL; else head = NULL;
    free(t);
    puts("Last record deleted.");
}

void disp() {
    Node *t = head; int count = 0;
    if (!t) puts("List is empty.");
    puts("USN\tName\tBranch\tSem");
    while (t) { printf("%s\t%s\t%s\t%d\n", t->usn, t->name, t->branch, t->sem); t = t->next; count++; }
    printf("Number of nodes: %d\n", count);
}

void search() {
    char key[S]; Node *t = head;
    printf("Enter USN to search: "); scanf("%29s", key);
    while (t && strcmp(t->usn, key)) t = t->next;
    if (!t) puts("Student not found.");
    else printf("Found: %s %s %s Semester %d\n", t->usn, t->name, t->branch, t->sem);
}

int main() {
    int ch;
    do {
        puts("\n1.Front Insert 2.Display/Count 3.End Insert 4.Delete Front 5.Delete End 6.Search USN 7.Exit");
        printf("Choice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: frontIns(); break;
            case 2: disp(); break;
            case 3: endIns(); break;
            case 4: delFront(); break;
            case 5: delEnd(); break;
            case 6: search(); break;
            case 7: puts("Exiting."); break;
            default: puts("Invalid choice.");
        }
    } while (ch != 7);
    while (head) { Node *t = head; head = head->next; free(t); }
    return 0;
}
