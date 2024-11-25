#include <stdio.h>
#include <stdlib.h>

#define MAX 100


int n; 
int adj[MAX][MAX]; 
int visited[MAX]; 
int queue[MAX]; 
int front = 0, rear = 0; 


void enqueue(int v) {
    queue[rear++] = v;
}


int dequeue() {
    return queue[front++];
}


int isEmpty() {
    return front == rear;
}


void BFS(int start) {
   
    visited[start] = 1;
    
    
    enqueue(start);
    
   
    while (!isEmpty()) {
        
        int u = dequeue();
        
       
        printf("%d ", u + 1); 
        
        
        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

int main() {
   
    FILE *file = fopen("baithb3.txt", "r");
    if (file == NULL) {
        printf("Khong mo duoc file.\n");
        return 1;
    }
    
    
    fscanf(file, "%d", &n);
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(file, "%d", &adj[i][j]);
        }
    }
    fclose(file);
    
    
    int x;
    printf("Nhap dinh can duyet x = ");
    scanf("%d", &x);
    x--; 
    
   
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    
    printf("Ket qua duyet BFS(%d) la: ", x + 1);
    BFS(x);
    printf("\n");

    return 0;
}

