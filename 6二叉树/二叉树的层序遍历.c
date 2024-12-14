#include "二叉树.c"

// 8.层次遍历
void LevelOrder(BiTree T) {
    BiTree Queue[100];  // 使用数组模拟队列
    int front = 0, rear = 0;
    Queue[rear++] = T;  // 根节点入队
    printf("层序遍历:");
    if (T) {
        while (front != rear) {  // 队列不为空
            BiTNode* temp = Queue[front++];  // 出队
            printf("%d ", temp->data);
            if (temp->lchild)  // 左孩子入队
                Queue[rear++] = temp->lchild;
            if (temp->rchild)  // 右孩子入队
                Queue[rear++] = temp->rchild;
        }
    }
}


int main() {
    BiTree T = NULL;
    int a[] = { 20,15,10,18,25 };
    for (int i = 0; i < 5; i++) {
        InsertNode(&T, a[i]);
    }
    LevelOrder(T);
    return 0;
}
