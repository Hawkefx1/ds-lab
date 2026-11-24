#include <stdio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

int empty() { return front == -1; }
int full()  { return (rear + 1) % MAX == front; }

void insert(int x) {
    if (full()) { puts("Circular Queue Overflow!"); return; }
    if (empty()) front = 0;
    rear = (rear + 1) % MAX;
    q[rear] = x;
    puts("Inserted.");
}

void deleteItem() {
    if (empty()) { puts("Circular Queue Underflow!"); return; }
    printf("Deleted: %d\n", q[front]);
    if (front == rear) front = rear = -1;
    else front = (front + 1) % MAX;
}

void display() {
    if (empty()) { puts("Queue is empty."); return; }
    printf("Queue: ");
    for (int i = front; ; i = (i + 1) % MAX) {
        printf("%d ", q[i]);
        if (i == rear) break;
    }
    puts("");
}

int main() {
    int ch, x;
    do {
        printf("\n1.Insert 2.Delete 3.Display 4.Demonstrate Overflow 5.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Integer: "); scanf("%d", &x); insert(x); break;
            case 2: deleteItem(); break;
            case 3: display(); break;
            case 4: while (!full()) insert(100 + rear + 1); insert(999); break;
            case 5: puts("Exiting."); break;
            default: puts("Invalid choice.");
        }
    } while (ch != 5);
    return 0;
}
