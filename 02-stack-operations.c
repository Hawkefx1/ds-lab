#include <stdio.h>
#define MAX 5

int s[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1) { puts("Stack Overflow!"); return; }
    s[++top] = x;
    printf("%d pushed.\n", x);
}

void pop() {
    if (top == -1) { puts("Stack Underflow!"); return; }
    printf("Popped: %d\n", s[top--]);
}

void disp() {
    if (top == -1) { puts("Stack is empty."); return; }
    printf("Stack (top to bottom): ");
    for (int i = top; i >= 0; i--) printf("%d ", s[i]);
    putchar('\n');
}

void pal() {
    char w[200];
    int ok = 1, len = 0;
    printf("Enter a word/string (no spaces): ");
    scanf("%199s", w);
    while (w[len]) len++;
    for (int i = 0; i < len / 2; i++) if (w[i] != w[len - 1 - i]) { ok = 0; break; }
    puts(ok ? "Palindrome." : "Not a palindrome.");
}

int main() {
    int ch, x;
    do {
        puts("\n1.Push 2.Pop 3.Check Palindrome 4.Demonstrate Overflow/Underflow 5.Display 6.Exit");
        printf("Choice: ");
        if (scanf("%d", &ch) != 1) break;
        switch (ch) {
            case 1: printf("Element: "); scanf("%d", &x); push(x); break;
            case 2: pop(); break;
            case 3: pal(); break;
            case 4: pop(); while (top < MAX - 1) push(10 + top + 1); push(99); break;
            case 5: disp(); break;
            case 6: puts("Exiting."); break;
            default: puts("Invalid choice.");
        }
    } while (ch != 6);
    return 0;
}
