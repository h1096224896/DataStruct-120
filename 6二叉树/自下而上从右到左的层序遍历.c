#include "二叉树.c"

// 自下而上从右到左的层序遍历
// 思路：
//     1.定义一个队列queue，一个指针p指向根结点
//     2.如果p不为空，根结点入队列
//     3.当队列不为空时，执行以下操作：
//         a.队头元素出队列，访问该结点
//         b.如果该结点的左孩子不为空，左孩子入队列
//         c.如果该结点的右孩子不为空，右孩子入队列
void LevelOrderReverse(BiTree T) {
    BiTree queue[100];  // 队列
    int front = 0, rear = 0;  // 队头和队尾
    BiTree p = T;
    if (p) {
        rear = (rear + 1) % 100;
        queue[rear] = p;
    }
    while (front != rear) {
        front = (front + 1) % 100;
        p = queue[front];
        printf("%c ", p->data);
        if (p->lchild) {
            rear = (rear + 1) % 100;
            queue[rear] = p->lchild;
        }
        if (p->rchild) {
            rear = (rear + 1) % 100;
            queue[rear] = p->rchild;
        }
    }
}