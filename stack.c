#include <stdio.h>

void main() {
    int top = -1;
    int choice, value, size;

    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    int stack[size];

    while (1) {
        printf("\n--- STACK MENU ---");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Check if the stack is full
                if (top == size - 1) {
                    printf("Stack Overflow! Cannot push into the stack.\n");
                } else {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    top++;
                    stack[top] = value;
                    printf("%d pushed into the stack.\n", value);
                }
                break;

            case 2:
                // Check if the stack is empty
                if (top == -1) {
                    printf("Stack Underflow! Cannot pop from the stack.\n");
                } else {
                    value = stack[top];
                    top--;
                    printf("%d popped from the stack.\n", value);
                }
                break;

            case 3:
                // Display stack elements
                if (top == -1) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack elements are:\n");
                    for (int i = top; i >= 0; i--) {
                        printf("%d\n", stack[i]);
                    }
                }
                break;

            case 4:
                // Exit the program
                printf("Exiting program.\n");
                return;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    }
}
