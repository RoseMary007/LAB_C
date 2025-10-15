#include <stdio.h>

int enqueue(int x);
int dequeue();
int isEmpty();

int front = -1;
int rear = -1;
int Queue[100];  
int visited[100];

int enqueue(int x) {
    if (rear == 99) { 
        printf("Queue Overflow\n");
        return -1;
    }
    if (front == -1)
        front = 0;
    rear++;
    Queue[rear] = x;
    return 0;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    int val = Queue[front];
    front++;
    if (front > rear) {
        front = -1;
        rear = -1;
    }
    return val;
}

int isEmpty() {
    return (front == -1);
}

int main() {
    int n, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int a[n][n];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &v);

   
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    
    enqueue(v);
    visited[v] = 1;

    printf("BFS traversal: ");

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        
        for (int i = 0; i < n; i++) {
            if (a[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");

    return 0;
}

