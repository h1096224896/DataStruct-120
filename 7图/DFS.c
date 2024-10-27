#include "图.c"

// DFS(非递归, 图采用邻接表存储)
void DFS(GraphAdjList* G, int i) {
    int j;
    Stack S;
    InitStack(&S);
    printf("%c ", G->adjList[i].data);
    visited[i] = true;
    Push(&S, i);
    while (!StackEmpty(S)) {
        Pop(&S, &i);
        for (j = FirstAdjVex(G, i); j >= 0; j = NextAdjVex(G, i, j)) {
            if (!visited[j]) {
                printf("%c ", G->adjList[j].data);
                visited[j] = true;
                Push(&S, j);
            }
        }
    }
}