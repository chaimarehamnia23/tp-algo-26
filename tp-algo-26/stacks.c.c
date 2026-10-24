
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initStack(Stack* s) {
    s->top = NULL;
}

int isEmpty(Stack s) {
    return s.top == NULL;
}

void push(Stack* s, char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}


char pop(Stack* s) {
    Node* t;
    char value;
    if (s->top == NULL) return '\0';
    t = s->top;
    value = t->data;
    s->top = t->next;
    free(t);
    return value;
}


char peek(Stack s) {
    if (s.top == NULL) return '\0';
    return s.top->data;
}

int evaluatePostfix(char* exp1) {
    Stack s;
    int i, a, b, res = 0;
    initStack(&s);

    for (i = 0; exp1[i] != '\0'; i++) {
        if (exp1[i] >= '0' && exp1[i] <= '9') {
            push(&s, exp1[i] - '0');
        }
        else if (exp1[i] != ' ') {
            b = pop(&s);
            a = pop(&s);
            if (exp1[i] == '+') res = a + b;
            if (exp1[i] == '-') res = a - b;
            if (exp1[i] == '*') res = a * b;
            if (exp1[i] == '/') res = a / b;
            push(&s, res);
        }
    }
    return pop(&s);
}

void display(Stack s) {
    Node* ptr = s.top;
    if (ptr == NULL) {
        printf("Stack is empty\n");
        return;
    }
    while (ptr != NULL) {
        printf("%c ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    int choice, r;
    char x, exp1[100];

    initStack(&s);

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Postfix\n5. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a character: ");
                scanf(" %c", &x);
                push(&s, x);
                break;
            case 2:
                if (isEmpty(s))
                    printf("Stack is empty\n");
                else
                    printf("Popped: %c\n", pop(&s));
                break;
            case 3:
                display(s);
                break;
            case 4:
                printf("Enter expression: ");
                scanf(" %[^\n]", exp1);
                r = evaluatePostfix(exp1);
                printf("Result = %d\n", r);
                break;
            case 5:
                printf("Bye\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    } while (choice != 5);

    return 0;
}
