#include <stdio.h>
#include <stdlib.h>

#define SIZE 40
 
struct queue {
  int items[SIZE];
  int front;
  int rear;
};
 
struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
int isEmpty(struct queue* q);
 
struct node {
  int vertex;
  struct node* next;
};
 
struct node* createNode(int);
 
struct Graph {
  int numVertices;
  struct node** adjLists;
  int* visited;
};
 
// BFS algorithm
void bfs(struct Graph* graph, int startVertex) {
  struct queue* q = createQueue();
 
  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);
 
  while (!isEmpty(q)) {
    int currentVertex = dequeue(q);
    printf("Visited %d\n", currentVertex);
 
    struct node* temp = graph->adjLists[currentVertex];
 
    while (temp) {
      int adjVertex = temp->vertex;
 
      if (graph->visited[adjVertex] == 0) {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}
 
// Creating a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}
 
// Creating a graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
 
  graph->adjLists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));
 
  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
 
  return graph;
}
 
// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;
 
  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}
 
// Create a queue
struct queue* createQueue() {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}
 
// Check if the queue is empty
int isEmpty(struct queue* q) {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}
 
// Adding elements into queue
void enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!\n");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}
 
// Removing elements from queue
int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("\nQueue is empty\n");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      q->front = q->rear = -1;
    }
  }
  return item;
}

// DFS algo
void DFS(struct Graph* graph, int vertex) {
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;
 
  graph->visited[vertex] = 1;
  printf("Visited %d \n", vertex);
 
  while (temp != NULL) {
    int connectedVertex = temp->vertex;
    if (!graph->visited[connectedVertex]) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}
// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n,e;
    printf("Enter the total no. of vertices :- \n");
    scanf("%d",&n);
    struct Graph* graph = createGraph(n);
    printf("Enter the total no. of edges :- \n");
    scanf("%d",&e);
    int x,y;
    for (int i = 1;i<=e;i++)
    {
        printf("Enter the edges(u,v) :- \n");
        scanf("%d%d",&x,&y);
        addEdge(graph,x,y);
    }
    // printing the graph
    printGraph(graph);
    printf("Menu :\n Press 1 for DFS. \n Press 2 for BFS. \n Press 3 to EXIT")
    int ch;
    printf("Enter your choice :\n");
    scanf("%d",&ch);
    int f=1;
    while(f)
    {
        switch (ch)
        {
            case 1:
            {
                printf("Enter The Starting Vertex\n");
                int starter;
                scanf("%d",&starter);
                DFS(graph, starter);
                for (i = 0; i <n; i++)
                {
                    graph.visited[i] = 0;
                }
                break;
            }
            case 2:
            {
                printf("Enter The Starting Vertex\n");
                int starter;
                scanf("%d",&starter);
                BFS(graph, starter);  
                for (i = 0; i <n; i++)
                {
                    graph.visited[i] = 0;
                }
                break;
            }
            case 3:
            {
                f=0;
                break;
            }
            default:
            {
                printf("Invalid Choice !!\n");
                break;
            }
        }
    }
    
   
    
    return 0;
}
