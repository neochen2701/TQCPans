#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int id;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

void put(Queue* q, int id) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->id = id;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        q->size = 1;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
    q->size++;
}

int get(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    Node* temp = q->front;
    int id = temp->id;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    q->size--;
    return id;
}

int main() {
    int n, x;
    scanf("%d", &n);
    scanf("%d", &x);

    Queue* allIds = createQueue();
    for (int i = 1; i <= n; i++) {
        put(allIds, i);
    }

    while (allIds->size > 1) {
        for (int i = 1; i < x; i++) {
            int t = get(allIds);
            put(allIds, t);
        }
        get(allIds);
    }

    printf("%d\n", get(allIds));
    return 0;
}
