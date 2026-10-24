
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int customerNumber;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue q) {
    return q.front == NULL;
}

void enqueue(Queue* q, int number) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->customerNumber = number;
    n->next = NULL;

    if (q->rear == NULL) {
        q->front = n;
        q->rear = n;
    } else {
        q->rear->next = n;
        q->rear = n;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }

    Node* temp = q->front;
    int number = temp->customerNumber;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return number;
}

int peek(Queue q) {
    if (q.front == NULL) {
        return -1;
    }
    return q.front->customerNumber;
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 101);
    enqueue(&q, 102);

    printf("Front: %d\n", peek(q));
    printf("Served: %d\n", dequeue(&q));
    printf("Served: %d\n", dequeue(&q));

    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    }

    return 0;
}