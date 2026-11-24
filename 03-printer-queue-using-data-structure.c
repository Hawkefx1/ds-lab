#include <stdio.h>
#define MAX 5

char q[MAX][80];
int front = 0, rear = -1, count = 0;

void addJob() {
    if (count == MAX) { puts("Queue Overflow! Printer queue is full."); return; }
    printf("Enter print job name: ");
    scanf(" %79[^\n]", q[(rear + 1) % MAX]);
    rear = (rear + 1) % MAX;
    count++;
    puts("Print job added.");
}

void processJob() {
    if (!count) { puts("Queue Underflow! No jobs to process."); return; }
    printf("Processing job: %s\n", q[front]);
    front = (front + 1) % MAX;
    count--;
    if (!count) { front = 0; rear = -1; }
}

void display() {
    if (!count) { puts("No pending print jobs."); return; }
    puts("Pending print jobs:");
    for (int i = 0; i < count; i++)
        printf("%d. %s\n", i + 1, q[(front + i) % MAX]);
}

int main() {
    int ch;
    do {
        printf("\n1.Add Job 2.Process Job 3.Display Jobs 4.Count Jobs 5.Test Underflow 6.Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF); // flush garbage input
            puts("Invalid input. Enter a number.");
            continue;
        }
        switch (ch) {
            case 1: addJob(); break;
            case 2: processJob(); break;
            case 3: display(); break;
            case 4: printf("Jobs waiting: %d\n", count); break;
            case 5: if (!count) processJob(); else puts("Queue is not empty; process jobs to test underflow."); break;
            case 6: puts("Exiting."); break;
            default: puts("Invalid choice.");
        }
    } while (ch != 6);
    return 0;
}
