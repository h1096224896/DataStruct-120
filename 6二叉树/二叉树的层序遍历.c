#include "二叉树.c"

// 8.层次遍历
void LevelOrder(BiTree T) {
    BiTree Queue[100];
    int front = 0, rear = 0;
    BiTree p;
    printf("层序遍历:");
    if (T) {
        Queue[rear++] = T;
        while (front != rear) {
            p = Queue[front++];
            printf("%c ", p->data);
            if (p->lchild) {
                Queue[rear++] = p->lchild;
            }
            if (p->rchild) {
                Queue[rear++] = p->rchild;
            }
        }
    }
}

int main() {
    BiTree T;
    Init_Tree(&T);
    Create_Tree(&T);
    PreOrder(T);
    LevelOrder(T);
    return 0;
}
